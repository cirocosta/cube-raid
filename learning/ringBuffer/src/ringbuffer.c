#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RBUF_SIZE 256

int modulo_inc(actual, max)
{
    if (actual < max) return actual;

    return (actual - max);
}

typedef struct cb {
    unsigned char buf[RBUF_SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void CB_init(CircularBuffer *_this)
{
    memset(_this, 0, sizeof(*_this));
}

int CB_empty(CircularBuffer *_this)
{
    return (0 == _this->count);
}

int CB_full(CircularBuffer *_this)
{
    return (_this->count >= RBUF_SIZE);
}

int CB_get(CircularBuffer *_this)
{
    int c;
    if (_this->count > 0) {
        c = _this->buf[_this->tail];
        _this->tail = modulo_inc(_this->tail, RBUF_SIZE);
        --_this->count;
    } else {
        c = -1;
    }

    return c;
}

int CB_put(CircularBuffer *_this, const unsigned char c)
{
    if (_this->count < RBUF_SIZE) {
        _this->buf[_this->head] = c;
        _this->head = modulo_inc (_this->head, RBUF_SIZE);
        ++_this->count;
    }
}

void CB_flush(CircularBuffer *_this, const int clearBuffer)
{
    _this->count = 0;
    _this->head = 0;
    _this->tail = 0;

    if (clearBuffer)
        memset(_this->buf, 0, sizeof(_this->buf));
}

int main(int argc, char const *argv[])
{

    CircularBuffer *cb = malloc(sizeof(CircularBuffer));
    CB_init(cb);
    CB_put(cb, 1);
    CB_put(cb, 1);
    CB_put(cb, 1);
    CB_put(cb, 1);
    CB_put(cb, 1);
    CB_put(cb, 1);
    CB_put(cb, 2);
    CB_put(cb, 2);
    CB_put(cb, 3);
    CB_put(cb, 4);
    CB_put(cb, 5);
    CB_put(cb, 7);


    free(cb);
    return 0;
}
