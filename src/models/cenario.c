#include "cenario.h"
#include "unistd.h"
#ifndef TIPOS_H
typedef enum { NAVE, TIRO, DEFESA } Tipo;
#endif

void CENARIO_consume_map(Queue map)
{
    int posx;
    int posy;
    int posz;
    CBData element;

    while (!queueIsEmpty(map)) {
        element = queueGet(map);

        printf("\n");

        switch(element.type) {
            case NAVE:
                posx = element.elemento.nave.pos.x;
                posy = element.elemento.nave.pos.y;
                posz = element.elemento.nave.pos.z;

                printf("Nave presente em (%d, %d, %d).", posx, posy, posz);
                break;

            case TIRO:
                posx = element.elemento.tiro.pos.x;
                posy = element.elemento.tiro.pos.y;
                posz = element.elemento.tiro.pos.z;

                printf("Tiro presente em (%d, %d, %d).", posx, posy, posz);
                break;

            case DEFESA:
                posx = element.elemento.defesa.pos.x;
                posy = element.elemento.defesa.pos.y;
                posz = element.elemento.defesa.pos.z;

                printf("Defesa presente em (%d, %d, %d).", posx, posy, posz);
                break;
        }

        usleep(1000000);
    }
}
