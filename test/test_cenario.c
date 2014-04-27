#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/models/cenario.h"
#include "../src/lib/queue.h"

void test_consume_map()
{
    Queue mapa = queueInit();
    CBData *elemento = malloc(sizeof *elemento);

    elemento->elemento.nave = NAVE_create(POS_create(0, 0, 0), 10,
                                 POS_create(10, 10, 10), 10);

    queuePut(mapa, *elemento);

    CENARIO_consume_map(mapa);
}

int main()
{
    test_consume_map();
    return 0;
}
