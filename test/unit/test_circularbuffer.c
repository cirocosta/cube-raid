#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../src/lib/circularbuffer.h"

static CircularBuffer *cb;
static int size = 10;

void set_up()
{
    cb = malloc(sizeof(cb));
    CB_init(cb, size);
}

void tear_down()
{
    free(cb->elems);
    free(cb);
}

void test_initialization()
{
    set_up();

    assert(cb->start == 0);
    assert(cb->end == 0);
    assert(cb->size == size);

    tear_down();
}

void test_write()
{
    CBData *element = malloc(sizeof(element));

    set_up();

    element->elemento.value = 10;
    CB_write(cb, element);

    assert(cb->elems[0].elemento.value == element->elemento.value);

    tear_down();
}

void test_read()
{
    CBData *element = malloc(sizeof(element));

    set_up();

    element->elemento.value = 10;
    CB_write(cb, element);

    assert(CB_read(cb).elemento.value == element->elemento.value);

    tear_down();
}

int main(int argc, char const *argv[])
{
    test_initialization();
    test_write();
    test_read();


    return 0;
}
