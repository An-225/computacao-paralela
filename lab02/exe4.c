/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 4.Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética.
  Faça isto com string de C e de C++

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int tam_max;

  printf("Digite o tamanho maximo dos nomes: ");
  scanf("%d", &tam_max);

  char *nome_um = malloc(sizeof(char) * tam_max);
  char *nome_dois = malloc(sizeof(char) * tam_max);

  printf("Digite o primeiro nome: ");
  scanf("%s",nome_um);

  printf("Digite o segundo nome: ");
  scanf("%s",nome_dois);

  if (strcmp(nome_um, nome_dois) <= 0)
  {
    printf("%s\n",nome_um);
  }
  else
  {
    printf("%s\n",nome_dois);
  }

  return 0;
}