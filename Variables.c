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
typedef struct Ciudad
{
    char id;
    char instalaciones[5];
    char guaridaEn;
    struct Ciudad *sig;
}Ciudad;

Ciudad *listaCiudad(Ciudad *Lista){
    Lista = NULL;
    return Lista;
}

Ciudad *agregarCiudad(Ciudad *Lista, char *nombre){
    Ciudad *nuevaCiudad, *auxiliarCiudad;
    nuevaCiudad = (Ciudad*)malloc(sizeof(Ciudad));
    nuevaCiudad->id = nombre;
    nuevaCiudad->sig = NULL;
    if (Lista == NULL){
        Lista = nuevaCiudad;
    }else{
        auxiliarCiudad = Lista;
        while (auxiliarCiudad != NULL)
        {
            auxiliarCiudad ->sig;
            
        }
        auxiliarCiudad ->sig = nuevaCiudad;
    }
    return Lista;
}

typedef struct Pokemon
{
    int hp;
    char tipo;
    char nivel;
    struct Pokemon *sig;
    
} Pokemon;

Pokemon *listaPokemon6(Pokemon *ListaPokemones){
    ListaPokemones = NULL;
    return ListaPokemones;
}

Pokemon *agregarPokemon(Pokemon *listaPokemon6, char *nombre){
    Pokemon *nuevoPokemon, *auxiliarPokemon;
    nuevoPokemon = (Pokemon*)malloc(sizeof(Pokemon));
    nuevoPokemon ->tipo = nombre;
    nuevoPokemon ->sig = NULL;
    if (listaPokemon6 == NULL){
        listaPokemon6 = nuevoPokemon;
    }else{
        auxiliarPokemon = listaPokemon6;
        while (auxiliarPokemon != NULL)
        {
            auxiliarPokemon ->sig;
        }
        auxiliarPokemon ->sig = nuevoPokemon;
    }
    return listaPokemon6;
}

typedef struct PokemonPC
{
    int hp;
    char tipo;
    char nivel;
    struct PokemonPC *sig;
    
}PokemonPC;

PokemonPC *listaPokemonPC(PokemonPC *ListaPokemonesPC){
    ListaPokemonesPC = NULL;
    return ListaPokemonesPC;
}

PokemonPC *agregarPokemonPC(PokemonPC *listaPokemonPC, char *nombre){
    PokemonPC *nuevoPokemonPC, *auxiliarPokemonPC;
    nuevoPokemonPC = (PokemonPC*)malloc(sizeof(PokemonPC));
    nuevoPokemonPC ->tipo = nombre;
    nuevoPokemonPC ->sig = NULL;
    if (listaPokemonPC == NULL){
        listaPokemonPC = nuevoPokemonPC;
    }else{
        auxiliarPokemonPC = listaPokemonPC;
        while (auxiliarPokemonPC != NULL)
        {
            auxiliarPokemonPC ->sig;
        }
        auxiliarPokemonPC ->sig = nuevoPokemonPC;
    }
    return listaPokemonPC;
}



int main()
{

}