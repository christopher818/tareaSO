#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "InputFlusher.h"

/*Funcion que sirve para tomar comandos en el juego.
Si el jugador escribe "apagar", deber hacer una llamada a "exit()" y cerrar el juego.
entrada - Direccion de memoria para tomar la entrada del jugador.
    -Si es "apagar", la funcion envia un mensaje de apagado y usa la funcion 'exit' para salir del programa.
    -Si no, la funcion retorna 0.
*/
char EntradaDeComando(char* entrada)
{   
    printf("Entry;");
    inputFlusher(entrada);
    printf("a");
    scanf("%s", entrada);
    printf("b");
    if(strcmp(entrada, "apagar") == 0)
    {
        printf("Apagando juego.\n");
        exit(0);
    }
    else
    {
        printf("returning;");
        return 0;
    }
    
    return 1;
}