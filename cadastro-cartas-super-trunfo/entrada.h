#ifndef ENTRADA_H
#define ENTRADA_H

#include "carta.h"

/* Lê todos os dados de uma carta, validando cada campo.
   Retorna 1 em caso de sucesso e 0 se a entrada for encerrada. */
int entrada_ler_carta(int numero, Carta *carta);

#endif
