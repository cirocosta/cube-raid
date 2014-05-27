#include "defesa.h"
Defesa DEFESA_create(Position pos, int damage)
{
    Defesa *defesa = malloc(sizeof(*defesa));

    defesa->pos = pos;
    defesa->damage = damage;
    defesa->radius = 3;
    return *defesa;
}

void DEFESA_update()
{
}
