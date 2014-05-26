#include <math.h>
#include "cenario.h"
#include <unistd.h>
#ifndef TIPOS_H
typedef enum { NAVE, TIRO, DEFESA } Tipo;
#endif

void CENARIO_consume_map(Queue map)
{
    Nave nave = NAVE_create(POS_create(0., 0., 0.),
                10,
                POS_create(10., 10., 10.), 10);

    while (1) {
        NAVE_update(&nave);
        NAVE_show(&nave);

        usleep(100000);
    }

}

int CENARIO_collision(float radius1, Position obj1, float radius2, Position obj2)
{
	float distance = sqrt(pow(obj1.x - obj2.x, 2) + pow(obj1.y - obj2.y, 2) + pow(obj1.z - obj2.z, 2));
	if (distance < radius1 + radius2)
		return 1;
	return 0;
}
