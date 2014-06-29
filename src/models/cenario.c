#include "cenario.h"

#ifndef TIPOS_H
typedef enum { NAVE, TIRO, DEFESA } Tipo;
#endif


void CENARIO_consume_map(Queue map)
{
	Nave nave;
	CircularBuffer *cb;
	int key;

	/* Creates Aircraft */
    nave = NAVE_create(
    		POS_create(0., 0., 0.), 	/* Position */
    		1,							/* Velocity */
            POS_create(10., 10., 10.),	/* Orientation */
            10 							/* HP */
    );

    /* Initializes Keyboard Input */
    key = -1;
    KEYBOARD_init();

    /* Enemies initialization */
    CENARIO_init(&cb, map);

    while (1)
    {
        key = KEYBOARD_check_input();
        if (key == 27) exit(0);

/*      NAVE_update(&nave, key);
        NAVE_show(&nave); */
        CENARIO_detect_collision(cb, nave);

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

int CENARIO_init(CircularBuffer **cb, Queue map)
{
	int i;
	CBData cbElem;

	*cb = malloc(sizeof *cb);
	CB_init(*cb, 10);

    /* Carrega todo o CB ou até o fim dos objetos do mapa */
    for (i = 0; i < (**cb).size && !queueIsEmpty(map); i++)
    {
    	cbElem = queueGet(map);
    	CB_write(*cb, &cbElem);
    	printf("Defesa inicializado no mapa (Posicao: %g %g %g)\n",
    			cbElem.elemento.defesa.pos.x,
    			cbElem.elemento.defesa.pos.y,
    			cbElem.elemento.defesa.pos.z);
    }

    return 0;
}

/* Percorre o CB atrás de colisões */
int CENARIO_detect_collision(CircularBuffer *cb, Nave nave)
{
	int start, collision;
	Position objPos;

	for(start = cb->start; start < cb->end; start++)
	{
		objPos = POS_create(
				cb->elems[start].elemento.defesa.pos.x,
				cb->elems[start].elemento.defesa.pos.y,
				cb->elems[start].elemento.defesa.pos.z);

		collision = CENARIO_collision(nave.radius, nave.pos, cb->elems[start].elemento.defesa.radius, objPos);
		if (collision == 1)
			printf("[GAME-LOG] OCORREU UMA COLISAO!\n");
	}
	return 0;
}

Queue CENARIO_create(char* name)
{
	FILE* fp;
	float x, y, z;
	int hp;
	Queue mapa = queueInit();
	CBData *elemento = malloc(sizeof *elemento);
	char str[100] = "src/maps/";

	strcat(str, name);
	fp = fopen(str, "r");

	while(fscanf(fp, "%f %f %f %d", &x, &y, &z, &hp) != EOF)
	{
	    elemento->type = DEFESA;
	    elemento->elemento.defesa = DEFESA_create(POS_create(x, y, z), hp);

	    queuePut(mapa, *elemento);
	}

    free(elemento);
    return mapa;
}
