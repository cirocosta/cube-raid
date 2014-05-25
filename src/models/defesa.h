#ifndef DEFESA_H
#define DEFESA_H
#include "../lib/position.h"

typedef struct Defesa
{
    Position pos;
    int damage;
} Defesa;

/**
 * Metodo construtor para o elemento de tipo Defesa
 * @param  pos    Elemento de posicao
 * @param  damage Dano
 * @return        O objeto criado se a alocacao acontecer com sucesso
 */
Defesa DEFESA_create(Position pos, int damage);
void DEFESA_update();

#endif
