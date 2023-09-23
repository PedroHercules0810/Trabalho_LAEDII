#include <stdio.h>
<<<<<<< HEAD
#include "listatel.c"
int main()
{
    agendaDeContatos agenda;
    iniciarAgenda(agenda);
    int opc;
    do{
    printf("\nMenu:\n");
    printf("1. Inserir Contato\n");
    printf("2. Buscar Contato\n");
    printf("3. Remover Contato\n");
    printf("4. Listar Contatos\n");
    printf("5. Exportar Contatos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
    {
        char nome[100], tel[20], email[100];
        printf("Digite o nome do contato: ");
        scanf("%s", nome);
        printf("Digite o telefone do contato: ");
        scanf("%s", tel);
        printf("Digite o email do contato: ");
        scanf("%s", email);
        struct contato *novo = criaContato(nome, tel, email);
        inserir(agenda, novo);
        printf("Contato inserido com sucesso!\n");
        break;
    }
    case 2:
    {
        char nome[100];
        printf("Digite o nome do contato a ser buscado: ");
        scanf("%s", nome);
        struct contato busca;
        busca.nome = nome;
        struct contato *encontrado = buscarContato(agenda, &busca);
        if (encontrado != NULL)
        {
            printf("\nContato encontrado:\nNome: %s\nTelefone: %s\nEmail: %s\n\n", encontrado->nome, encontrado->tel, encontrado->email);
        }
        else
        {
            printf("\nContato não encontrado.\n");
        }
        break;
    }
    case 3:
    {
        char nome[100];
        printf("Digite o nome do contato a ser removido: ");
        scanf("%s", nome);
        struct contato busca;
        busca.nome = nome;
        if (removerContato(agenda, &busca))
        {
            printf("Contato removido com sucesso!\n");
        }
        else
        {
            printf("Contato não encontrado.\n");
        }
        break;
    }
    case 4:
        listarContatos(agenda);
        break;
    case 5:
        exportarContatos(agenda);
        printf("Contatos exportados para 'AgendaDeContatos.txt'.\n");
        break;
    case 0:
        printf("Saindo...\n");
        break;
    default:
        printf("Opção inválida. Tente novamente.\n");
    }
}
while (opc != 0)
    ;

return 0;
}
=======
#include <stdlib.h>
#include "listatel.c"

int main(int argc, char const *argv[])
{
    Lista * l;
    Contato * novo = insere_contato(l, novo, "PH", "88999325982","pedro@gmail.com");
    novo = insere_contato(l, novo, "mATEUS", "88999325982","pedro@gmail.com");

    printf("%s \n", &novo->nome);
    printf("%s", &novo->prox->nome);

    int test = dobra_binaria("Pedro");

    printf("%s", test);

    return 0;
}

>>>>>>> bffd035c24af7b59a18ec54c7b9ef16b214d8048
