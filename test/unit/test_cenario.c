#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../src/models/nave.h"
#include "../../src/models/cenario.h"


void test_collision()
{
	Nave n = NAVE_create(POS_create(1,0,0), 10,
                         POS_create(10, 20, 30), 30);

	Nave n2 = NAVE_create(POS_create(0,1,0), 10,
                         POS_create(10, 20, 30), 30);

	assert(CENARIO_collision(n.radius, n.pos, n2.radius, n2.pos) == 1);
}

int main()
{
	test_collision();
	return 0;
}
