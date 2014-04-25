#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/models/nave.h"


void test_create()
{
	Nave n = NAVE_create(POS_create(1,2,3), 10, 20, 30);

	assert(n.pos.x == 1);
	assert(n.pos.y == 2);
	assert(n.pos.z == 3);
	assert(n.vel == 10);
	assert(n.orientation == 20);
	assert(n.damage == 30);
}

int main()
{
	test_create();
	return 0;
}
