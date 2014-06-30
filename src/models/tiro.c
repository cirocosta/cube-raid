#include "tiro.h"

Tiro TIRO_create(Position pos, float vel, Position orientation)
{
    Tiro *tiro = malloc(sizeof(*tiro));

    tiro->pos = pos;
    tiro->vel = vel;
    tiro->orientation = orientation;

    return *tiro;
}

void TIRO_update(Tiro *tiro, int dir)
{
	if (dir == 0)
		tiro->pos.x += tiro->vel;
	else
		tiro->pos.x -= tiro->vel;
}

void TIRO_draw(Tiro *tiro)
{

}

void TIRO_destroy(Tiro *tiro)
{
    free(&tiro->pos);
    free(tiro);
}

