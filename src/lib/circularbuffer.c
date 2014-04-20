#include <stdlib.h>
// #include <stdio.h>
#include "circularbuffer.h"

// typedef union {
//     int value;
// } CBData;

// typedef struct {
//     int size;
//     int start;
//     int end;
//     CBData *elems;
// } CircularBuffer;

void CB_init(CircularBuffer *cb, int size)
{
    cb->size = size + 1;
    cb->start = 0;
    cb->end = 0;
    cb->elems = (CBData*) calloc(cb->size, sizeof(CBData));
}

void CB_free(CircularBuffer *cb)
{
    free(cb->elems);
}

void CB_write(CircularBuffer *cb, CBData *elem)
{
    cb->elems[cb->end] = *elem;
    cb->end = (cb->end + 1) % cb->size;
    if (cb->end == cb->start)
        cb->start = (cb->start + 1) % cb->size;
}

void CB_read(CircularBuffer *cb, CBData *elem)
{
    *elem = cb->elems[cb->start];
    cb->start = (cb->start + 1) % cb->size;
}

int CB_isEmpty(CircularBuffer *cb)
{
    return cb->end == cb->start;
}

/////////////
// EXEMPLO //
/////////////

int main(int argc, char const *argv[])
// {
//     CircularBuffer cb;
//     CBData elem = {0};
//     int bufferSize = 10;

//     CB_init(&cb,bufferSize);

//     for (elem.value = 0; elem.value < 3 * bufferSize; ++elem.value)
//         CB_write(&cb, &elem);


//     while (!CB_isEmpty(&cb)) {
//         CB_read(&cb, &elem);
//         printf("%d\n", elem.value);
//     }

//     CB_free(&cb);

//     return 0;
// }
