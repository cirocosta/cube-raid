#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

typedef struct queueNode* Link;
typedef struct queue* Queue;

struct queueNode {
	CBData conteudo;
	Link prox;
};

struct queue {
	Link ini;
	Link fim;
};

/**
 * Metodo construtor da Queue.
 * @return um objeto Queue
 */
Queue queueInit();

/**
 * Adiciona um  elemento CBData ao fim da fila q
 * @param q fila
 * @param v elemento CBData a adicionar
 */
void queuePut(Queue q, CBData v);

/**
 * Obtem um elemento do inicio da fila
 * @param  q fila
 * @return   elemento obtido
 */
CBData queueGet(Queue q);

/**
 * Verifica se a fila esta vazia ou nao.
 * @param  q fila
 * @return   0 | 1 se vazia ou nao
 */
int queueIsEmpty(Queue q);

/**
 * Desaloca a memoria passada para a fila.
 * @param q fila
 */
void queueFree(Queue q);
#endif
