#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
   int x;
   int y;
} PONTO;

typedef struct pilha {
   PONTO* coordenada;
   struct pilha* abaixo;
} PILHA;

PONTO* criar_ponto(int x, int y);
PILHA* criar_pilha(PONTO * coordenada);
void adicionar_pilha(PILHA** topo, PONTO* coordenada);
PONTO* desempilhar_pilha(PILHA** topo);
void imprimirCaminho(PILHA * topo);

#endif
