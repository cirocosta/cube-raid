#include <stdio.h>
#include <stdlib.h>

#ifndef TIPOS_H
#include "tipos.h"
#endif

typedef struct queueNode *Link;
typedef struct queue *Queue;

struct queueNode {
	CBData conteudo;
	Link prox;
};

struct queue {
	Link ini;
	Link fim;
};

void queueDump(Queue q)
{
	Link p = q->ini;
	
	if (p == NULL)
		printf("\n[DUMP] A fila esta vazia\n");
	else
	{
		printf("\n[DUMP] Conteudo da lista:\n");
	    printf("endereco      elemento   prox\n");
	    
		while (p != NULL)
		{
			printf("%p     %5d      %p\n", (void*)p, p->conteudo.tipo, (void*)p->prox);
			p = p->prox;
		}
		printf("\n");
	}	
}

Queue queueInit()
{
	Queue q = malloc(sizeof *q);
	q->ini = q->fim = NULL;
	
	printf("\nInicializando uma fila: %p\n", (void*)q);
	
	return q;
}

void queuePut(Queue q, CBData v)
{
	Link p = malloc(sizeof *p);
	p->conteudo = v;
	p->prox = NULL;
		
	printf("\nColocando na fila: %d\n", p->conteudo.tipo);	
		
	if (q->ini == NULL)
	{
		q->ini = q->fim = p;
		return;		
	}	
		
	q->fim->prox = p;
	q->fim = p;	
}

CBData queueGet(Queue q)
{
	CBData conteudo;
	Link p = q->ini;
	
	if (q->ini == NULL)
	{
		fprintf(stderr,"[ERRO] Tentando retirar de uma fila vazia\n");
		exit(-1);		
	}
	
	conteudo = p->conteudo;

	q->ini = q->ini->prox;
	
	free(p);
	printf("\nRetirando o primeiro item da fila: %d\n", conteudo.tipo);
	
	return conteudo;
}

int queueEmpty(Queue q)
{
	return q->ini == NULL;
}

void queueFree(Queue q)
{
	while (q->ini != NULL)
	{
		Link p = q->ini;
		q->ini = p->prox;
		free(p);
	}
	free(q);
	
	printf("\nA fila foi liberada da memoria\n");
	
}
