/*

* NOME: Nathan Silva Macena

* TIA: 41990404

* 7. Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct.
  O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas.
  A struct deve armazenar os dados de idade, peso e altura.

*/

#include <stdio.h>

struct Pessoa
{
  int idade;
  float peso, altura;
};

void printPessoa(struct Pessoa p)
{
  printf("----------\n");
  printf("Idade: %d\n", p.idade);
  printf("Peso: %f\n", p.peso);
  printf("Altura: %f\n", p.altura);
  printf("----------\n");
}

int main()
{
  struct Pessoa dados[3];
  char nomes[3][20];
  for (int i = 0; i < 3; i++)
  {
    printf("Digite o nome %d: ",(i+1));
    scanf("%s",nomes[i]);
    printf("Digite a idade: ");
    scanf("%d",&dados[i].idade);
    printf("Digite a peso: ");
    scanf("%f",&dados[i].peso);
    printf("Digite a altura: ");
    scanf("%f",&dados[i].altura);
  }

  for (int i = 0; i < 3; i++)
  {
    printf("%s",nomes[i]);
    printPessoa(dados[i]);
  }
  
  
  return 0;
}