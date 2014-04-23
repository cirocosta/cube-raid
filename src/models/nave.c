#ifndef TIPOS_H
#include "../lib/tipos.h"
#endif

typedef struct Nave
{
    Position *pos;
    int vel;
    int orientation;
    int damage;
} Nave;
