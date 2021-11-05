#include <stdlib.h>
#include <stdio.h>

typedef struct Ciudad
{
    char id;
    char instalaciones[5];
    char guaridaEn;
    struct Ciudad *sig;Ciudad *cabeza;int longitud;
}Ciudad;

typedef struct Pokemon
{
    int hp;
    char tipo;
    char nivel;
    struct Pokemon *sig;Pokemon *cabeza;int longitud;
    
} Pokemon;

typedef struct PokemonPC
{
    int hp;
    char tipo;
    char nivel;
    struct PokemonPC *sig;PokemonPC *cabeza;int longitud;
    
}PokemonPC;


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
