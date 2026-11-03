#include "comparacao.h"

#include <stdio.h>

int comparacao_valores(long double valor1, long double valor2, int menor_vence) {
    if (valor1 == valor2) {
        return 0;
    }

    if (menor_vence) {
        return valor1 < valor2 ? 1 : -1;
    }

    return valor1 > valor2 ? 1 : -1;
}

int comparacao_atributo(const Carta *carta1, const Carta *carta2, Atributo atributo) {
    /* A população é comparada como unsigned long int para não perder
       precisão na conversão para double em valores próximos de ULONG_MAX. */
    if (atributo == ATRIBUTO_POPULACAO) {
        if (carta1->populacao == carta2->populacao) {
            return 0;
        }

        return carta1->populacao > carta2->populacao ? 1 : -1;
    }

    return comparacao_valores(atributo_valor(carta1, atributo),
                              atributo_valor(carta2, atributo),
                              atributo == ATRIBUTO_DENSIDADE);
}

static void exibir_resultado(int resultado) {
    if (resultado == 1) {
        printf("Resultado: 1 (Carta 1 venceu)\n");
    } else if (resultado == -1) {
        printf("Resultado: 0 (Carta 2 venceu)\n");
    } else {
        printf("Resultado: empate\n");
    }
}

void comparacao_exibir_atributo(const Carta *carta1, const Carta *carta2,
                                Atributo atributo, int resultado) {
    printf("\n--- %s ---\n", atributo_nome(atributo));
    printf("Carta 1 (%s): ", carta1->nome);
    atributo_exibir_valor(atributo, carta1);
    printf(" | Carta 2 (%s): ", carta2->nome);
    atributo_exibir_valor(atributo, carta2);
    printf("\n");

    exibir_resultado(resultado);
}

void comparacao_exibir_resultado_final(int vitorias_carta1, int vitorias_carta2) {
    printf("\n=== Resultado final ===\n");

    if (vitorias_carta1 > vitorias_carta2) {
        printf("Carta 1 venceu por %d atributo(s) a %d.\n",
               vitorias_carta1, vitorias_carta2);
    } else if (vitorias_carta2 > vitorias_carta1) {
        printf("Carta 2 venceu por %d atributo(s) a %d.\n",
               vitorias_carta2, vitorias_carta1);
    } else {
        printf("Empate: cada carta venceu %d atributo(s).\n", vitorias_carta1);
    }
}

void comparacao_exibir_super_poder(const Carta *carta1, const Carta *carta2) {
    int resultado = comparacao_valores(carta1->super_poder, carta2->super_poder, 0);

    printf("\n--- Super Poder ---\n");
    printf("Carta 1 (%s): %.2Lf | Carta 2 (%s): %.2Lf\n",
           carta1->nome, carta1->super_poder,
           carta2->nome, carta2->super_poder);

    exibir_resultado(resultado);
}
