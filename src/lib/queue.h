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

Queue queueInit();
void queuePut(Queue q, CBData v);
CBData queueGet(Queue q);
int queueIsEmpty(Queue q);
void queueFree(Queue q);
void queueDump(Queue q);
#endif
