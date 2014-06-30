#include "nave.h"

Nave NAVE_create(Position pos, float vel, Position orientation, int hp)
{
	Nave *nave = malloc(sizeof(*nave));

	nave->pos = pos;
	nave->vel = vel;
	nave->orientation = orientation;
	nave->hp = hp;
	nave->radius = 1.0;
	nave->visibility = 5.0;

	return *nave;
}

void NAVE_destroy(Nave *nave)
{
    free(&nave->pos);
    free(nave);
}

void NAVE_draw(Nave *nave)
{
	float size[3] = {.5, .5, .5};

	CUBE_build(size, nave->pos, .0);
}

void NAVE_update(Nave *nave, bool * keysPressed, float z)
{
	if (keysPressed[KB_A])
		if (nave->pos.x < -2)
			nave->pos.x += .01;
		else
			nave->pos.x -= .1;
	else if (keysPressed[KB_D])
		if (nave->pos.x > 2)
			nave->pos.x -= .01;
		else
			nave->pos.x += .1;

	if (keysPressed[KB_W])
		if (nave->pos.y > 2)
			nave->pos.y -= .01;
		else
			nave->pos.y += .1;
	else if (keysPressed[KB_S])
		if (nave->pos.y < -2)
			nave->pos.y += .01;
		else
			nave->pos.y -= .1;

	nave->pos.z = -z - 5;
}

void NAVE_show(Nave *nave)
{
	printf("Nave em (%g %g %g)\n",
	       nave->pos.x, nave->pos.y, nave->pos.z);
}
