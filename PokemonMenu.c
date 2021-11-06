#include <stdio.h>
#include <stdlib.h>
#include "InputFlusher.h"
#include "Apagado.h"
#include "Variables.h"

int main(int argc, char* argv[])
{
    printf("Bienvenido al Mundo Pokemon!\n");
    printf("Cuantas ciudades tendra esta region?");
    fflush(stdout);
    char* seleccion;
    EntradaDeComando(seleccion);

    printf("Cuantos gimnasios tendra esta region?");
    fflush(stdout);
    char* seleccion2;
    EntradaDeComando(seleccion2);
    
    

    

    return 0;
}