#include "../lib/position.h"
#include "nave.h"
#include <stdio.h>

Nave NAVE_create(Position pos, float vel, Position orientation, int hp)
{
	Nave *nave = malloc(sizeof(*nave));

	nave->pos = pos;
	nave->vel = vel;
	nave->orientation = orientation;
	nave->hp = hp;
	nave->radius = 3.0;

	return *nave;
}

void NAVE_destroy(Nave *nave)
{
    free(&nave->pos);
    free(nave);
}

void NAVE_update(Nave *nave)
{
	nave->pos.x += 1.;
	nave->pos.y += 1.;
	nave->pos.z += 1.;
}

void NAVE_show(Nave *nave)
{
	printf("Nave em (%f %f %f)\n",
	       nave->pos.x, nave->pos.y, nave->pos.z);
}
