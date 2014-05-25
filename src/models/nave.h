#ifndef NAVE_H
#define NAVE_H
#include "../lib/position.h"

typedef struct Nave
{
    Position pos;
    float vel;
    Position orientation;
    int hp;
} Nave;

/**
 * Metodo construtor para o objeto Nave
 * @param  pos         Objeto posicao em xyz
 * @param  vel         velocidade
 * @param  orientation Orientacao em xyz
 * @param  hp          vida
 * @return             Objeto criado
 */
Nave NAVE_create(Position pos, float vel, Position orientation, int hp);

/**
 * Destroi um objeto do tipo Nave (desaloca memoria)
 * @param nave [description]
 */
void NAVE_destroy(Nave *nave);
void NAVE_update(Nave *nave);
void NAVE_show(Nave *nave);

#endif
