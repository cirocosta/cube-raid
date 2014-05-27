#include "map1.h"

Queue MAPS_generate_map()
{
    Queue mapa = queueInit();
    CBData *elemento = malloc(sizeof *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(10, 10, 50), 10);

    queuePut(mapa, *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(31, 6, 20), 10);

    queuePut(mapa, *elemento);

    elemento->type = DEFESA;
    elemento->elemento.defesa = DEFESA_create(POS_create(-18, 10, 50), 10);

    queuePut(mapa, *elemento);

    free(elemento);

    return mapa;
}
