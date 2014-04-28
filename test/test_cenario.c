#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/models/cenario.h"
#include "../src/lib/queue.h"

#ifndef TIPOS_H
typedef enum { NAVE, TIRO, DEFESA } Tipo;
#endif

void test_consume_map()
{
    Queue mapa = queueInit();
    CBData *elemento = malloc(sizeof *elemento);

    elemento->type = NAVE;
    elemento->elemento.nave = NAVE_create(POS_create(0, 0, 0), 10,
                                 POS_create(10, 10, 10), 10);

    queuePut(mapa, *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(0, 0, 0), 10);

    queuePut(mapa, *elemento);


    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(0, 0, 0), 10);

    queuePut(mapa, *elemento);


    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(0, 0, 0), 10);

    queuePut(mapa, *elemento);


    CENARIO_consume_map(mapa);

    free(elemento);
}

int main()
{
    test_consume_map();
    return 0;
}
