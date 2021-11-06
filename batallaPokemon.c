#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "Variables.h"
#include "GeneradorPokemon.h"
#include "Apagado.h"

// Funcion que sirve para ejecutar las batallas Pokemon contra la computadora.

int turno = 1;

void BatallaPokemon(char NivelDeBatalla, char TipoDelPokemonBatalla){
    Pokemon *pokemonLucha = GenerarPokemon(0, NivelDeBatalla, TipoDelPokemonBatalla);
    Pokemon *pokemonJugador = pokemonEnJugador->cabeza;
    printf("%s\n", pokemonLucha->tipo);
    printf("%d\n", pokemonJugador->hp);
    int daño; 
    int ataque;
    
    printf("Opciones de Batalla\n");
    printf("1.- Luchar\n");
    printf("2.- Lanzar Pokeball\n");
    printf("3.- Cambiar Pokemon\n");
    printf("4.- Huir\n");

    printf("Introduce el numero del comando a ejecutar\n");
    printf("Ejemplo, si quieres luchar coloca el numero 1\n");
    char* comando;
    char opciones;
    EntradaDeComando(comando);
    if (strcmp(comando, "1") == 0 || strcmp(comando,"2") == 0 || strcmp(comando,"3") == 0
    || strcmp(comando,"4") == 0){
        strcpy(comando, opciones );
    }

    if (turno == 1){

        switch (opciones)
        {
        case '1':
            /* Luchar */

            turno = 2;
            break;
        case '2':
            /* Lanzar Pokeball */
            printf("Atrapaste el Pokemon salvaje\n");
            if (->longitud ){

            }
            break;
        case '3':
            /* Cambiar Pokemon */
            break;
        case '4':
            /* Huir */

            printf("Huiste de la Batalla\n");
            exit(0);
            break;
    
        default:
            printf("No coloco una opcion valida, intente de nuevo\n");
            break;
        }
    }else {

        switch ('1')
        {
        case '1':
            /* Luchar */

            turno = 1;
            break;
        case '3':
            /* Cambiar Pokemon */
            break;
    
        default:
            printf("No coloco una opcion valida, intente de nuevo\n");
            break;
        }
    }
}

void GanadorDeBatalla(){
    if (turno == 1){
        printf("%s Gano la partida \n", pokemonEnJugador->cabeza->tipo);
        exit(0);
    }else{
        printf("Gano la partida el rival\n");
        exit(0);
    }
}