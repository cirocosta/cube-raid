#include "defesa.h"
Defesa DEFESA_create(Position pos, int damage)
{
    Defesa *defesa = malloc(sizeof(*defesa));

    defesa->pos = pos;
    defesa->damage = damage;
    defesa->radius = 1;
    return *defesa;
}

void DEFESA_update(Defesa *defesa)
{
}

void DEFESA_fire(Defesa *defesa)
{

}

void DEFESA_destroy(Defesa *defesa)
{
    free(&defesa->pos);
    free(defesa);
}
