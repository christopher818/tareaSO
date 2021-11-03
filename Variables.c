#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include "Variables.h"

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
    struct Ciudad *sig;Ciudad *cabeza;
}Ciudad;

Ciudad *listaCiudad(Ciudad *Lista){
    Lista = NULL;
    Ciudad *cabeza;
    return Lista;
}

Ciudad *agregarCiudad(Ciudad *Lista){
    Ciudad *nuevaCiudad, *auxiliarCiudad;
    nuevaCiudad = (Ciudad*)malloc(sizeof(Ciudad));
    strncpy(nuevaCiudad->id);
    strncpy(nuevaCiudad->instalaciones,5);
    strncpy(nuevaCiudad->guaridaEn);
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
    struct Pokemon *sig; Pokemon *cabeza;
    
} Pokemon;

Pokemon *listaPokemon6(Pokemon *ListaPokemones){
    ListaPokemones = NULL;
    Pokemon *cabeza;
    return ListaPokemones;
}

Pokemon *agregarPokemon(Pokemon *listaPokemon6){
    Pokemon *nuevoPokemon, *auxiliarPokemon;
    nuevoPokemon = (Pokemon*)malloc(sizeof(Pokemon));
    strncpy(nuevoPokemon->hp);
    strncpy(nuevoPokemon->tipo);
    strncpy(nuevoPokemon->nivel);
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
    struct PokemonPC *sig;PokemonPC *cabeza;
    
}PokemonPC;

PokemonPC *listaPokemonPC(PokemonPC *ListaPokemonesPC){
    ListaPokemonesPC = NULL;
    PokemonPC *cabeza;
    return ListaPokemonesPC;
}

PokemonPC *agregarPokemonPC(PokemonPC *listaPokemonPC){
    PokemonPC *nuevoPokemonPC, *auxiliarPokemonPC;
    nuevoPokemonPC = (PokemonPC*)malloc(sizeof(PokemonPC));
    strncpy(nuevoPokemonPC->hp);
    strncpy(nuevoPokemonPC->nivel);
    strncpy(nuevoPokemonPC->tipo);
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

void DestruirNodoPokemon6(Pokemon *listaPokemon6){
    free(listaPokemon6);
}

void DestruirNodoPokemonPC(PokemonPC *listaPokemonPC){
    free(listaPokemonPC);
}

void PonerPokemonPrimero(Pokemon *listaPokemon6, Pokemon *ListaPokemones){
    Pokemon *nuevoPokemon = agregarPokemon(listaPokemon6);
    nuevoPokemon->sig = listaPokemon6->cabeza;
    listaPokemon6->cabeza = nuevoPokemon;
}

void PonerPokemonUltimo(Pokemon *listaPokemon6, Pokemon *ListaPokemones){
    Pokemon *nuevoPokemon = agregarPokemon(listaPokemon6);
    if(listaPokemon6->cabeza == NULL){
        listaPokemon6->cabeza = nuevoPokemon;
    }else{
        Pokemon *puntero = listaPokemon6->cabeza;
        while (puntero->sig)
        {
            puntero = puntero->sig;
        }
        puntero->sig = nuevoPokemon;
    }

}

void ColocarPokemonDespuesDe(int n,Pokemon *listaPokemon6, Pokemon *ListaPokemones){
    Pokemon *nuevoPokemon = agregarPokemon(listaPokemon6);
    if(listaPokemon6->cabeza == NULL){
        listaPokemon6->cabeza = nuevoPokemon;
    }else{
        Pokemon *puntero = listaPokemon6->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->sig)
        {
            puntero = puntero->sig;
            posicion++;
        }
        nuevoPokemon->sig = puntero->sig;
        puntero->sig = nuevoPokemon;
    }
}



int main()
{

}