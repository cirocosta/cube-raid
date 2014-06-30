/**
 * Modulo representativo de uma defesa, a qual pode se tratar de uma
 * torre ou demais objetos dependendo do que for montado (pelo factory)
 * -- ainda a implementar.
 */

#ifndef DEFESA_H
#define DEFESA_H
#include "../lib/position.h"
#include "tiro.h"

/**
 * Defesa e composta por:
 * 	- 	Posicao
 * 	-	Dano que pode causar
 */
typedef struct Defesa
{
    Position pos;
    int damage;
    int radius;
    int id;
} Defesa;

/**
 * Metodo construtor para o elemento de tipo Defesa
 * @param  pos    Elemento de posicao
 * @param  damage Dano
 * @return        O objeto criado se a alocacao acontecer com sucesso
 */
Defesa DEFESA_create(Position pos, int damage);

/**
 * Atualiza o estado de uma Defesa -- metodo a ser chamado dentro de um
 * laco principal de execucao.
 * @param defesa Defesa a atualizar
 */
void DEFESA_update(Defesa *defesa);

void DEFESA_fire(Defesa *defesa);

void DEFESA_destroy(Defesa *defesa);

#endif
