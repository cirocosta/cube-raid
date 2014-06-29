#ifndef NAVE_H
#define NAVE_H
#include "../lib/position.h"
#include "../lib/glutils.h"
#include <stdio.h>

/**
 * A nave e composta por:
 * -	{float} Velocidade
 * -	{Position} orientacao (para onde esta indo)
 * -	{int} Vida
 * -	{float} raio representativo de suas dimensoes
 */
typedef struct Nave
{
    Position pos;
    float vel;
    Position orientation;
    int hp;
    float radius;
    float visibility;
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

/**
 * Atualiza atributos da nava - executado dentro do laco principal do
 * jogo.
 * @param nave Objeto da nave.
 * @param key Keycode do input no momento
 */
void NAVE_update(Nave *nave, int key);

/**
 * Expoe os atributos da Nave
 * @param nave Nave a mostrar
 */
void NAVE_show(Nave *nave);

void NAVE_draw(Nave *nave);

#endif
