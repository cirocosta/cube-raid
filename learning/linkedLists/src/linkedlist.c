#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


struct Celula;

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

/**
 * Faz uma busca por toda a lista ate encontrar alguem com numero X.
 * @return     a celula com o X ou a celula que contem NULL como prox.
 */
Celula *busca(int x, Celula *ini)
{
    Celula *p;
    p = ini->prox;
    while (p != NULL && p->conteudo != x) {
        p = p->prox;
    }

    return p;
}

int get_list_size(Celula *lista)
{
    Celula *p = lista->prox;
    int size = 0;

    while (p != NULL) {
        size++;
        p = p->prox;
    }

    return size;
}

Celula *busca_r(int x, Celula *ini)
{
    if (ini->prox == NULL)
        return NULL;
    if (ini->prox->conteudo == x)
        return ini->prox;

    return busca_r(x, ini->prox);
}

Celula *create_cel(int conteudo) {
    Celula *nova = malloc(sizeof(Celula));
    nova->conteudo = conteudo;
    nova->prox = NULL;

    return nova;
}

Celula *insere(Celula *atual, Celula *cel)
{
    atual->prox = cel->prox;
    cel->prox = atual;

    return atual;
}

void remove_from_list(Celula *p)
{
    Celula *morta;
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
}
