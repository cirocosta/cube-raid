#ifndef NAVE_H
#define NAVE_H
#include "../lib/position.h"

typedef struct Nave
{
    Position pos;
    int vel;
    Position orientation;
    int hp;
} Nave;

Nave NAVE_create(Position pos, int vel, Position orientation, int hp);

void NAVE_destroy(Nave *nave);

#endif
