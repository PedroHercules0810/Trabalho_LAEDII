#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listatelefonica.h"

int main(void)
{
    Contato *novo; 

    criaContato(novo,"Mikael", "84996488895", "mikael.vidal@gmail.com");

    agendaDeContatos agenda;
    iniciarAgenda(agenda);
    inserir(agenda, novo);

    criaContato(novo ,"Joao", "84996488891", "joao.vidal@gmail.com");

    inserir(agenda, novo);
    printf("nome: %s, telefone: %s, email:%s\n",novo->nome, novo->tel, novo->email);
    //printf("nome: %s, numero: %s, email:%s",novo->prox->nome, novo->prox->tel, novo->prox->email);
    
    return 0;
}
