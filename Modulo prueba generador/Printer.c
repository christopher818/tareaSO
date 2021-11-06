#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Apagado.h"
#include "GeneradorCiudad.h"
#include "GeneradorPokemon.h"
#include "Variables.h"


int ImprimirCiudades(Ciudad* Lista)
{
    Ciudad imprimir = *Lista->cabeza;
    do
    {
        printf("%d\n", imprimir.id);
        printf("Centro pok: %d\n", imprimir.instalaciones[0]);
        printf("Tienda: %d\n", imprimir.instalaciones[1]);
        printf("Gimnasio: %d\n", imprimir.instalaciones[2]);
        printf("C. Entre: %d\n", imprimir.instalaciones[3]);
        printf("Guarida: %d\n", imprimir.instalaciones[4]);
        printf("Guarida en: %d", imprimir.guaridaEn);
        printf("\n");
    }while(imprimir.sig != NULL);
}

int ImprimirPokemones(Pokemon* Lista)
{
    Pokemon imprimir = *Lista->cabeza;
    do
    {
        printf("%c\n", imprimir.tipo);
        printf("%d\n", imprimir.nivel);
        printf("\n");
    }while(imprimir.sig != NULL);
}

int main(int argc, char* argv[])
{
    pokemonEnJugador = calloc(6,sizeof(Pokemon));

    printf("Diga numero de ciudades");
    char* seleccion1;
    EntradaDeComando(seleccion1);
    char selbuff1 = memccpy(selbuff1,seleccion1, 1, 1);

    printf("Diga numero de gimnasios maximo");
    char* seleccion2;
    char selbuff2;
    do
    {
        EntradaDeComando(seleccion2);
        selbuff2 = memccpy(selbuff2,seleccion2, 1, 1);

        if (selbuff2 > selbuff1)
        {
            printf("ERROR: Deben ser menos gimnasios que ciudades!\n");
        }
    } while(selbuff2 > selbuff1);

    GenerarCiudades(ciudades, selbuff1, selbuff2);

    agregarPokemon(pokemonEnJugador, 0, 1, 5);

    ImprimirCiudades(ciudades);
    ImprimirPokemones(pokemonEnJugador);
    return 0;
}