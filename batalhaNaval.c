#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* VERSÃO 01 - NÍVEL BÁSICO
int main()
{

   setlocale(LC_ALL, "Portuguese");

   // 1. Cria o tabuleiro 10x10 preenchido com ï¿½gua (0)
   int tabuleiro[10][10] = {0};

   // 2. Cria o navio com 3 partes
   int navio[3] = {3, 3, 3};

   // Posiï¿½ï¿½es escolhidas para os navios
   int linha_horiz = 2, col_horiz = 1;
   int linha_vert = 5, col_vert = 7;

   // 3. Validaï¿½ï¿½o bem simples: seleciona o navio e checa se o tamanho (3) cabe dentro do limite (10)
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

/* VERSÃO 02 - NÍVEL INTERMEDIÁRIO

#include <stdio.h>

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
} */

// VERSÃO 03 - NÍVEL AVANÇADO

#include <stdio.h>
#include <stdlib.h>

int main()
{
   // 1. TABULEIRO E NAVIOS BASE
   int tabuleiro[10][10] = {0};

   // Colocando alguns navios normais (valor 3) só para termos alvos no mapa
   for (int i = 0; i < 3; i++)
   {
      tabuleiro[0][i] = 3;     // Navio no canto superior esquerdo
      tabuleiro[i + 7][9] = 3; // Navio no canto inferior direito
   }

   // 2. MATRIZES DE HABILIDADES (Tamanho 5x5 preenchidas com 0)
   int cone[5][5] = {0};
   int cruz[5][5] = {0};
   int octaedro[5][5] = {0};

   // 3. CONSTRUÇÃO DINÂMICA DAS HABILIDADES (Loops e Condicionais)
   // O centro de uma matriz 5x5 é a posição [2][2]
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {

         // CONE: Aponta para baixo. Ocupa as 3 primeiras linhas (i <= 2).
         // A largura aumenta conforme a linha desce.
         if (i <= 2 && j >= (2 - i) && j <= (2 + i))
         {
            cone[i][j] = 1;
         }

         // CRUZ: Marca apenas a linha central (2) e a coluna central (2)
         if (i == 2 || j == 2)
         {
            cruz[i][j] = 1;
         }

         // OCTAEDRO (Losango): A soma da distância da linha e da coluna até o centro deve ser <= 2
         // abs() transforma números negativos em positivos, garantindo a distância exata.
         if (abs(i - 2) + abs(j - 2) <= 2)
         {
            octaedro[i][j] = 1;
         }
      }
   }

   // 4. SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO

   // Coordenadas centrais (origem) onde cada habilidade será lançada no tabuleiro 10x10
   int centro_cone_linha = 2, centro_cone_col = 2; // Lançado em C3
   int centro_cruz_linha = 7, centro_cruz_col = 2; // Lançado em C8
   int centro_octa_linha = 5, centro_octa_col = 7; // Lançado em H6

   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {

         // Variáveis para calcular a posição real no tabuleiro grande (-2 ajusta o centro da 5x5)
         int linha_real, col_real;

         // Aplica o Cone (se tiver 1 na matriz da habilidade)
         if (cone[i][j] == 1)
         {
            linha_real = centro_cone_linha - 2 + i;
            col_real = centro_cone_col - 2 + j;
            // Validação de limite do tabuleiro
            if (linha_real >= 0 && linha_real < 10 && col_real >= 0 && col_real < 10)
            {
               tabuleiro[linha_real][col_real] = 5;
            }
         }

         // Aplica a Cruz
         if (cruz[i][j] == 1)
         {
            linha_real = centro_cruz_linha - 2 + i;
            col_real = centro_cruz_col - 2 + j;
            if (linha_real >= 0 && linha_real < 10 && col_real >= 0 && col_real < 10)
            {
               tabuleiro[linha_real][col_real] = 5;
            }
         }

         // Aplica o Octaedro
         if (octaedro[i][j] == 1)
         {
            linha_real = centro_octa_linha - 2 + i;
            col_real = centro_octa_col - 2 + j;
            if (linha_real >= 0 && linha_real < 10 && col_real >= 0 && col_real < 10)
            {
               tabuleiro[linha_real][col_real] = 5;
            }
         }
      }
   }

   // 5. EXIBINDO O TABULEIRO
   printf("TABULEIRO BATALHA NAVAL - HABILIDADES ESPECIAIS\n");
   printf("   A B C D E F G H I J\n");

   for (int i = 0; i < 10; i++)
   {
      // Formatação dos números laterais
      if (i < 9)
      {
         printf("%d  ", i + 1);
      }
      else
      {
         printf("%d ", i + 1);
      }

      // Imprime os elementos do tabuleiro
      for (int j = 0; j < 10; j++)
      {
         printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
   }

   return 0;
}
