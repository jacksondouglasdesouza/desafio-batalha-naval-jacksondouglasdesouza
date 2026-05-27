#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* VERSÃO 01 - NÍVEL BÁSICO
int main()
{

   setlocale(LC_ALL, "Portuguese");

   // 1. Cria o tabuleiro 10x10 preenchido com �gua (0)
   int tabuleiro[10][10] = {0};

   // 2. Cria o navio com 3 partes
   int navio[3] = {3, 3, 3};

   // Posi��es escolhidas para os navios
   int linha_horiz = 2, col_horiz = 1;
   int linha_vert = 5, col_vert = 7;

   // 3. Valida��o bem simples: seleciona o navio e checa se o tamanho (3) cabe dentro do limite (10)
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
   */

/* VERSÃO 02 - NÍVEL INTERMEDIÁRIO*/

int main()
{
   // 1. Cria o tabuleiro 10x10 preenchido com água (0)
   int tabuleiro[10][10] = {0};

   // 2. Cria o navio com 3 partes (valor 3)
   int navio[3] = {3, 3, 3};

   // Coordenadas dos navios (definidas diretamente no código)
   int linha_horiz = 2, col_horiz = 1; // Navio Horizontal
   int linha_vert = 5, col_vert = 7;   // Navio Vertical

   // Novas coordenadas para as diagonais (posições estratégicas para não haver sobreposição)
   int linha_diag1 = 1, col_diag1 = 5; // Diagonal que desce para a direita (\)
   int linha_diag2 = 6, col_diag2 = 3; // Diagonal que desce para a esquerda (/)

   // 3. Validação de limites: garante que todos os 4 navios de tamanho 3 caibam no tabuleiro
   if ((col_horiz + 3 <= 10) &&
       (linha_vert + 3 <= 10) &&
       (linha_diag1 + 3 <= 10 && col_diag1 + 3 <= 10) &&
       (linha_diag2 + 3 <= 10 && col_diag2 - 2 >= 0))
   {

      // Posiciona o Navio Horizontal (linha fixa, coluna avança)
      for (int i = 0; i < 3; i++)
      {
         tabuleiro[linha_horiz][col_horiz + i] = navio[i];
      }

      // Posiciona o Navio Vertical (linha avança, coluna fixa)
      for (int i = 0; i < 3; i++)
      {
         tabuleiro[linha_vert + i][col_vert] = navio[i];
      }

      // Posiciona a Primeira Diagonal (linha aumenta e coluna aumenta: \)
      for (int i = 0; i < 3; i++)
      {
         tabuleiro[linha_diag1 + i][col_diag1 + i] = navio[i];
      }

      // Posiciona a Segunda Diagonal (linha aumenta e coluna diminui: /)
      for (int i = 0; i < 3; i++)
      {
         tabuleiro[linha_diag2 + i][col_diag2 - i] = navio[i];
      }
   }

   // 4. Exibindo o Tabuleiro com a padronização clássica
   printf("TABULEIRO BATALHA NAVAL\n");
   printf("   A B C D E F G H I J\n"); // Cabeçalho com letras

   for (int i = 0; i < 10; i++)
   {
      // Formatação dos números laterais (ajuste de espaçamento para o 10)
      if (i < 9)
      {
         printf("%d  ", i + 1);
      }
      else
      {
         printf("%d ", i + 1);
      }

      // Imprime a linha do tabuleiro
      for (int j = 0; j < 10; j++)
      {
         printf("%d ", tabuleiro[i][j]);
      }
      printf("\n"); // Quebra a linha lateral
   }

   return 0;
}
