#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../src/models/tiro.h"


void test_create()
{
    Tiro tiro = TIRO_create(POS_create(1,2,3), 10,
                            POS_create(10, 20, 30));

    assert(tiro.pos.x == 1);
    assert(tiro.pos.y == 2);
    assert(tiro.pos.z == 3);
    assert(tiro.vel == 10);
    assert(tiro.orientation.x == 10);
    assert(tiro.orientation.y == 20);
    assert(tiro.orientation.z == 30);
}

int main()
{
    test_create();
    return 0;
}
