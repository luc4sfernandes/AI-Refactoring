#ifndef CARTA_H
#define CARTA_H

#define TAM_CODIGO 4
#define TAM_NOME 50

/* Estado de cada carta. Os atributos calculados ficam no próprio registro
   para evitar repetir fórmulas e variáveis soltas pelo programa. */
typedef struct {
    char estado;
    char codigo[TAM_CODIGO];
    char nome[TAM_NOME];
    unsigned long int populacao;
    double area;
    double pib; /* em bilhões de reais */
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
    long double super_poder;
} Carta;

typedef enum {
    ATRIBUTO_POPULACAO = 1,
    ATRIBUTO_AREA,
    ATRIBUTO_PIB,
    ATRIBUTO_PONTOS_TURISTICOS,
    ATRIBUTO_DENSIDADE,
    ATRIBUTO_PIB_PER_CAPITA
} Atributo;

/* Calcula densidade, PIB per capita e Super Poder da carta.
   Retorna 1 em caso de sucesso e 0 se o resultado não for finito
   (por exemplo, valores que geram divisão por zero ou overflow). */
int carta_calcular_atributos(Carta *carta);

/* Exibe todos os dados da carta. */
void carta_exibir(int numero, const Carta *carta);

/* Funções auxiliares para tratar os atributos de forma genérica. */
const char *atributo_nome(Atributo atributo);
double atributo_valor(const Carta *carta, Atributo atributo);
void atributo_exibir_valor(Atributo atributo, const Carta *carta);

#endif
