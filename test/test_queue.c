#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/lib/queue.h"

static Queue q;

void set_up()
{
   q = queueInit();
}

void tear_down()
{
    queueFree(q);
}

void test_init()
{
    set_up();

    assert(q->ini == NULL);

    tear_down();
}

void test_put()
{
    CBData *v = malloc(sizeof *v);

    set_up();

    v->elemento.value = 10;
    queuePut(q, *v);

    v->elemento.value = 20;
    queuePut(q, *v);

    assert(q->ini->conteudo.elemento.value == 10);
    assert(q->fim->conteudo.elemento.value == 20);
    assert(q->fim->prox == NULL);
    assert(q->ini->prox->conteudo.elemento.value == v->elemento.value);

    tear_down();

    free(v);
}

void test_get()
{
    CBData v1, v2;
    CBData *p1 = malloc(sizeof *p1);
    CBData *p2 = malloc(sizeof *p2);

    set_up();

    p1->elemento.value = 10;
    p2->elemento.value = 20;
    queuePut(q, *p1);
    queuePut(q, *p2);

    /* Testa queueGet() */
    v1 = queueGet(q);
    assert(q->ini->conteudo.elemento.value == 20);
    v2 = queueGet(q);

    assert(v1.elemento.value == 10);
    assert(v2.elemento.value == 20);
    assert(q->ini == NULL);

    free(p1);
    free(p2);

    tear_down();
}

void test_isEmpty()
{
    set_up();

    assert(queueIsEmpty(q));

    tear_down();
}

int main(int argc, char const *argv[])
{
    test_init();
    test_put();
    test_get();
    test_isEmpty();

    return 0;
}
