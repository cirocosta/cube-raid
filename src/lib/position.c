#include "position.h"

Position POS_create(int x, int y, int z)
{
	Position *p = malloc(sizeof *p);

	p->x = x;
	p->y = y;
	p->z = z;

	return *p;
}
