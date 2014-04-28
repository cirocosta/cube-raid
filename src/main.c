#include <stdio.h>
#include <stdlib.h>
#include "lib/queue.h"
#include "maps/map1.h"
#include "models/cenario.h"

int main(int argc, char const *argv[])
{
    Queue map;

    printf("----------\n");
    printf("\n%s\n", "Bem Vindo ao Monsters Raid!\n");

    printf("\n%s\n", "Executando mapa 1");
    printf("----------\n");
    printf("\n\n");

    map = MAPS_generate_map();
    CENARIO_consume_map(map);

    return 0;
}
