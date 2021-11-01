#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

/* Estructura que representa a las ciudades del juego 
id - Numero de la ciudad
Instalaciones - arreglo que guarda que elementos existen en la ciudad.
    Se guardan en flags dependiendo del indice del arreglo:
    0 - es 1 si hay un centro pokemon
    1 - */
struct Ciudad
{
    char id;
    char instalaciones[6];
    char guaridaEn;
};

struct Pokemon
{
    int hp;
    char tipo;
    char nivel;
};

int GenerarCiudad()
{
    struct Ciudad* nueva = malloc(6); 
}

int GenerarPokemon(char nuevoTipo, char nuevoNivel)
{
    struct Pokemon* pkmn = malloc(6);
    
}


int main()
{

}