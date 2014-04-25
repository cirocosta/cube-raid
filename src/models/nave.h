#include "../lib/tipos.h"
#ifndef NAVE_H
#define NAVE_H

typedef struct Nave
{
    Position *pos;
    int vel;
    int orientation;
    int damage;
} Nave;

#endif