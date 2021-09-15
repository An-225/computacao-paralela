/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 8. Crie uma função capaz de criar a transposta de uma matriz.
  #Obs.: mesmo código do exe6

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

int **transpostaMatriz(int **M, int L, int C)
{
  int **tempM = malloc(sizeof(int) * C);
  for (int c = 0; c < C; c++)
  {
    tempM[c] = malloc(sizeof(int) * L);
  }

  for (int l = 0; l < L; l++)
  {
    for (int c = 0; c < C; c++)
    {
      tempM[c][l] = M[l][c];
    }
  }

  return tempM;
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
  int **transposta = transpostaMatriz(Matriz, Linhas, Colunas);
  printMatriz(transposta, Colunas, Linhas);

  return 0;
}