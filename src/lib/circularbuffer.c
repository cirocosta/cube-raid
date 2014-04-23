#include <stdlib.h>
#include <stdio.h>
#include "circularbuffer.h"

union CBData;
struct CircularBuffer;

void CB_init(CircularBuffer *cb, int size)
{
    cb->size = size;
    cb->start = 0;
    cb->end = 0;
    cb->elems = (CBData*) calloc(cb->size, sizeof(CBData));
}

void CB_free(CircularBuffer *cb)
{
    free(cb->elems);
    free(cb);
}

void CB_write(CircularBuffer *cb, CBData *elem)
{
    cb->elems[cb->end] = *elem;
    cb->end = (cb->end + 1) % cb->size;
    if (cb->end == cb->start)
        cb->start = (cb->start + 1) % cb->size;
}

CBData CB_read(CircularBuffer *cb)
{
    CBData element = cb->elems[cb->start];
    cb->start = (cb->start + 1) % cb->size;
    return element;
}

int CB_isEmpty(CircularBuffer *cb)
{
    return cb->end == cb->start;
}
