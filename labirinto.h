#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "pilha.h"

typedef struct labirinto {
   int linhas;
   int colunas;
   int** labirinto;

} LABIRINTO;

LABIRINTO* criar_labirinto(int linhas, int colunas);
void liberar_labirinto(LABIRINTO* labirinto);
bool valido_labirinto(int x, int y, LABIRINTO * labirinto);
void resolve_labirinto(LABIRINTO* labirinto);

#endif