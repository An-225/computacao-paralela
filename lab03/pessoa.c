//Nathan Silva Macena - 41990404

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNome 100

typedef struct
{
    char nome[maxNome];
    int idade;
    float altura;
} Pessoa;

void leNomeArquivoEntrada(char *linha)
{
    printf("Digite o nome do arquivo: ");
    scanf("%s", linha);
}

int abreArquivoAEntrada(FILE **arquivo, char *nome)
{
    if ((*arquivo = fopen(nome, "r")) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int leDadosUmaPessoa(Pessoa *destino, FILE *arquivo)
{
    char tempLinha[maxNome];
    for (int i = 0; i < 3; i++)
    {
        if (fgets(tempLinha, maxNome, arquivo))
        {
            printf("%s",tempLinha);
            switch (i)
            {
            case 0:
                strcpy(destino->nome, strtok(tempLinha, "\n"));
                break;

            case 1:
                destino->idade = atoi(tempLinha);
                break;

            default:
                destino->altura = atof(tempLinha);
                break;
            }
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void fechaArquivo(FILE *arquivo)
{
    fclose(arquivo);
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

void ordenaVetor(Pessoa *lista, int tamanho)
{
    qsort(lista, tamanho, sizeof(Pessoa), comparaAltura);
}

void gravaPessoas(Pessoa *lista, int tamanho)
{
    FILE *arquivo = fopen("saida.txt", "w");
    char quebraLinha [] = {'\n'};

    for (int pessoa = 0; pessoa < tamanho; pessoa++)
    {
        fprintf(arquivo, lista[pessoa].nome);
        char temp[maxNome];

        fprintf(arquivo,quebraLinha);

        itoa(lista[pessoa].idade,temp,10);
        fprintf(arquivo,temp);

        fprintf(arquivo,quebraLinha);

        gcvt(lista[pessoa].altura,2,temp);
        fprintf(arquivo, temp);
        
        fprintf(arquivo,quebraLinha);
    }

    fclose(arquivo);
}

int main()
{
    char S1[50];
    Pessoa Povo[10], P;
    FILE *Arq;
    int i = 1;

    leNomeArquivoEntrada(S1);
    if (abreArquivoAEntrada(Arq, S1) == 1)
    {
        do
        {
            if (leDadosUmaPessoa(&P, Arq) == 1)
            {
                Povo[i] = P;
                i++;
            }
            else
                break;
        } while (i <= 10);
        fechaArquivo(Arq);
        ordenaVetor(Povo, i);
        gravaPessoas(Povo, i);
    }
    else
        printf("Erro na abertura do arquivo");
    return 0;
}