#include <stdio.h>
#include <stdlib.h>
#include "InputFlusher.h"

int main(int argc, char* argv[])
{
    printf("Bienvenido al Mundo Pokemon!\n");
    printf("Cuantas ciudades tendra esta region?");
    fflush(stdout);
    char seleccion = getc(stdin);
    

    printf("Cuantos gimnasios tendra esta region?");
    fflush(stdout);
    char seleccion2;
    inputFlusher(seleccion2);
    seleccion2 = getc(stdin);

    return 0;
}