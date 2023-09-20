#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listatel.h"

#define size 32

typedef struct contato
{
    char *nome[50];
    char *tel[11];
    char *email[50];
    Contato *prox;
} Contato;

typedef struct lista
{
    Contato *contato[size];
} Lista;

int dobra_binaria(char *chave)
{
    int valor_resultante = 0;

    for (int i = 0; i < strlen(chave); i++)
    {
        valor_resultante <<= 4;

        valor_resultante += chave[i];
    }

    int indice = valor_resultante % size;

    return indice;
}

Contato *insere_contato(Lista *l, Contato *c, char *nome, char *tel, char *email)
{

    int i;
    for (i = 0; i < size; i++)
    {
        l->contato[i] = NULL;
    }

    Contato *novo = (Contato *)malloc(sizeof(Contato));

    if (novo == NULL)
    {
        printf("Alocação mal sucedida! \n Encerrando execução!\n");
        exit(1);
    }

    strcpy(novo->nome, nome);
    strcpy(novo->tel, tel);
    strcpy(novo->email, email);

    int indice = dobra_binaria(novo->nome);

    if (l->contato[indice] == NULL)
    {
        l->contato[indice] = novo;
    }
    else
    {
        l->contato[indice] = novo->prox;
    }

    return novo;
}
