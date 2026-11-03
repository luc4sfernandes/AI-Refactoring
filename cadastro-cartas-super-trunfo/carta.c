#include "carta.h"

#include <math.h>
#include <stdio.h>

int carta_calcular_atributos(Carta *carta) {
    /* A densidade usa a população convertida para double, garantindo
       divisão real mesmo que os dois operandos fossem inteiros. */
    double densidade = (double)carta->populacao / carta->area;

    /* O PIB é informado em bilhões. Multiplicar por 1e9 converte para
       reais antes de dividir pela população. */
    double pib_per_capita = (carta->pib * 1e9) / (double)carta->populacao;

    long double super_poder;

    /* Rejeita resultados que não podem ser representados como número
       finito. Isso evita saídas como "inf" e comparações inválidas. */
    if (!isfinite(densidade) || densidade <= 0.0) {
        return 0;
    }
    if (!isfinite(pib_per_capita) || pib_per_capita < 0.0) {
        return 0;
    }

    /* A soma é feita em long double para preservar a população
       (unsigned long) mesmo em valores próximos de ULONG_MAX. */
    super_poder = (long double)carta->populacao + carta->area + carta->pib +
                  carta->pontos_turisticos + pib_per_capita +
                  (1.0L / (long double)densidade);

    if (!isfinite(super_poder)) {
        return 0;
    }

    carta->densidade = densidade;
    carta->pib_per_capita = pib_per_capita;
    carta->super_poder = super_poder;
    return 1;
}

void carta_exibir(int numero, const Carta *carta) {
    printf("\n=== Dados da Carta %d ===\n", numero);
    printf("Codigo: %s\n", carta->codigo);
    printf("Estado: %c\n", carta->estado);
    printf("Cidade: %s\n", carta->nome);
    printf("Populacao: %lu habitantes\n", carta->populacao);
    printf("Area: %.2f km2\n", carta->area);
    printf("PIB: R$ %.2f bilhoes de reais\n", carta->pib);
    printf("Pontos turisticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta->densidade);
    printf("PIB per Capita: R$ %.2f\n", carta->pib_per_capita);
    printf("Super Poder: %.2Lf\n", carta->super_poder);
}

const char *atributo_nome(Atributo atributo) {
    switch (atributo) {
        case ATRIBUTO_POPULACAO: return "Populacao";
        case ATRIBUTO_AREA: return "Area";
        case ATRIBUTO_PIB: return "PIB";
        case ATRIBUTO_PONTOS_TURISTICOS: return "Pontos turisticos";
        case ATRIBUTO_DENSIDADE: return "Densidade demografica";
        case ATRIBUTO_PIB_PER_CAPITA: return "PIB per Capita";
        default: return "Atributo desconhecido";
    }
}

double atributo_valor(const Carta *carta, Atributo atributo) {
    switch (atributo) {
        case ATRIBUTO_POPULACAO: return (double)carta->populacao;
        case ATRIBUTO_AREA: return carta->area;
        case ATRIBUTO_PIB: return carta->pib;
        case ATRIBUTO_PONTOS_TURISTICOS: return (double)carta->pontos_turisticos;
        case ATRIBUTO_DENSIDADE: return carta->densidade;
        case ATRIBUTO_PIB_PER_CAPITA: return carta->pib_per_capita;
        default: return 0.0;
    }
}

void atributo_exibir_valor(Atributo atributo, const Carta *carta) {
    switch (atributo) {
        case ATRIBUTO_POPULACAO:
            printf("%lu", carta->populacao);
            break;
        case ATRIBUTO_PONTOS_TURISTICOS:
            printf("%d", carta->pontos_turisticos);
            break;
        default:
            printf("%.2f", atributo_valor(carta, atributo));
            break;
    }
}
