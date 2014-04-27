#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/models/nave.h"


void test_create()
{
	Nave n = NAVE_create(POS_create(1,2,3), 10, POS_create(10, 20, 30), 30);

	assert(n.pos.x == 1);
	assert(n.pos.y == 2);
	assert(n.pos.z == 3);
	assert(n.vel == 10);
	assert(n.orientation.x == 10);
    assert(n.orientation.y == 20);
    assert(n.orientation.z == 30);
	assert(n.hp == 30);
}

int main()
{
	test_create();
	return 0;
}
