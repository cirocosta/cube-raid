#include "defesa.h"
Defesa DEFESA_create(Position pos, int damage)
{
    Defesa *defesa = malloc(sizeof(*defesa));

    defesa->pos = pos;
    defesa->damage = damage;
    defesa->radius = 1;
    defesa->counter = 0;

    return *defesa;
}

int DEFESA_update(Defesa *defesa)
{
	if (defesa->counter++ > 200 && defesa->counter < 2000) {
		defesa->counter = 9999;
        return 1;
    }

    return 0;
}

Tiro DEFESA_fire(Defesa *defesa)
{
	printf("%s\n", "JUST FIRED!!!");
	Tiro tiro = TIRO_create(defesa->pos, 1., POS_create(1., 0., 0.));

	return tiro;
}

void DEFESA_destroy(Defesa *defesa)
{
    free(&defesa->pos);
    free(defesa);
}
