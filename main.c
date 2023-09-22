#include<stdio.h>
#include"listatel.c"
int main() {
    agendaDeContatos agenda;
    iniciarAgenda(agenda);

    struct contato *novo = criaContato("mikael", "84996488895", "mikael.vidal@gmail.com");
    inserir(agenda, novo);
    novo = criaContato("mateus", "123", "mateus@gmail.com");
    inserir(agenda, novo);
    listarContatos(agenda);

    struct contato busca;
    busca.nome = "mikael";
    struct contato *encontrado = buscarContato(agenda, &busca);

    if (encontrado != NULL) {
        printf("\nContato encontrado:\nNome: %s\nTelefone: %s\nEmail: %s\n\n", encontrado->nome, encontrado->tel, encontrado->email);
    } else {
        printf("\nContato não encontrado.\n");
    }

    exportarContatos(agenda);
    removerContato(agenda, novo);
    listarContatos(agenda);


    return 0;
}