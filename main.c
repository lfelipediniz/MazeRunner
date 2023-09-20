#include <stdio.h>
#include "labirinto.h"

int main() {
   int linhas, colunas;

   scanf("%d %d", &linhas, &colunas);

   LABIRINTO* labirinto = criar_labirinto(linhas, colunas);
   resolve_labirinto(labirinto);
   liberar_labirinto(labirinto);

   return 0;
}
