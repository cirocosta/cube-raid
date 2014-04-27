#include "defesa.h"
Defesa DEFESA_create(Position pos, int damage)
{
    Defesa *defesa = malloc(sizeof(*defesa));

    defesa->pos = pos;
    defesa->damage = damage;

    return *defesa;
}
