#include "nave.h"

Nave NAVE_create(Position pos, float vel, Position orientation, int hp)
{
	Nave *nave = malloc(sizeof(*nave));

	nave->pos = pos;
	nave->vel = vel;
	nave->orientation = orientation;
	nave->hp = hp;
	nave->radius = 3.0;
	nave->visibility = 5.0;

	return *nave;
}

void NAVE_destroy(Nave *nave)
{
    free(&nave->pos);
    free(nave);
}

void NAVE_update(Nave *nave, int key)
{
	nave->pos.x += nave->orientation.x;
	nave->pos.y += nave->orientation.y;
	nave->pos.z += nave->vel;


	nave->orientation.x = 0;
	nave->orientation.y = 0;

    switch(key) {
        case 97: /* A */
    	nave->orientation.x -= 1;
        break;

        case 119: /* W */
        nave->orientation.y += 1;
        break;

        case 100: /* D */
        nave->orientation.x += 1;
        break;

        case 115: /* S */
        nave->orientation.y -= 1;
        break;

    }

	nave->pos.x += nave->orientation.x;
	nave->pos.y += nave->orientation.y;
	nave->pos.z += 1;
}

void NAVE_show(Nave *nave)
{
	printf("Nave em (%g %g %g)\n",
	       nave->pos.x, nave->pos.y, nave->pos.z);
}
