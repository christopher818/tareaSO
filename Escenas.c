#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Apagado.h"
#include "InputFlusher.h"
#include "Variables.h"

char salioDeCiudadNatal = 1;

int Comienzo()
{
    char* entrada;
    printf("Es hora de comenzar tu aventura, ve al laboratorio para elegir tu primer pokemon! \n");
    printf("Escribe 'ir al laboratorio' para ir hacia el laboratorio.\n");
    inputFlusher(entrada);
    EntradaDeComando(entrada);

    while(strcmp(entrada,"ir al laboratorio") != 0)
    {
        printf("ERROR: Intenta escribir 'ir al laboratorio'\n");
        inputFlusher(entrada);
        EntradaDeComando(entrada);
    }

    printf("Bienvenido al Laboratorio! Para comenzar tu aventura, necesitas tomar un Pokemon.\n");
    printf("Hay tres pokemon de tipos diferentes: Fuego, Grama y Agua\n");
    printf("Elige uno de los pokemon:\n");
    printf("escribe 'elegir fuego' para tomar al pokemon de tipo Fuego.\n");
    printf("escribe 'elegir grama' para tomar al pokemon de tipo Grama.\n");
    printf("escribe 'elegir agua' para tomar al pokemon de tipo Agua.\n");
    EntradaDeComando(entrada);

    while(strcmp(entrada,"elegir fuego") != 0 
    || strcmp(entrada,"elegir grama") != 0 || strcmp(entrada,"elegir agua") != 0)
    {
        printf("ERROR: Intenta otra vez");
        printf("escribe 'elegir fuego' para tomar al pokemon de tipo Fuego.\n");
        printf("escribe 'elegir grama' para tomar al pokemon de tipo Grama.\n");
        printf("escribe 'elegir agua' para tomar al pokemon de tipo Agua.\n");
        EntradaDeComando(entrada);
    }

    if(strcmp(entrada,"elegir fuego") == 0)
    {
        printf("Has elegido el pokemon de tipo fuego!.\n");
    }
    if (strcmp(entrada,"elegir grama") == 0)
    {
        printf("Has elegido el pokemon de tipo grama!.\n");
    }
    if (strcmp(entrada,"elegir agua") == 0)
    {
        printf("Has elegido el pokemon de tipo agua!.\n");
    }

    printf("Ahora que tienes un pokemon, puedes comenzar tu aventura.\n");
    printf("Puedes escribir 'ir a casa' para regresar a tu casa...\n");
    printf("O escribe 'avanzar' para embarcarte y comenzar!\n");
    EntradaDeComando(entrada);

    do
    {
        printf("Puedes escribir 'ir a casa' para regresar a tu casa...\n");
        printf("O escribe 'avanzar' para embarcarte y comenzar!\n");
        
        if(strcmp(entrada, "avanzar") == 0)
        {
            printf("Te diriges a la ruta 1 para comenzar tu viaje!\n");
            salioDeCiudadNatal = 0;
        }
        if(strcmp(entrada, "ir a casa") == 0)
        {
            printf("Regresas a tu casa.\n");
            CentroPokemon(1);

        }
        if (strcmp(entrada, "avanzar") != 0 && strcmp(entrada, "ir a casa") != 0)
        {
            printf("ERROR: comando invalido, intenta otra vez.\n");
        }
    } while(strcmp(entrada, "avanzar") != 0 && strcmp(entrada, "ir a casa") != 0);
    
}

int CiudadNatal()
{
    char* entrada;
    printf("Bienvenido de vuelta a tu hogar.\n");
    printf("Tu casa sigue allí, puedes entrar con 'ir a casa'.\n");
    printf("O puedes 'avanzar' a la ruta 1 para seguir tu camino.\n");
    EntradaDeComando(entrada);    
}

int Ciudad(char* pueblo)
{
    //colocar codigo de la ciudad a la que se llegó aqui
    char* nombre, entrada;
    printf("Bienvenido a la ciudad %s.\n", nombre);

    while (0==0)
    {
        printf("Elije si va a 'avanzar' o si va a entrar en algun edificio de la ciudad.\n");
        EntradaDeComando(entrada);

        if(strcmp(entrada, "ir al centro") == 0)
        {
            printf("Encontraste un centro pokemon y entras.\n");
            CentroPokemon(0);
        }
        if (strcmp(entrada, "ir a la tienda") == 0)
        {
            printf("Encontraste una tienda y entras.\n");
            tienda();
        }
        if (strcmp(entrada, "ir al gimnasio") == 0)
        {
            char placeholder;
            printf("Encontraste un gimnasio y entras!\n");
            Gimnasio(placeholder);
        }
        if (strcmp(entrada, "ir al centro de entrenamiento")== 0)
        {
            printf("Encontraste un centro de entrenamiento y entras.\n");
            CentroEntrenamiento();
        }
        if (strcmp(entrada, "buscar guarida secreta") == 0)
        {
            /* if(Ciudad->instalaciones[] == 1)
            {
                printf("Encontraste una guarida! Entras y comienza la batalla");
            } 
            else
            {
                printf("No hay una guarida que completar en esta ciudad");
            }
            */
        }
        if (strcmp(entrada, "avanzar") == 0)
        {
            //revisar rutas disponibles
            //printf("Eliga una ruta entre %d y %d para seguir.");
        }
        if (strcmp(entrada, "regresar") == 0)
        {
            //revisar rutas disponibles
            //printf("Eliga una ruta entre %d y %d para seguir.");
        }
        if (strcmp(entrada, "regresar") == 1 && strcmp(entrada, "avanzar") == 1 
        && strcmp(entrada, "buscar guarida secreta") == 1 && strcmp(entrada, "ir al centro de entrenamiento") == 1
        && strcmp(entrada, "ir al gimnasio") == 1 && strcmp(entrada, "ir a la tienda") == 1
        && strcmp(entrada, "ir al centro") == 1)
        {
            printf("ERROR: Entrada invalida, intenta otra vez.\n");
        }
    }

}

int ruta(char numeroDeRuta)
{
    char* entrada;
    printf("Estas en la ruta %d, elige si vas a 'avanzar', 'regresar' o vas a hacer 'grind' para buscar pokemon salvage para entrenar o capturar. ");
    while(0 == 0)
    {
        EntradaDeComando(entrada);
        if(strcmp(entrada, "avanzar") == 0)
        {

        }
        if(strcmp(entrada, "regresar") == 0)
        {

        }
        if(strcmp(entrada, "avanzar") == 1 && strcmp(entrada, "regresar") == 1)
        {

        }
    }

}

int tienda()
{
    char* entrada;
    while(0 == 0)
    {
        printf("Escribe 'comprar pokeball' para comprar una pokeball por $100.\n");
        printf("Escribe 'salir' para regresar afuera.\n");
        EntradaDeComando(entrada);

        if(strcmp(entrada, "comprar pokeball") == 0)
        {
            printf("compraste una pokeball.\n");
            //codigo para añadir una pokeball al jugador y quitar dinero
        }
        if(strcmp(entrada, "salir") == 0)
        {
            printf("saliste de la tienda.\n");
            return 0;
        }
    }
}

int CentroPokemon(char EnCasa)
{
    char* entrada;
    if(EnCasa == 1)
    {
        printf("Entras a tu casa, elige si vas a 'sanar' tus pokemon o si vas a 'guardar en pc'\n");
        while(0 == 0)
        {
            EntradaDeComando(entrada);
        }
    }
    else
    {
        printf("Elige si vas a 'sanar' tus pokemon o si vas a 'guardar en pc'\n");
        while(0 == 0)
        {
            EntradaDeComando(entrada);
        }
    }
}

int Gimnasio(char cantDeBatallasRestantes)
{
    char* entrada;
    while(0==0)
        {
            printf("Quedan %d batallas para conseguir la medalla, estas seguro de que quieres desafiar a una batalla ahora?\n", cantDeBatallasRestantes);
            EntradaDeComando(entrada);
        }
    //codigo que controla las batallas en el gimnasio de una ciudad
    //NOTA: debe hacer que todas sean contra un pokemon de un mismo tipo
}

int CentroEntrenamiento()
{
    char* entrada;
    //codigo para controlar batallas en los centros de entrenamiento
}

int Liga()
{
    char* entrada;
    //control de batallas en la liga
    //NOTA: debe hacer que las batallas sean una detrás de otra, sin poder retroceder

    printf("FELICIDADES! Has vencido a la liga y te haz convertido en el Campeon de la Liga Pokemon\n.");
    printf("Presiona cualquier tecla para salir y terminar el juego\n.");
    EntradaDeComando(entrada);
    exit(0);
}