/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.

*/

#include <stdio.h>
#include <stdlib.h>

void remover(char *str, int index)
{
  int i = index;
  do
  {
    str[i] = str[i+1];

    i++;
  } while (str[i] != '\0');
  
}

int main()
{
  int tam_max;

  printf("Digite o tamanho da string: ");
  scanf("%d", &tam_max);

  char *str = malloc(sizeof(char) * tam_max);
  int posi;

  printf("Digite a string: ");
  scanf("%s",str);

  printf("Digite a posicao: ");
  scanf("%d",&posi);

  remover(str,posi);
  printf("%s",str);

  
  return 0;
}