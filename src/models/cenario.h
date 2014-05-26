#ifndef CENARIO_H
#define CENARIO_H
#include "../lib/queue.h"
#include <math.h>

/**
 * Consome um mapa passado como argumento.
 * @param map mapa a ser consumido
 */
void CENARIO_consume_map(Queue map);
int CENARIO_collision(float radius1, Position obj1, float radius2, Position obj2);
#endif
