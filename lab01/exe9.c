/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 9. Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.

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

void moduloMatriz(int **M, int L, int C)
{
  for (int l = 0; l < L; l++)
  {
    for (int c = 0; c < C; c++)
    {
      M[l][c] = abs(M[l][c]);
    }
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
  printMatriz(Matriz, Linhas, Colunas);
  printf("-------------------------\n");
  moduloMatriz(Matriz, Linhas, Colunas);
  printMatriz(Matriz, Linhas, Colunas);

  return 0;
}