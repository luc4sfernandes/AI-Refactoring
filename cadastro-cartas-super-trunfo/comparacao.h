#ifndef COMPARACAO_H
#define COMPARACAO_H

#include "carta.h"

/* Retorna 1 se a Carta 1 venceu, -1 se a Carta 2 venceu e 0 em caso de empate. */
int comparacao_valores(long double valor1, long double valor2, int menor_vence);

/* Compara um atributo específico das duas cartas. */
int comparacao_atributo(const Carta *carta1, const Carta *carta2, Atributo atributo);

/* Exibe os valores comparados e o resultado do atributo. */
void comparacao_exibir_atributo(const Carta *carta1, const Carta *carta2,
                                Atributo atributo, int resultado);

/* Exibe o resultado final a partir da contagem de vitórias. */
void comparacao_exibir_resultado_final(int vitorias_carta1, int vitorias_carta2);

/* Compara e exibe o Super Poder das duas cartas. */
void comparacao_exibir_super_poder(const Carta *carta1, const Carta *carta2);

#endif
