#include "cenario.h"
#include "unistd.h"
#ifndef TIPOS_H
typedef enum { NAVE, TIRO, DEFESA } Tipo;
#endif

void CENARIO_consume_map(Queue map)
{
    Nave nave = NAVE_create(POS_create(0., 0., 0.),
                10,
                POS_create(10., 10., 10.), 10);

    while (1) {
        NAVE_update(&nave);
        NAVE_show(&nave);

        usleep(100000);
    }

}
