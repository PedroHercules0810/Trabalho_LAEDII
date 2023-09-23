#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32

struct contato {
    char *nome;
    char *tel;
    char *email;
};

struct lista {
    struct contato *contato;
    struct lista *prox;
};

typedef struct lista *agendaDeContatos[SIZE];

struct contato *criaContato(char *nome, char *tel, char *email) {
    struct contato *novo = (struct contato *)malloc(sizeof(struct contato));
    novo->nome = strdup(nome);
    novo->tel = strdup(tel);
    novo->email = strdup(email);
    return novo;
}

int concatenacao(char c[]) {
    int key = 0, i = 0;
    while (c[i] != '\0') {
        key += c[i];
        i++;
    }
    return key % SIZE;
}

void iniciarAgenda(agendaDeContatos Hash) {
    for (int i = 0; i < SIZE; i++) {
        Hash[i] = NULL;
    }
}

int inserir(agendaDeContatos Hash, struct contato *c) {
    int key = concatenacao(c->nome);
    struct lista *novo = (struct lista *)malloc(sizeof(struct lista));
    novo->contato = c;
    novo->prox = NULL;

    if (Hash[key] == NULL) {
        Hash[key] = novo;
    } else {
        struct lista *aux = Hash[key];
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return key;
}

struct contato *buscarContato(agendaDeContatos Hash, struct contato *c) {
    int key = concatenacao(c->nome);

    struct lista *aux = Hash[key];
    while (aux != NULL) {
        if (strcmp(aux->contato->nome, c->nome) == 0) {
            return aux->contato;
        }
        aux = aux->prox;
    }

    return NULL;
}

int removerContato(agendaDeContatos Hash, struct contato *c) {
    int key = concatenacao(c->nome);

    struct lista *aux = Hash[key];
    struct lista *anterior = NULL;

    while (aux != NULL) {
        if (strcmp(aux->contato->nome, c->nome) == 0) {
            if (anterior == NULL) {
                Hash[key] = aux->prox;
            } else {
                anterior->prox = aux->prox;
            }
            free(aux->contato->nome);
            free(aux->contato->tel);
            free(aux->contato->email);
            free(aux->contato);
            free(aux);
            return 1;
        }
        anterior = aux;
        aux = aux->prox;
    }

    return 0;
}

void exportarContatos(agendaDeContatos Hash) {
    FILE *f = fopen("AgendaDeContatos.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        struct lista *aux = Hash[i];
        while (aux != NULL) {
            fprintf(f, "Nome: %s\nTelefone: %s\nEmail: %s\n\n", aux->contato->nome, aux->contato->tel, aux->contato->email);
            aux = aux->prox;
        }
    }

    fclose(f);
}

void listarContatos(agendaDeContatos Hash) {
    for (int i = 0; i < SIZE; i++) {
        struct lista *aux = Hash[i];
        while (aux != NULL) {
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n\n", aux->contato->nome, aux->contato->tel, aux->contato->email);
            aux = aux->prox;
        }
    }
}
