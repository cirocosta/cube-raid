#ifndef DEFESA_H
#define DEFESA_H
#include "../lib/position.h"

typedef struct Defesa
{
    Position pos;
    int damage;
    /* and some attack params*/
} Defesa;

Defesa DEFESA_create(Position pos, int damage);

#endif
