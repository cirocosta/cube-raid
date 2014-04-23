#ifndef TIPOS_H
#include "tipos.h"
#endif
/**
 * Tipo do Buffer circular. Armazena seu tamanho, um inicio, o fim e um
 * array de elementos mantidos pelo mesmo tendo seu tamanho settado
 * dinamicamente em sua inicializacao.
 */
typedef struct {
    int size;
    int start;
    int end;
    CBData *elems;
} CircularBuffer;

/**
 * Inicializa o buffer circular. Recebe um CB e o tamanho do buffer.
 * @param cb   o endereco de memoria de um CB.
 * @param size o tamanho do buffer circular
 */
void CB_init(CircularBuffer *cb, int size);

/**
 * Faz o GC do buffer circular
 * @param cb endereco de memoria de um CB.
 */
void CB_free(CircularBuffer *cb);

/**
 * Escreve no CB.
 * @param cb   endereco de memoria de um CB
 * @param elem endereco de memoria de um elemento CBData
 */
void CB_write(CircularBuffer *cb, CBData *elem);

CBData CB_read(CircularBuffer *cb);

int CB_isEmpty(CircularBuffer *cb);


