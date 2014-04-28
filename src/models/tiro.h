#ifndef TIRO_H
#define TIRO_H
#include "../lib/position.h"

typedef struct Tiro
{
    Position pos;
    int vel;
    Position orientation;
} Tiro;

/**
 * Metodo construtor de objetos TIRO
 * @param  pos         posicao em xyz
 * @param  vel         velocidade
 * @param  orientation orientacao em xyz
 * @return             um objeto Tiro
 */
Tiro TIRO_create(Position pos, int vel, Position orientation);

#endif
