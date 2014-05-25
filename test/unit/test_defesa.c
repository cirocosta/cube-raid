#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../src/models/defesa.h"


void test_create()
{
    Defesa def = DEFESA_create(POS_create(1,2,3), 10);

    assert(def.pos.x == 1);
    assert(def.pos.y == 2);
    assert(def.pos.z == 3);
    assert(def.damage == 10);
}

int main()
{
    test_create();
    return 0;
}
