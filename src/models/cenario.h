/**
 * Modulo representando o cenario. Tem seus metodos utilizados a partir
 * do momento em que o usuario esta dentro de um mapa.
 */

#ifndef CENARIO_H
#define CENARIO_H
#include <math.h>
#include <unistd.h>
#include <string.h>

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "../models/tiro.h"
#include "../lib/queue.h"
#include "../lib/keyboard.h"
#include "../lib/circularbuffer.h"
#include "../lib/position.h"
#include "../lib/queue.h"
#include "../lib/tipos.h"

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
int CENARIO_init(CircularBuffer **cb, Queue map);
int CENARIO_detect_collision(CircularBuffer *cb, Nave *nave);
Queue CENARIO_create(char* name);
void CENARIO_draw(CircularBuffer *cb, Nave nave);
#endif
