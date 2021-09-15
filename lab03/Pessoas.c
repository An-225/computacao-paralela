//Nathan Silva Macena - 41990404

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNome 50

typedef struct
{
    char nome[maxNome];
    int idade;
    float altura;
} Pessoa;

void printPessoa(Pessoa temp)
{
    printf("Nome: %s\n", temp.nome);
    printf("Idade: %d\n", temp.idade);
    printf("altura: %.2f\n", temp.altura);
}

void printPessoas(Pessoa *lista, int tam)
{
    printf("---------------\n");
    for (int i = 0; i < tam; i++)
    {
        printPessoa(lista[i]);
        printf("---------------\n");
    }
}

int comparaAltura(const void *pessoaA, const void *PessoaB)
{
    Pessoa tempA = *(Pessoa *)pessoaA;
    Pessoa tempB = *(Pessoa *)PessoaB;

    if (tempA.altura > tempB.altura)
    {
        return 1;
    }
    else if (tempA.altura == tempB.altura)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void gravaPessoas(Pessoa *pessoas, int tamanho)
{
    FILE *arquivo = fopen("output.txt", "w");

    char *quebraLinha = "\n";

    for (int pessoa = 0; pessoa < tamanho; pessoa++)
    {
        fprintf(arquivo, pessoas[pessoa].nome);
        char temp[maxNome];

        fprintf(arquivo, quebraLinha);

        itoa(pessoas[pessoa].idade, temp, 10);
        fprintf(arquivo, temp);

        fprintf(arquivo, quebraLinha);

        gcvt(pessoas[pessoa].altura, 2, temp);
        fprintf(arquivo, temp);

        fprintf(arquivo, quebraLinha);
    }

    fclose(arquivo);
}

int main()
{
    Pessoa lista[10];
    char tempLinha[maxNome];

    FILE *arq;

    arq = fopen("input.txt", "r");

    int nline = 0;
    int index;
    while (fgets(tempLinha, maxNome, arq))
    {
        index = nline / 3;
        if (nline % 3 == 0)
        {
            strcpy(lista[index].nome, strtok(tempLinha, "\n"));
        }
        else if (nline % 3 == 1)
        {
            lista[index].idade = atoi(tempLinha);
        }
        else
        {
            lista[index].altura = atof(tempLinha);
        }
        nline++;
    }
    fclose(arq);

    qsort(lista, index + 1, sizeof(Pessoa), comparaAltura);

    printPessoas(lista, index + 1);

    gravaPessoas(lista, index + 1);

    return 0;
}