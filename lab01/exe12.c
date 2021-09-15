/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 12. Faça uma função que retorne a posição de um dado caracter dentro de uma string.

*/

#include <stdio.h>
#include <stdlib.h>

int remover(char *str, char obj)
{
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == obj)
    {
      return i;
    }

    i++;
  }

  return -1;
}

int main()
{
  int tam_max;

  printf("Digite o tamanho da string: ");
  scanf("%d", &tam_max);

  char *str = malloc(sizeof(char) * tam_max);
  char obj;

  printf("Digite a string: ");
  scanf("%s",str);

  printf("Digite o caracter: ");
  scanf(" %c",&obj);

  printf("Posicao: %d",remover(str,obj));

  
  return 0;
}