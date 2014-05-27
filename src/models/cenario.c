#include "cenario.h"

#ifndef TIPOS_H
typedef enum { NAVE, TIRO, DEFESA } Tipo;
#endif


void CENARIO_consume_map(Queue map)
{
	Nave nave;
	CircularBuffer *cb;
	int key, i;
	CBData cbElem;

	/* Create Aircraft */
    nave = NAVE_create(
    		POS_create(0., 0., 0.), 	/* Position */
    		10,							/* Velocity */
            POS_create(10., 10., 10.),	/* Orientation */
            10 							/* HP */
    );

    /* Initialize Keyboard Input */
    key = -1;
    KEYBOARD_init();

    /* Create CircularBuffer */
    cb = malloc(sizeof *cb);
    CB_init(cb, 10);
    /* Carrega todo o CB ou até o fim dos objetos do mapa */
    for (i = 0; i < cb->size && !queueIsEmpty(map); i++)
    {
    	cbElem = queueGet(map);
    	CB_write(cb, &cbElem);
    	printf("Defesa inicializado no mapa (Posicao: %g %g %g)\n",
    			cbElem.elemento.defesa.pos.x,
    			cbElem.elemento.defesa.pos.y,
    			cbElem.elemento.defesa.pos.z);
    }

    while (1)
    {
        key = KEYBOARD_check_input();
        if (key == 27) exit(0);

        NAVE_update(&nave, key);
        NAVE_show(&nave);

        usleep(100005);
    }
}


int CENARIO_collision(float radius1, Position obj1, float radius2, Position obj2)
{
	float distance = sqrt(pow(obj1.x - obj2.x, 2) + pow(obj1.y - obj2.y, 2) + pow(obj1.z - obj2.z, 2));
	if (distance < radius1 + radius2)
		return 1;

	return 0;
}
