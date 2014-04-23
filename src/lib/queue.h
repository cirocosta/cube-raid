#ifndef TIPOS_H
#include "tipos.h"
#endif

typedef struct queue *Queue;

Queue queueInit();
void queuePut(Queue q, CBData v);
CBData queueGet(Queue q);
int queueEmpty(Queue q);
void queueFree(Queue q);
void queueDump(Queue q);
