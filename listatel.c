#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <listatel.h>

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

Contato *insere_contato(Lista *l, Contato *c, char *nome, char *tel, char *email)
{
    Contato *novo = (Contato *)malloc(sizeof(Contato));

    if(novo == NULL){
        printf("Alocação mal sucedida! \n Encerrando execução!\n");
        exit(1);
    }

    strcpy(novo->nome, nome);
    strcpy(novo->tel, tel);
    strcpy(novo->email, email);
    novo->prox = c;

    return novo;
}