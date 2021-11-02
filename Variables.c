#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

/* Estructura que representa a las ciudades del juego 
id - Numero de la ciudad
Instalaciones - arreglo que guarda que elementos existen en la ciudad.
    Se guardan en flags dependiendo del indice del arreglo:
    0 - es 1 si hay un centro pokemon
    1 - es 1 si hay una tienda
    2 - es 1 si hay un gimnasio, es 2 si el gimnasio esta bloqueado
    3 - es 1 si hay un centro de entrenamiento
    4 - es 1 si hay una guarida*/
struct Ciudad
{
    char id;
    char instalaciones[5];
    char guaridaEn;
};

struct Pokemon
{
    int hp;
    char tipo;
    char nivel;
};


int main()
{

}