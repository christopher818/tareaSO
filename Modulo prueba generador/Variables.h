#ifndef variables
#define variables

#include <stdlib.h>
#include <stdio.h>

/* Estructura que representa a las ciudades del juego 
id - Numero de la ciudad
Instalaciones - arreglo que guarda que elementos existen en la ciudad.
    Se guardan en flags dependiendo del indice del arreglo:
    0 - es 1 si hay un centro pokemon
    1 - es 1 si hay una tienda
    2 - es 1 si hay un gimnasio, es 2 si el gimnasio esta bloqueado
    3 - es 1 si hay un centro de entrenamiento
    4 - es 1 si hay una guarida*/

typedef struct CiudadStruct
{
    struct CiudadStruct *sig;
    struct CiudadStruct *cabeza;
    int longitud;
    char id;
    char instalaciones[5];
    char guaridaEn;
}Ciudad;

Ciudad *listaCiudad(Ciudad *Lista);

Ciudad *agregarCiudad(Ciudad *Lista, char id, char instalaciones[5], char guaridaEn);

typedef struct Pokemon
{
    struct Pokemon *sig;
    struct Pokemon *cabeza;
    int longitud;
    int hp;
    char tipo;
    char nivel;
    
} Pokemon;

Pokemon *listaPokemon6(Pokemon *ListaPokemones);

Pokemon *agregarPokemon(Pokemon *listaPokemon6, int hp, char tipo, char nivel);

/*
tipo- indica el tipo del pokemon:
    1 - Tipo Fuego
    2 - Tipo Agua
    3 - Tipo Grama
    4 - Tipo Volador
    5 - Tipo roca

*/
typedef struct PokemonPC
{
    struct PokemonPC *sig;
    struct PokemonPC *cabeza;
    int longitud;
    int hp;
    char tipo;
    char nivel;    
}PokemonPC;

PokemonPC *listaPokemonPC(PokemonPC *ListaPokemonesPC);

PokemonPC *agregarPokemonPC(PokemonPC *listaPokemonPC, int hp, char tipo, char nivel);


// Funciones que estan en el archivo Variable.c

void DestruirNodoPokemon6(Pokemon *listaPokemon6);

void DestruirNodoPokemonPC(PokemonPC *listaPokemonPC);

void PonerPokemonPrimero(Pokemon *listaPokemon6, int hp, char tipo, char nivel);

void PonerPokemonPrimeroPC(Pokemon *listaPokemonPC, int hp, char tipo, char nivel);

void PonerPokemonUltimo(Pokemon *listaPokemon6,  int hp, char tipo, char nivel);

void PonerPokemonUltimoPC(Pokemon *listaPokemonPC,  int hp, char tipo, char nivel);

void ColocarPokemonDespuesDe(int n,Pokemon *listaPokemon6,  int hp, char tipo, char nivel);

void ColocarPokemonPCDespuesDe(int n,Pokemon *listaPokemonPC,  int hp, char tipo, char nivel);

Pokemon *ObtenerPokemonPC(int n, Pokemon *listaPokemonPC);

Pokemon *ObtenerPokemon6(int n, Pokemon *listaPokemon6);

int ContarCiudad(Ciudad *listaCiudad);

int ContarPokemon6(Pokemon *listaPokemon6);

int ContarPokemonPC(PokemonPC *listaPokemonPC);

int EstavacioPokemon6(Pokemon *listaPokemon6);

int EstavacioPokemonPC(Pokemon *listaPokemonPC);

void eliminarPrincipioPokemon6(Pokemon *listaPokemon6);

void eliminarPrincipioPokemonPC(Pokemon *listaPokemonPC);

void eliminarUltimoPokemon6(Pokemon *listaPokemon6);

void eliminarUltimoPokemonPC(Pokemon *listaPokemonPC);

void eliminarPokemon(int n, Pokemon *listaPokemon6);

void eliminarPokemonPC(int n, Pokemon *listaPokemonPC);

Pokemon* pokemonEnJugador;
Ciudad* ciudades;
Pokemon* pokemonEnPC;
#endif
