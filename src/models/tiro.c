#include "tiro.h"

Tiro TIRO_create(Position pos, float vel, Position orientation)
{
    Tiro *tiro = malloc(sizeof(*tiro));

    tiro->pos = pos;
    tiro->vel = vel;
    tiro->orientation = orientation;

    return *tiro;
}

void TIRO_update(Tiro *tiro)
{
	if (tiro->orientation.x == 0)
		tiro->pos.x += tiro->vel;
	else
		tiro->pos.x -= tiro->vel;
}

void TIRO_draw(Tiro *tiro)
{
    float size[3] = {.1, .1, .1};

    CUBE_build(size, tiro->pos, .0);
}

void TIRO_destroy(Tiro *tiro)
{
    free(&tiro->pos);
    free(tiro);
}

