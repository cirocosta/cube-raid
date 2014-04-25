#include "map1.h"

Queue generate_map()
{
	Queue map1 = queueInit();
	CBData *elemento = malloc(sizeof *elemento);

	elemento->nave = NAVE_create(POS_create(0, 0, 0), 10, 10, 10);
	queuePut(map1, *elemento);




	return map1;
}
