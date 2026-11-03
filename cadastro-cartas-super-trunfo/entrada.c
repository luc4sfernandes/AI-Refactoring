#include "entrada.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 64
#define MSG_LINHA_INVALIDA \
    "Entrada invalida: linha muito longa ou com caractere nulo.\n"

/* Lê uma linha inteira, descartando o excesso.
   Retorna 1 para linha válida, 0 para fim de entrada e -1 para linha
   inválida (NUL ou maior que o buffer). */
static int ler_linha(char *buffer, size_t tamanho) {
    size_t usados = 0;
    int caractere;
    int leu_algo = 0;
    int invalida = 0;

    if (tamanho == 0) {
        return -1;
    }

    while ((caractere = fgetc(stdin)) != EOF) {
        leu_algo = 1;

        if (caractere == '\n') {
            break;
        }

        /* NUL não é um caractere digitável válido e quebra funções de
           string; por isso a linha inteira é rejeitada. */
        if (caractere == '\0') {
            invalida = 1;
            continue;
        }

        if (usados + 1 < tamanho) {
            buffer[usados++] = (char)caractere;
        } else {
            invalida = 1;
        }
    }

    if (!leu_algo || ferror(stdin)) {
        return 0;
    }

    buffer[usados] = '\0';

    /* Remove o \r de arquivos com terminação CRLF. */
    if (usados > 0 && buffer[usados - 1] == '\r') {
        buffer[--usados] = '\0';
    }

    return invalida ? -1 : 1;
}

static int solicitar_linha(const char *mensagem, char *buffer, size_t tamanho) {
    printf("%s", mensagem);
    fflush(stdout);
    return ler_linha(buffer, tamanho);
}

/* Insiste até receber uma linha válida. Retorna 0 apenas em fim de entrada. */
static int obter_linha(const char *mensagem, char *buffer, size_t tamanho,
                       const char *mensagem_erro) {
    for (;;) {
        int status = solicitar_linha(mensagem, buffer, tamanho);

        if (status == 0) {
            return 0;
        }
        if (status > 0) {
            return 1;
        }

        printf("%s", mensagem_erro);
    }
}

static const char *ignorar_espacos(const char *texto) {
    while (isspace((unsigned char)*texto)) {
        texto++;
    }
    return texto;
}

static int converter_ulong(const char *texto, unsigned long int *valor) {
    const char *inicio = ignorar_espacos(texto);
    char *fim;
    unsigned long int convertido;

    if (*inicio == '-') {
        return 0;
    }

    errno = 0;
    convertido = strtoul(inicio, &fim, 10);
    if (errno == ERANGE || fim == inicio) {
        return 0;
    }

    while (isspace((unsigned char)*fim)) {
        fim++;
    }
    if (*fim != '\0') {
        return 0;
    }

    *valor = convertido;
    return 1;
}

static int converter_double(const char *texto, double *valor) {
    const char *inicio = ignorar_espacos(texto);
    const char *numero = inicio;
    char *fim;
    double convertido;

    if (*inicio == '-') {
        return 0;
    }

    if (*numero == '+') {
        numero++;
    }

    /* Aceita apenas decimal; evita formatos hexadecimais como 0x1p3. */
    if (numero[0] == '0' && (numero[1] == 'x' || numero[1] == 'X')) {
        return 0;
    }

    errno = 0;
    convertido = strtod(inicio, &fim);
    if (errno == ERANGE || fim == inicio || !isfinite(convertido)) {
        return 0;
    }

    while (isspace((unsigned char)*fim)) {
        fim++;
    }
    if (*fim != '\0') {
        return 0;
    }

    *valor = convertido;
    return 1;
}

static int converter_int(const char *texto, int *valor) {
    const char *inicio = ignorar_espacos(texto);
    char *fim;
    long convertido;

    if (*inicio == '-') {
        return 0;
    }

    errno = 0;
    convertido = strtol(inicio, &fim, 10);
    if (errno == ERANGE || fim == inicio || convertido > INT_MAX) {
        return 0;
    }

    while (isspace((unsigned char)*fim)) {
        fim++;
    }
    if (*fim != '\0') {
        return 0;
    }

    *valor = (int)convertido;
    return 1;
}

static int nome_valido(const char *nome) {
    const unsigned char *caractere = (const unsigned char *)nome;
    int tem_conteudo = 0;

    while (*caractere != '\0') {
        /* Bloqueia ESC, TAB, DEL e outros caracteres de controle que
           poderiam injetar comandos no terminal. */
        if (iscntrl(*caractere)) {
            return 0;
        }

        if (!isspace(*caractere)) {
            tem_conteudo = 1;
        }

        caractere++;
    }

    return tem_conteudo;
}

static int ler_estado(char *estado) {
    char linha[TAM_LINHA];

    for (;;) {
        if (!obter_linha("\nDigite o estado (uma letra de A a H): ",
                         linha, sizeof linha, MSG_LINHA_INVALIDA)) {
            return 0;
        }

        if (linha[0] != '\0' && linha[1] == '\0') {
            char letra = (char)toupper((unsigned char)linha[0]);
            if (letra >= 'A' && letra <= 'H') {
                *estado = letra;
                return 1;
            }
        }

        printf("Estado invalido. Informe uma unica letra de A a H.\n");
    }
}

static int ler_codigo(char estado, char *codigo) {
    char linha[TAM_LINHA];

    for (;;) {
        if (!obter_linha("Digite o codigo da carta (ex: A01): ",
                         linha, sizeof linha, MSG_LINHA_INVALIDA)) {
            return 0;
        }

        if (strlen(linha) == 3) {
            char letra = (char)toupper((unsigned char)linha[0]);
            int cidade = (linha[1] - '0') * 10 + (linha[2] - '0');

            if (letra == estado && isdigit((unsigned char)linha[1]) &&
                isdigit((unsigned char)linha[2]) && cidade >= 1 && cidade <= 4) {
                codigo[0] = estado;
                codigo[1] = linha[1];
                codigo[2] = linha[2];
                codigo[3] = '\0';
                return 1;
            }
        }

        printf("Codigo invalido. Use a letra do estado (%c) seguida de 01 a 04.\n", estado);
    }
}

static int ler_nome(char *nome) {
    for (;;) {
        if (!obter_linha("Digite o nome da cidade: ", nome, TAM_NOME,
                         "Nome invalido: use no maximo 49 caracteres.\n")) {
            return 0;
        }

        if (nome_valido(nome)) {
            return 1;
        }

        printf("Nome invalido. Informe ao menos um caractere visivel e evite caracteres de controle.\n");
    }
}

static int ler_populacao(unsigned long int *populacao) {
    char linha[TAM_LINHA];
    unsigned long int valor;

    for (;;) {
        if (!obter_linha("Digite a populacao: ", linha, sizeof linha,
                         MSG_LINHA_INVALIDA)) {
            return 0;
        }

        if (converter_ulong(linha, &valor) && valor > 0) {
            *populacao = valor;
            return 1;
        }

        printf("Valor invalido. Digite um inteiro maior que zero.\n");
    }
}

static int ler_area(double *area) {
    char linha[TAM_LINHA];
    double valor;

    for (;;) {
        if (!obter_linha("Digite a area (km2): ", linha, sizeof linha,
                         MSG_LINHA_INVALIDA)) {
            return 0;
        }

        if (converter_double(linha, &valor) && valor > 0.0) {
            *area = valor;
            return 1;
        }

        printf("Valor invalido. A area deve ser um numero finito maior que zero.\n");
    }
}

static int ler_pib(double *pib) {
    char linha[TAM_LINHA];
    double valor;

    for (;;) {
        if (!obter_linha("Digite o PIB (em bilhoes de reais): ",
                         linha, sizeof linha, MSG_LINHA_INVALIDA)) {
            return 0;
        }

        if (converter_double(linha, &valor) && valor >= 0.0) {
            *pib = valor;
            return 1;
        }

        printf("Valor invalido. O PIB deve ser um numero finito nao negativo.\n");
    }
}

static int ler_pontos_turisticos(int *pontos) {
    char linha[TAM_LINHA];
    int valor;

    for (;;) {
        if (!obter_linha("Digite o numero de pontos turisticos: ",
                         linha, sizeof linha, MSG_LINHA_INVALIDA)) {
            return 0;
        }

        if (converter_int(linha, &valor) && valor >= 0) {
            *pontos = valor;
            return 1;
        }

        printf("Valor invalido. Digite um inteiro maior ou igual a zero.\n");
    }
}

int entrada_ler_carta(int numero, Carta *carta) {
    for (;;) {
        printf("\n*** Digite os dados da Carta %d ***\n", numero);

        if (!ler_estado(&carta->estado) ||
            !ler_codigo(carta->estado, carta->codigo) ||
            !ler_nome(carta->nome) ||
            !ler_populacao(&carta->populacao) ||
            !ler_area(&carta->area) ||
            !ler_pib(&carta->pib) ||
            !ler_pontos_turisticos(&carta->pontos_turisticos)) {
            return 0;
        }

        if (carta_calcular_atributos(carta)) {
            return 1;
        }

        printf("Os dados informados geram resultados fora do limite numerico.\n");
        printf("Informe valores menores para a area e o PIB e tente novamente.\n");
    }
}
