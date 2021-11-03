#include <stdlib.h>
#include <stdio.h>

typedef struct Ciudad
{
    char id;
    char instalaciones[5];
    char guaridaEn;
    struct Ciudad *sig;Ciudad *cabeza;
}Ciudad;

typedef struct Pokemon
{
    int hp;
    char tipo;
    char nivel;
    struct Pokemon *sig;Pokemon *cabeza;
    
} Pokemon;

typedef struct PokemonPC
{
    int hp;
    char tipo;
    char nivel;
    struct PokemonPC *sig;PokemonPC *cabeza;
    
}PokemonPC;