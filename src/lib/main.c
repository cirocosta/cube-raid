#include <stdlib.h>
#include <stdio.h>
#include "position.h"

int main(int argc, char const *argv[])
{

    Position *pos = malloc(sizeof(Position));
    pos->x = 10;

    printf("Horizontal Position: %d", pos->x);

    return 0;
}
