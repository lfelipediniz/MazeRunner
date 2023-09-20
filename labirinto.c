#include "labirinto.h"

LABIRINTO* criar_labirinto(int linhas, int colunas) {
   int i, j;
   LABIRINTO* labirinto = (LABIRINTO*)malloc(sizeof(LABIRINTO));
   labirinto->labirinto = (int**)malloc(linhas * sizeof(int*));

   for (i = 0; i < linhas; i++) {
      labirinto->labirinto[i] = (int*)malloc(colunas * sizeof(int));
   }

   for (i = 0; i < linhas; i++) {
      for (j = 0; j < colunas; j++) {
         int input;
         if (scanf("%d", &input) != 1) {
            printf("Erro na leitura do caminho do labirinto.\n");
            exit(1);
         }
         labirinto->labirinto[i][j] = input;
      }
   }

   labirinto->linhas = linhas;
   labirinto->colunas = colunas;

   return labirinto;
}

void liberar_labirinto(LABIRINTO* labirinto) {
   int linhas = labirinto->linhas;
   int i;

   for (i = 0; i < linhas; i++) {
      free(labirinto->labirinto[i]);
   }
   free(labirinto->labirinto);
   free(labirinto);
}

bool valido_labirinto(int x, int y, LABIRINTO* labirinto) {
   if (x >= 0 && x < labirinto->linhas && y >= 0 && y < labirinto->colunas &&
       labirinto->labirinto[x][y] != 0)
      return true;
   else
      return false;
}

void resolve_labirinto(LABIRINTO* labirinto) {
  // Definindo as direções: baixo, esquerda, cima, direita
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, -1, 0, 1};
  
  PONTO* start = criar_ponto(0, 0);
  PONTO* final = NULL;
  
  int linhas = labirinto->linhas;
  int colunas = labirinto->colunas;
  
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (labirinto->labirinto[i][j] == 2) {
        final = criar_ponto(i, j);
        break;
      }
    }
  }
  
  PILHA* pilha = criar_pilha(start);
  int** visitado = (int**)malloc(linhas * sizeof(int*));
  
  for (int i = 0; i < linhas; i++) {
    visitado[i] = (int*)calloc(colunas, sizeof(int));
  }
  
  PILHA* trajetoria = NULL;  // pilha que armazena a trajetória
  
  while (pilha) {
    PONTO* atual = pilha->coordenada;
    int x = atual->x;
    int y = atual->y;
    
    // verificamos se a célula já foi visitada antes de empilhá-la novamente
    if (visitado[x][y]) {
      desempilhar_pilha(&pilha); // Remove a célula repetida
      continue;
    }
    
    // marcamos a célula como visitada antes de empilhá-la
    visitado[x][y] = 1;
    
    adicionar_pilha(&trajetoria, atual);  // adicionando o ponto atual na trajetória
    
    if (x == final->x && y == final->y) {
      break;  // quando ele encontrar a saída, sai do laço
    }
    
    int direcao = 0;
    
    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      
      if (valido_labirinto(new_x, new_y, labirinto) && !visitado[new_x][new_y] &&
          labirinto->labirinto[new_x][new_y] != 0) {
        PONTO* ponto = criar_ponto(new_x, new_y);
        adicionar_pilha(&pilha, ponto);
        direcao = 1;
      }
    }
    
    if (direcao == 0) {
      // não há direções não visitadas, então desempilhamos
      desempilhar_pilha(&pilha);
    }
  }
  
  // imprime a trajetória
  imprimirCaminho(trajetoria);
  
  // libera a pilha de trajetória
  while (trajetoria) {
    PONTO* ponto = desempilhar_pilha(&trajetoria);
    free(ponto);
  }
  
  // verifica se a saída não foi encontrada
  if (pilha == NULL) {
    printf("Saída não encontrada.\n");
  }
  
  free(visitado);
}
