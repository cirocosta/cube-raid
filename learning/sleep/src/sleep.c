#include <stdio.h>

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#endif

void sleep_in_seconds(int seconds)
{
    int i = 0;
    for(i = 0; i < 100; i++) {
        sleep(1);
        printf("%d\n", i);
    }
}

void sleep_in_microseconds(int microseconds)
{
    int i = 0;
    for (i = 0; i < 100; i++) {
        usleep(microseconds);
        printf("%d\n", i);

    }
}

int main(int argc, char const *argv[])
{

    if (argc > 1) {
        sleep_in_seconds(1);
    } else {
        sleep_in_microseconds(100000);
    }

    return 0;
}
