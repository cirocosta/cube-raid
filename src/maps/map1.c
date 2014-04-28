#include "map1.h"

Queue MAPS_generate_map()
{
    Queue mapa = queueInit();
    CBData *elemento = malloc(sizeof *elemento);

    elemento->elemento.nave = NAVE_create(POS_create(0, 0, 0), 10,
                                 POS_create(10, 10, 10), 10);

    queuePut(mapa, *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(12, 2, 0), 10);

    queuePut(mapa, *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(31, 6, 0), 10);

    queuePut(mapa, *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(-18, 10, 0), 10);

    queuePut(mapa, *elemento);

    free(elemento);

    return mapa;
}
