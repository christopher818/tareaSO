#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "Variables.h"
#include "GeneradorPokemon.h"
#include "Apagado.h"

// Funcion que sirve para ejecutar las batallas Pokemon contra la computadora.


void BatallaPokemon(char NivelDeBatalla, char TipoDelPokemonBatalla){
    Pokemon *pokemonLucha = GenerarPokemon(0, NivelDeBatalla, TipoDelPokemonBatalla);
    Pokemon *pokemonJugador = pokemonEnJugador->cabeza;
    printf("%s\n", pokemonLucha->tipo);
    printf("%d\n", pokemonJugador->hp);
    
    
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

    if (strcmp(comando, "1") == 0 || strcmp(comando,"2") == 0 || strcmp(comando,"3") == 0 || strcmp(comando,"4") == 0){

        strcpy(comando, opciones );
        switch (opciones){
        case '1':
            /* Luchar */
            Luchar(pokemonLucha);
            break;
        case '2':
            /* Lanzar Pokeball */
            printf("Atrapaste el Pokemon salvaje\n");
            if (pokemonEnJugador->longitud < 7 ){
                PonerPokemonUltimo(pokemonEnJugador, pokemonLucha->hp, pokemonLucha->tipo, pokemonLucha->nivel);
                exit(0);
            }else{
                PonerPokemonUltimoPC(pokemonEnJugador, pokemonLucha->hp, pokemonLucha->tipo, pokemonLucha->nivel);
                exit(0);
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
    }
}   
/*
tipo- indica el tipo del pokemon:
    1 - Tipo Fuego
    2 - Tipo Agua
    3 - Tipo Planta
    4 - Tipo Volador
    5 - Tipo Roca

*/
void Luchar(Pokemon *pokemonLucha){
    int daño; 
    int ataque = 1;
    int turno = 1;
    while (ataque == 1) {
    if (turno == 1){
    switch (pokemonEnJugador->cabeza->tipo){

        // El tipo del pokemon del jugador es Fuego
        case '1':
            // El tipo del pokemon contra el que lucha es planta
            if (pokemonLucha->tipo == '3'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipos contra los que fuego es debil, agua y roca
            }else if (pokemonLucha->tipo == '2' || pokemonLucha ->tipo == '5'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo contra los que fuego es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra fuego 
                daño = pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;
            }
            break;

        // El tipo del pokemon del jugador es Agua
        case '2':
                // El tipo del pokemon contra el que lucha es fuego o roca
            if (pokemonLucha->tipo == '1' || pokemonLucha->tipo == '5'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo donde agua es debil, planta 
            }else if (pokemonLucha->tipo == '3'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo contra lo que agua es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra agua 
                daño = pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;
            }

            break;
        
        // El tipo del pokemon del jugador es Planta
        case '3':
            // El tipo del pokemon contra el que lucha es agua o roca
            if (pokemonLucha->tipo == '2' || pokemonLucha->tipo == '5'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipos donde planta es debil, fuego o volador 
            }else if (pokemonLucha->tipo == '1' || pokemonLucha ->tipo == '4'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo contra lo que planta es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra planta
                daño = pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;
            }
            break;
        
        // El tipo el pokemon del jugador es Volador
        case '4':
            // El tipo del pokemon contra el que lucha es planta
            if (pokemonLucha->tipo == '3'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo contra los que volador es debil, Roca
            }else if (pokemonLucha ->tipo == '5'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo contra los que volador es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra volador
                daño = pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;
            }
            break;
        
        // El tipo del pokemon del jugador es Roca
        case '5':
            // El tipo del pokemon contra el que lucha es fuego o Volador
            if (pokemonLucha->tipo == '1' || pokemonLucha->tipo == '4'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipos donde Roca es debil, agua y planta 
            }else if (pokemonLucha->tipo == '2' || pokemonLucha ->tipo == '3'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;

            // tipo contra los Roca es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra Roca 
                daño = pokemonEnJugador->nivel;
                //se le resta el daño al pokemon rival
                pokemonLucha->hp = pokemonLucha->hp - daño;
                // si la vida del pokemon rival llega a 0 o es menor, se gana la partida 
                if (pokemonLucha->hp <= 0){
                    GanadorDeBatalla();
                    // Sube de nivel el pokemon ganador 
                    pokemonEnJugador->cabeza->nivel++;
                    // El pokemon ganador gana 4 puntos de salud por subir de nivel
                    pokemonEnJugador->cabeza->hp = 4 + pokemonEnJugador->cabeza->hp;
                }
                // se le la el turno a la computadora
                turno = 2;
            }
            break;
        }

    // Turno de la computadora, turno 2 
    }else {
        switch (pokemonLucha->cabeza->tipo){

        // El tipo del pokemon de la computadora es Fuego
        case '1':
            // El tipo del pokemon contra el que lucha es planta
            if (pokemonEnJugador->tipo == '3'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador
                turno = 1;

            // tipos contra los que fuego es debil, agua y roca
            }else if (pokemonEnJugador->tipo == '2' || pokemonEnJugador ->tipo == '5'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
        
                }
                // se le la el turno al jugador
                turno = 1;

            // tipo contra los que fuego es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra fuego 
                daño = pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                }
                // se le la el turno al jugador
                turno = 1;
            }
            break;

        // El tipo del pokemon de la computadora es Agua
        case '2':
                // El tipo del pokemon contra el que lucha es fuego o roca
            if (pokemonEnJugador->tipo == '1' || pokemonEnJugador->tipo == '5'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador
                turno = 1;

            // tipo donde agua es debil, planta 
            }else if (pokemonEnJugador->tipo == '3'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador 
                turno = 1;

            // tipo contra lo que agua es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra agua 
                daño = pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador 
                turno = 1;
            }

            break;
        
        // El tipo del pokemon de la computadora es Planta
        case '3':
            // El tipo del pokemon contra el que lucha es agua o roca
            if (pokemonEnJugador->tipo == '2' || pokemonEnJugador->tipo == '5'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonLucha->nivel;
                //se le resta el daño al pokemon al jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador  llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                
                }
                // se le la el turno al jugador
                turno = 1;

            // tipos donde planta es debil, fuego o volador 
            }else if (pokemonEnJugador->tipo == '1' || pokemonEnJugador ->tipo == '4'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonEnJugador->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador 
                turno = 1;

            // tipo contra lo que planta es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra planta
                daño = pokemonLucha->nivel;
                //se le resta el daño al pokemon rival
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador  llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador 
                turno = 1;
            }
            break;
        
        // El tipo el pokemon de la computadora es Volador
        case '4':
            // El tipo del pokemon contra el que lucha es planta
            if (pokemonEnJugador->tipo == '3'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                } 
                // se le la el turno al jugador 
                turno = 1;

            // tipo contra los que volador es debil, Roca
            }else if (pokemonEnJugador ->tipo == '5'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                }  
                // se le la el turno al jugador 
                turno = 1;

            // tipo contra los que volador es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra volador
                daño = pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                
                }
                // se le la el turno al jugador 
                turno = 1;
            }
            break;
        
        // El tipo del pokemon de la computadora es Roca
        case '5':
            // El tipo del pokemon contra el que lucha es fuego o Volador
            if (pokemonEnJugador->tipo == '1' || pokemonEnJugador->tipo == '4'){
                //daño contra el tipo contra el que es fuerte
                daño = 2 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador
                turno = 1;

            // tipos donde Roca es debil, agua y planta 
            }else if (pokemonEnJugador->tipo == '2' || pokemonEnJugador ->tipo == '3'){
                //daño contra el tipo contra el que es debil
                daño = 0,5 * pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del juagdor llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador
                turno = 1;

            // tipo contra los Roca es neutro
            }else {
                // daño contras los tipo que no son debil ni fuerte contra Roca 
                daño = pokemonLucha->nivel;
                //se le resta el daño al pokemon del jugador
                pokemonEnJugador->hp = pokemonEnJugador->hp - daño;
                // si la vida del pokemon del jugador llega a 0 o es menor, se gana la partida 
                if (pokemonEnJugador->hp <= 0){
                    GanadorDeBatalla();
                    
                }
                // se le la el turno al jugador 
                turno = 1;
            }
            break;
        }
    }
    } 
}


void GanadorDeBatalla(){
    int turno = 1;
    if (turno == 1){
        printf("Gano la partida \n");
        exit(0);
    }else{
        printf("Gano la partida el rival\n");
        exit(0);
    }
}