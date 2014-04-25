#include "../lib/position.h"
#include "nave.h"

Nave NAVE_create(Position pos, int vel, Position orientation, int hp)
{
	Nave *nave = malloc(sizeof(*nave));

	nave->pos = pos;
	nave->vel = vel;
	nave->orientation = orientation;
	nave->hp = hp;

	return *nave;
}
