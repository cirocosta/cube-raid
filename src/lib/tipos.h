#ifndef TIPOS_H
#define TIPOS_H

/**
 * CBData trata-se de um elemento de tipo variavel dada a definicao dos
 * tipos possiveis do union.
 */
typedef enum { NAVE, TIRO, DEFESA } Tipo;
typedef struct {
    Tipo tipo;
    int value;
} CBData;

/**
 * Posiçao nas tres coordenadas de um objeto qualquer
 */
typedef struct pos {
    int x;
    int y;
    int z;
} Position;

#endif
