#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

   setlocale(LC_ALL, "Portuguese");

   // 1. Cria o tabuleiro 10x10 preenchido com água (0)
   int tabuleiro[10][10] = {0};

   // 2. Cria o navio com 3 partes
   int navio[3] = {3, 3, 3};

   // Posições escolhidas para os navios
   int linha_horiz = 2, col_horiz = 1;
   int linha_vert = 5, col_vert = 7;

   // 3. Validação bem simples: seleciona o navio e checa se o tamanho (3) cabe dentro do limite (10)
   if (col_horiz + 3 <= 10 && linha_vert + 3 <= 10)
   {

      // Coloca o navio na Horizontal (a linha fica igual, a coluna muda)
      for (int i = 0; i < 3; i++)
      {
         tabuleiro[linha_horiz][col_horiz + i] = navio[i];
      }

      // Coloca o navio na Vertical (a linha muda, a coluna fica igual)
      for (int i = 0; i < 3; i++)
      {
         tabuleiro[linha_vert + i][col_vert] = navio[i];
      }
   }

   // 4. Imprime o mapa na tela
   printf("Tabuleiro Naval:\n\n");
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 10; j++)
      {
         printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
   }

   return 0;
}
