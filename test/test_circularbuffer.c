#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/lib/circularbuffer.h"

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

    element->value = 10;
    CB_write(cb, element);

    assert(cb->elems[0].value == element->value);

    tear_down();
}

void test_read()
{
    CBData *element = malloc(sizeof(element));
    
    set_up();

    element->value = 10;
    CB_write(cb, element);

    assert(CB_read(cb).value == element->value);

    tear_down();
}

int main(int argc, char const *argv[])
{
    test_initialization();
    test_write();
    test_read();


    return 0;
}


/*
EXEMPLO


int main(int argc, char const *argv[])
{
    CircularBuffer cb;
    CBData elem = {0};
    int bufferSize = 10;

    CB_init(&cb,bufferSize);

    for (elem.value = 0; elem.value < 3 * bufferSize; ++elem.value)
        CB_write(&cb, &elem);

    while (!CB_isEmpty(&cb)) {
       CB_read(&cb, &elem);
        printf("%d\n", elem.value);
    }

    CB_free(&cb);

    return 0;
}
*/
