/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 14. Faça uma rotina que insira um caracter em uma string do tipo char Str[100], dada a posição do caracter.

*/

#include <stdio.h>
#include <stdlib.h>

void inserir(char *str, int index, char obj, int size)
{
  for (int i = size-1; i < index; i--)
  {
    str[i] = str[i+1];
  }
  str[index] = obj;
  
}

int main()
{
  int tam_max;

  printf("Digite o tamanho da string: ");
  scanf("%d", &tam_max);

  char *str = malloc(sizeof(char) * tam_max);
  char obj;
  int posi;

  printf("Digite a string: ");
  scanf("%s", str);

  printf("Digite a posicao: ");
  scanf("%d", &posi);

  printf("Digite o caracter: ");
  scanf(" %c", &obj);

  inserir(str, posi, obj, tam_max);
  printf("%s", str);

  return 0;
}