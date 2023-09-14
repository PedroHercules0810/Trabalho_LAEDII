#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listatelefonica.h"

int main(void)
{
    struct contato *novo = criaContato("Mikael", "84996488895", "mikael.vidal@gmail.com");

    agendaDeContatos agenda;
    iniciarAgenda(agenda);
    inserir(agenda, novo);

    novo = criaContato("Joao", "84996488891", "joao.vidal@gmail.com");

    inserir(agenda, novo);
    printf("nome: %s, telefone: %s, email:%s\n",novo->nome, novo->tel, novo->email);
    //printf("nome: %s, numero: %s, email:%s",novo->prox->contato->nome, novo->tel, novo->email);
    
    return 0;
}
