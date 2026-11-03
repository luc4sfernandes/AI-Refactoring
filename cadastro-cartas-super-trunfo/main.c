#include <stdio.h>

#include "carta.h"
#include "comparacao.h"
#include "entrada.h"

int main(void) {
    Carta carta1;
    Carta carta2;
    int vitorias_carta1 = 0;
    int vitorias_carta2 = 0;
    Atributo atributo;

    printf("\n*** DESAFIO SUPER TRUNFO ***\n");
    printf("Cadastro de duas cartas do jogo Super Trunfo - Paises\n");

    if (!entrada_ler_carta(1, &carta1) || !entrada_ler_carta(2, &carta2)) {
        fprintf(stderr, "\nEntrada encerrada antes do fim do cadastro.\n");
        return 1;
    }

    carta_exibir(1, &carta1);
    carta_exibir(2, &carta2);

    printf("\n=== Comparacao de atributos ===\n");

    /* O nivel Mestre pede o resultado da comparacao para cada atributo. */
    for (atributo = ATRIBUTO_POPULACAO; atributo <= ATRIBUTO_PIB_PER_CAPITA; atributo++) {
        int resultado = comparacao_atributo(&carta1, &carta2, atributo);

        comparacao_exibir_atributo(&carta1, &carta2, atributo, resultado);
        vitorias_carta1 += (resultado == 1);
        vitorias_carta2 += (resultado == -1);
    }

    comparacao_exibir_resultado_final(vitorias_carta1, vitorias_carta2);
    comparacao_exibir_super_poder(&carta1, &carta2);

    /* Garante que erros de escrita (disco cheio, stdout fechado etc.)
       não sejam reportados como sucesso. */
    if (fflush(stdout) != 0 || ferror(stdout)) {
        fprintf(stderr, "\nErro ao escrever a saida.\n");
        return 1;
    }

    return 0;
}
