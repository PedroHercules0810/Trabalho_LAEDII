#include <stdio.h>
#include <stdlib.h>
#include "listatel.c"

int main(int argc, char const *argv[])
{
    Lista * l;
    Contato * novo = insere_contato(l, novo, "PH", "88999325982","pedro@gmail.com");
    novo = insere_contato(l, novo, "mATEUS", "88999325982","pedro@gmail.com");

    printf("%s \n", &novo->nome);
    printf("%s", &novo->prox->nome);
    return 0;
}

