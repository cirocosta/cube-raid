/**
 * Modulo representando o cenario. Tem seus metodos utilizados a partir
 * do momento em que o usuario esta dentro de um mapa.
 */

#ifndef CENARIO_H
#define CENARIO_H
#include "../lib/queue.h"
#include <math.h>

/**
 * Consome um mapa passado como argumento.
 * @param map mapa a ser consumido
 */
void CENARIO_consume_map(Queue map);

/**
 * Verifica se ha uma colisao dadas duas posicoes e dois raios.
 * @param  radius1 Primeiro raio
 * @param  obj1    Primeiro objeto
 * @param  radius2 Segundo raio
 * @param  obj2    Segundo objeto
 * @return         1 o 0 se ha colisoca ou nao, respectivamente.
 */
int CENARIO_collision(float radius1, Position obj1, float radius2, Position obj2);

#endif
