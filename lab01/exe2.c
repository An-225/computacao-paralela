/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 2.Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele.
  Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média,
  informar o conceito de acordo com a tabela:

    maior ou igual a 9 	A
    maior ou igual a 7.5 e menor que 9 	B
    maior ou igual a 6 e menor que 7.5 	C
    maior ou igual a 4 e menor que 6 	D
    menor que 4 	E

*/

#include <stdio.h>

int main()
{
    int N1, N2, N3, ME;

    printf("Digite a N1: ");
    scanf("%d", &N1);
    printf("Digite a N2: ");
    scanf("%d", &N2);
    printf("Digite a N3: ");
    scanf("%d", &N3);
    printf("Digite a ME: ");
    scanf("%d", &ME);

    int MA = (N1 + N2 * 2 + N3 * 3 + ME) / 7;

    if (MA >= 9)
    {
        printf("A\n");
    }
    else if (MA >= 7.5 && MA < 9)
    {
        printf("B\n");
    }
    else if (MA >= 6 && MA < 7.5)
    {
        printf("C\n");
    }
    else if (MA >= 4 && MA < 6)
    {
        printf("D\n");
    }
    else
    {
        printf("E\n");
    }

    return 0;
}