#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"

#ifndef generadorPokemon_c
#define generadorPokemon_c

/*Funcion que genera un pokemon aleatorio para colocarlo al final de una lista;
como al tomar el primer pokemon, al encontrar un pokemon salvaje, al entrar a un gimnasio, guarida, centro de entrenamiento o la Liga 
    Lista - apuntador a la Lista de pokemon que se va a añadir
    hp - int que si es diferente de 0, se añade el pokemon con esa cantidad de hp, si es 0, se añade con hp al maximo
    nivel - char que guarda el nivel maximo del pokemon
    tipoDelPokemon - char que guarda el tipo del pokemon, si es 0, se selecciona un tipo aleatorio, los tipos son:
        1 - Tipo Fuego
        2 - Tipo Agua
        3 - Tipo Grama
        4 - Tipo Volador
        5 - Tipo roca
*/
Pokemon* GenerarPokemon(int hp, char nivel, char tipoDelPokemon)
{
    if( hp == 0 )
    {
        int hp = (int)(4 * nivel);
    }
    if (tipoDelPokemon == 0)
    {
        time_t seed;
        char random;  
        srand(time(NULL));
        random = rand();

        tipoDelPokemon = (random % 4) + 1;
    }

    Pokemon *nuevoPokemon;
    nuevoPokemon = malloc(sizeof(Pokemon));
    nuevoPokemon->hp = hp;
    nuevoPokemon->tipo = tipoDelPokemon;
    nuevoPokemon->nivel = nivel;    
    nuevoPokemon ->sig = NULL;
    
    return nuevoPokemon;
}

#endif