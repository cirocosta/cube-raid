#ifndef POSITION_H
#define POSITION_H

#include <stdlib.h>

/**
 * Estrutura de posicao utilizado pelos modulos que necessitam de mais
 * de uma coordenada.
 */
typedef struct pos {
    float x;
    float y;
    float z;
} Position;

/**
 * Metodo construtor de uma Position
 * @param  x distancia lateral (sendo 0 o meio)
 * @param  y distancia para frente (sendo 0 o inicio)
 * @param  z posicao vertical (altura)
 * @return   um objeto Position
 */
Position POS_create(float x, float y, float z);

#endif
