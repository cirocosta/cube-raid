#include <stdlib.h>

#ifndef POSITION_H
#define POSITION_H

typedef struct pos {
    int x;
    int y;
    int z;
} Position;

Position POS_create(int x, int y, int z);

#endif
