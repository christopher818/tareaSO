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
    struct Ciudad *sig;Ciudad *cabeza; int longitud;
}Ciudad;

Ciudad *listaCiudad(Ciudad *Lista){
    Lista = NULL;
    Ciudad *cabeza;
    int longitud;
    return Lista;
}

Ciudad *agregarCiudad(Ciudad *Lista, char id, char instalaciones[5], char guaridaEn){
    Ciudad *nuevaCiudad, *auxiliarCiudad;
    nuevaCiudad = (Ciudad*)malloc(sizeof(Ciudad));
    nuevaCiudad->id = id ;
    nuevaCiudad->instalaciones[5] = instalaciones[5];
    nuevaCiudad->guaridaEn = guaridaEn;
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
    struct Pokemon *sig; Pokemon *cabeza;int longitud;
    
} Pokemon;

Pokemon *listaPokemon6(Pokemon *ListaPokemones){
    ListaPokemones = NULL;
    Pokemon *cabeza;
    int longitud;
    return ListaPokemones;
}

Pokemon *agregarPokemon(Pokemon *listaPokemon6, int hp, char tipo, char nivel){
    Pokemon *nuevoPokemon, *auxiliarPokemon;
    nuevoPokemon = (Pokemon*)malloc(sizeof(Pokemon));
    nuevoPokemon->hp = hp;
    nuevoPokemon->tipo = tipo;
    nuevoPokemon->nivel = nivel;
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
    struct PokemonPC *sig;PokemonPC *cabeza;int longitud;
    
}PokemonPC;

PokemonPC *listaPokemonPC(PokemonPC *ListaPokemonesPC){
    ListaPokemonesPC = NULL;
    PokemonPC *cabeza;
    int longitud;
    return ListaPokemonesPC;
}

PokemonPC *agregarPokemonPC(PokemonPC *listaPokemonPC, int hp, char tipo, char nivel){
    PokemonPC *nuevoPokemonPC, *auxiliarPokemonPC;
    nuevoPokemonPC = (PokemonPC*)malloc(sizeof(PokemonPC));
    nuevoPokemonPC->hp = hp;
    nuevoPokemonPC->nivel = nivel;
    nuevoPokemonPC->tipo = tipo;
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


// Funciones para manejar las listas enlazadas 

void DestruirNodoPokemon6(Pokemon *listaPokemon6){
    free(listaPokemon6);
}

void DestruirNodoPokemonPC(PokemonPC *listaPokemonPC){
    free(listaPokemonPC);
}

void PonerPokemonPrimero(Pokemon *listaPokemon6, Pokemon *ListaPokemones, int hp, char tipo, char nivel){
    Pokemon *nuevoPokemon = agregarPokemon(listaPokemon6, hp, tipo, nivel);
    nuevoPokemon->sig = listaPokemon6->cabeza;
    listaPokemon6->cabeza = nuevoPokemon;
    listaPokemon6->longitud++;
}

void PonerPokemonUltimo(Pokemon *listaPokemon6,  int hp, char tipo, char nivel){
    Pokemon *nuevoPokemon = agregarPokemon(listaPokemon6, hp, tipo, nivel);
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
    listaPokemon6->longitud++;

}

void ColocarPokemonDespuesDe(int n,Pokemon *listaPokemon6,  int hp, char tipo, char nivel){
    Pokemon *nuevoPokemon = agregarPokemon(listaPokemon6, hp, tipo, nivel);
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
    listaPokemon6->longitud++;
}

Pokemon *ObtenerPokemonPC(int n, Pokemon *listaPokemonPC){
    if (listaPokemonPC->cabeza == NULL){
        return NULL;
    }else {
        PokemonPC *puntero = listaPokemonPC->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->sig)
        {
            puntero = puntero->sig;
            posicion++;
        }
        if (posicion != n)
        {
            return NULL;
        }else{
            return &puntero->tipo;
        }
        
    }
}

int ContarCiudad(Ciudad *listaCiudad){
    return listaCiudad->longitud;
    
}

int ContarPokemon6(Pokemon *listaPokemon6){
    return listaPokemon6->longitud;
    
}

int ContarPokemonPC(PokemonPC *listaPokemonPC){
    return listaPokemonPC->longitud;
    
}

int EstavacioPokemon6(Pokemon *listaPokemon6){
    return listaPokemon6->cabeza == NULL;
}

int EstavacioPokemonPC(Pokemon *listaPokemonPC){
    return listaPokemonPC->cabeza == NULL;
}

void eliminarPrincipioPokemon6(Pokemon *listaPokemon6){
    if (listaPokemon6->cabeza){
        Pokemon *eliminado = listaPokemon6->cabeza;
        listaPokemon6->cabeza = listaPokemon6->cabeza->sig;
        DestruirNodoPokemon6(eliminado);
        listaPokemon6->longitud--;
    }
}

void eliminarUltimoPokemon6(Pokemon *listaPokemon6){
    if (listaPokemon6->cabeza){
        if (listaPokemon6->cabeza->sig){
            Pokemon *puntero = listaPokemon6->cabeza;
            while(puntero->sig->sig){
                puntero = puntero->sig;
            }
            Pokemon *eliminado = puntero->sig;
            puntero->sig = NULL;
            DestruirNodoPokemon6(eliminado);
            listaPokemon6->longitud--;
        }else{
            Pokemon *eliminado = listaPokemon6->cabeza;
            listaPokemon6->cabeza = NULL;
            DestruirNodoPokemon6(eliminado);
            listaPokemon6->longitud--;
        }
    }
}

void eliminarPokemon(int n, Pokemon *listaPokemon6){
    if (listaPokemon6->cabeza){
        if (n == 0){
            Pokemon *eliminado = listaPokemon6->cabeza;
            listaPokemon6->cabeza = listaPokemon6->cabeza->sig;
            DestruirNodoPokemon6(eliminado);
            listaPokemon6->longitud--;
        }else if(n < listaPokemon6->longitud){
            Pokemon *puntero = listaPokemon6->cabeza;
            int posicion = 0;
            while (posicion < (n-1)){
                puntero = puntero ->sig;
                posicion++;
            }
            Pokemon *eliminado = puntero->sig;
            puntero->sig = eliminado->sig;
            DestruirNodoPokemon6(eliminado);
            listaPokemon6->longitud--;
        }
    }
}


int main()
{

}