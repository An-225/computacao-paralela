/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 3.Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9).
  Este número deve ser sempre ímpar.
  1 2 3 4 5 6 7 8 9
    2 3 4 5 6 7 8
      3 4 5 6 7
        4 5 6
          5   

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    printf("Digite um numero impar: ");
    scanf("%d", &N);

    if (N % 2 == 0)
    {
        printf("%d e par!!", N);
    }
    else
    {
        int *L = malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
        {
            L[i] = i + 1;
        }

        int I = 0, F = N - 1;

        while (F >= I)
        {
            for (int i = 0; i < N; i++)
            {
                if (i > F || i < I)
                {
                    int temp = (L[i] / 10)+2;
                    for (int z = 0; z <= temp; z++)
                    {
                        printf(" ");
                    }
                }
                else
                {
                    printf(" %d ", L[i]);
                }
            }
            printf("\n");

            I++;
            F--;
        }
    }

    return 0;
}