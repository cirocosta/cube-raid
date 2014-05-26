#ifndef TIPOS_H
#define TIPOS_H
#include "../models/defesa.h"
#include "../models/nave.h"
#include "../models/tiro.h"

typedef enum { NAVE, TIRO, DEFESA } Tipo;

/**
 * Elemento trata-se de um elemento de tipo variavel dada a definicao
 * dos tipos possiveis do union. Isto nos da a possibilidade de podermos
 * passar um elemento qualquer para uma fila/buffer, por exemplo.
 */
typedef union {
    int value;
    Defesa defesa;
    Tiro tiro;
    Nave nave;
} Elemento;

/**
 * CBData trata-se de um elemento de tipo variavel dada a definicao dos
 * tipos possiveis do union. Permite que, possamos identificar (atraves
 * do type) qual tipo de elemento estamos utilizando.
 */
typedef struct {
    int type;
    Elemento elemento;
} CBData;

#endif
