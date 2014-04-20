#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "../src/linkedlist.h"

void test_insere()
{
    /* cabeca da lista */
    Celula *lista = create_cel(0);

    assert(true && get_list_size(lista) == 0);

    Celula *cel1 = create_cel(1);
    Celula *cel2 = create_cel(2);

    insere(cel1,lista);
    insere(cel2,lista);

    Celula *p = lista->prox;
    int size = get_list_size(lista);

    assert(true && size == 2);

    free(cel2);
    free(cel1);
    free(lista);
}

int main(int argc, char const *argv[])
{

    test_insere();
    return 0;
}
