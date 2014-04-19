#include <stdio.h>
#include <stdlib.h>

/**
 * se P é uma lista, então:
 * -    p == NULL ou
 * -    p->prox é uma lista
 */

typedef struct Celula {
    int conteudo;
    struct Celula *prox;
} Celula;

/**
 * Uma lista pode ter cabeca ou nao.
 *
 * No primeiro caso a primeira celula da lista é irrelevante e serve
 * apenas para marcar o início da lista. A primeira célula é a cabeça e
 * está sempre no mesmo lugar na memória, mesmo que a lista fique vazia.
 *
 * No segundo caso, o conteudo da primeira celula é tão relevante quanto
 * o das demais e então a lista está vazia se e somente se o endereço de
 * sua primeira célula é NULL.
 */

void imprime(Celula *ini)
{
    Celula *p;
    for (p = ini->prox; p != NULL; p = p->prox) {
        printf("%d\n", p->conteudo);
    }
}

int main(int argc, char const *argv[])
{

    Celula *ini = (Celula*) malloc(sizeof(Celula));
    ini->prox = NULL;
    return 0;
}
