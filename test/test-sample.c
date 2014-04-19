#include "ourmodule.h"

#include <assert.h>
#include <stdbool.h>

static void test_my_function()
{
    assert(some_fun_call() && "test_my_function()");
}

int main(int argc, char const *argv[])
{

    text_my_function();
    /* ... */

    return 0;
}
