#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

PONTO* criar_ponto(int x, int y) {
   PONTO* coordenada = (PONTO*)malloc(sizeof(PONTO));

   coordenada->x = x;
   coordenada->y = y;

   return coordenada;
}

PILHA* criar_pilha(PONTO* coordenada) {
   PILHA* pilha = (PILHA*)malloc(sizeof(PILHA));

   if (!pilha) {
      printf("Não foi possível criar a pilha!\n");
      exit(1);
   }

   pilha->abaixo = NULL;
   pilha->coordenada = coordenada;

   return pilha;
}

void adicionar_pilha(PILHA** topo, PONTO* coordenada) {
   PILHA* novo_topo = criar_pilha(coordenada);
   novo_topo->abaixo = *topo;
   *topo = novo_topo;
}

PONTO* desempilhar_pilha(PILHA** topo) {
   if (*topo == NULL) {
      printf("A pilha está vazia!\n");
      exit(1);
   }

   PONTO* coordenada = (*topo)->coordenada;
   PILHA* temp = *topo;
   *topo = (*topo)->abaixo;
   free(temp);
   return coordenada;
}

void imprimirCaminho(PILHA* topo) {
   PILHA* atual = topo;
   PILHA* anterior = NULL;
   PILHA* prox = NULL;

   // inverte a ordem dos elementos da pilha
   while (atual) {
      prox = atual->abaixo;
      atual->abaixo = anterior;
      anterior = atual;
      atual = prox;
   }

   atual = anterior;

   while (atual) {
      printf("(%d, %d)\n", atual->coordenada->x, atual->coordenada->y);
      atual = atual->abaixo;
   }
}