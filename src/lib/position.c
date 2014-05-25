#include "position.h"

Position POS_create(float x, float y, float z)
{
	Position *p = malloc(sizeof *p);

	p->x = x;
	p->y = y;
	p->z = z;

	return *p;
}
