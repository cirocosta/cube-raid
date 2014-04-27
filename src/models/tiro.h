#ifndef TIRO_H
#define TIRO_H
#include "../lib/position.h"

typedef struct Tiro
{
    Position pos;
    int vel;
    Position orientation;
} Tiro;

Tiro TIRO_create(Position pos, int vel, Position orientation);

#endif
