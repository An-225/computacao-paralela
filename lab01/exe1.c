/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 1.Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros.
  Ao final da leitura o programa deverá imprimir o número da linha que contém
  o menor dentre todos os números lidos.

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

int menorlMatriz(int **M, int L, int C)
{
    int min = M[0][0];
    int minL = 0;

    for (int l = 0; l < L; l++)
    {
        for (int c = 0; c < C; c++)
        {
            if (min > M[l][c])
            {
                min = M[l][c];
                minL = l;

            }
        }
    }

    return minL;
}

int main()
{
    int N;
    printf("Dismensao da matriz: ");
    scanf("%d", &N);
    int **Matriz = criaMatriz(N, N);
    inputMatriz(Matriz, N, N);
    int Menor = menorlMatriz(Matriz, N, N);

    printf("Linha com menor numero: %d", Menor);

    return 0;
}