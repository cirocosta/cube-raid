#ifndef TIPOS_H
#define TIPOS_H
#include "../models/defesa.h"
#include "../models/nave.h"
#include "../models/tiro.h"

/**
 * CBData trata-se de um elemento de tipo variavel dada a definicao dos
 * tipos possiveis do union.
 */
typedef enum { NAVE, TIRO, DEFESA } Tipo;

typedef union {
    int value;
    Defesa defesa;
    Tiro tiro;
    Nave nave;
} Elemento;

typedef struct {
    int type;
    Elemento elemento;
} CBData;

#endif
