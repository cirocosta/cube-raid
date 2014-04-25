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
    CBData *v1 = malloc(sizeof *v1);
    CBData *v2 = malloc(sizeof *v2);

    set_up();

    v1->value = 10;
    v2->value = 20;
    queuePut(q, *v1);
    queuePut(q, *v2);

    assert(q->fim->conteudo.value == 20);
    assert(q->fim->prox == NULL);
    assert(q->ini->prox->conteudo.value == v2->value);

    tear_down();

    free(v1);
    free(v2);
}

void test_get()
{
    CBData v1, v2;
    CBData *p1 = malloc(sizeof *p1);
    CBData *p2 = malloc(sizeof *p2);

    set_up();

    p1->value = 10;
    p2->value = 20;
    queuePut(q, *p1);
    queuePut(q, *p2);

    /* Testa queueGet() */
    v1 = queueGet(q);
    assert(q->ini->conteudo.value == 20);
    v2 = queueGet(q);

    assert(v1.value == 10);
    assert(v2.value == 20);
    assert(q->ini == NULL);

    /*free(v1);
    free(v2);*/

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
