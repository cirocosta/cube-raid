#include "../lib/position.h"
#include "nave.h"

Nave NAVE_create(Position pos, int vel, int orientation, int damage)
{
	Nave *nave = malloc(sizeof(*nave));

	nave->pos = pos;
	nave->vel = vel;
	nave->orientation = orientation;
	nave->damage = damage;

	return *nave;
}
