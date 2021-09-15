/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz.
  O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.

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

void printMatriz(int **M, int L, int C)
{
    for (int l = 0; l < L; l++)
    {
        for (int c = 0; c < C; c++)
        {
            printf("%d", M[l][c]);
        }
        printf("\n");
    }
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

void somaLinha(int **M, int L1, int L2, int Ld, int C)
{
    int *tempL = malloc(sizeof(int) * C);

    for (int c = 0; c < C; c++)
    {
        tempL[c] = M[L1][c] + M[L2][c];
    }

    for (int c = 0; c < C; c++)
    {
        M[Ld][c] = tempL[c];
    }
}

void multiLinha(int **M, int L1, int L2, int Ld, int C)
{
    int *tempL = malloc(sizeof(int) * C);

    for (int c = 0; c < C; c++)
    {
        tempL[c] = M[L1][c] * M[L2][c];
    }

    for (int c = 0; c < C; c++)
    {
        M[Ld][c] = tempL[c];
    }
}

int main()
{

    int Linhas, Colunas, OP;

    printf("Digite o numero de linhas: ");
    scanf("%d", &Linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &Colunas);

    int **Matriz_1 = criaMatriz(Linhas, Colunas);
    inputMatriz(Matriz_1,Linhas,Colunas);

    printf("------------\n");
    printf("1-soma\n2-multi\n");
    scanf("%d",&OP);
    printf("------------\n");

    if (OP == 1)
    {
        somaLinha(Matriz_1,0,1,1,Colunas);
    }
    else{
        multiLinha(Matriz_1,0,1,1,Colunas);
    }
    
    printMatriz(Matriz_1,Linhas,Colunas);
    return 0;
}