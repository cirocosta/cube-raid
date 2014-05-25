#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../src/lib/position.h"


void test_create()
{
	Position p = POS_create(10, 11, 12);

	assert(p.x == 10);
	assert(p.y == 11);
	assert(p.z == 12);
}

int main()
{
	test_create();
	return 0;
}
