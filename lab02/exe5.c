/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 5. Crie um programa  capaz de multiplicar uma linha de uma matriz de inteiros por um dado número.
  Faça o mesmo para uma coluna. A matriz deve ser lida de teclado.

*/

#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int L, int C)
{
  int **M = malloc(sizeof(int *) * L);
  for (int l = 0; l < L; l++)
  {
    M[l] = malloc(sizeof(int) * C);
  }
  return M;
}

void inputMatriz(int **M, int L, int C)
{
  int temp;
  for (int l = 0; l < L; l++)
  {
    for (int c = 0; c < C; c++)
    {
      printf("Linha: %d Coluna: %d\n", l, c);
      printf("Numero: ");
      scanf("%d", &temp);
      M[l][c] = temp;
    }
  }
}

void printMatriz(int **M, int L, int C)
{
  for (int l = 0; l < L; l++)
  {
    for (int c = 0; c < C; c++)
    {
      printf("|%d|", M[l][c]);
    }
    printf("\n");
  }
}

void multiLinha(int **M, int L, int C, int N)
{
  for (int c = 0; c < C; c++)
  {
    M[L][c] = M[L][c] * N;
  }
}

void multiColuna(int **M, int L, int C, int N)
{
  for (int l = 0; l < L; l++)
  {
    M[l][C] = M[l][C] * N;
  }
}

int main()
{
  int Linhas, Colunas, OP;

  printf("Digite o numero de linhas: ");
  scanf("%d", &Linhas);
  printf("Digite o numero de colunas: ");
  scanf("%d", &Colunas);

  int **Matriz = criaMatriz(Linhas, Colunas);
  inputMatriz(Matriz, Linhas, Colunas);

  printf("------------\n");
  printf("1-linha\n2-coluna\n");
  scanf("%d", &OP);
  printf("------------\n");

  if (OP == 1)
  {
    int l, n;
    printf("Digite a linha: ");
    scanf("%d", &l);
    printf("Digite o inteiro: ");
    scanf("%d", &n);
    multiLinha(Matriz, l, Colunas, n);
  }
  else
  {
    int c, n;
    printf("Digite a coluna: ");
    scanf("%d", &c);
    printf("Digite o inteiro: ");
    scanf("%d", &n);
    multiColuna(Matriz, Linhas, c, n);
  }

  printMatriz(Matriz, Linhas, Colunas);

  return 0;
}