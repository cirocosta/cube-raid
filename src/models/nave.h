#ifndef NAVE_H
#define NAVE_H
#include "../lib/position.h"

typedef struct Nave
{
    Position pos;
    int vel;
    int orientation;
    int damage;
} Nave;

Nave NAVE_create(Position pos, int vel, int orientation, int damage);

#endif
