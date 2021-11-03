#include <stdlib.h>
#include <stdio.h>
#include "Variables.h"

char salioDeCiudadNatal = 0;

int CiudadNatal()
{
    char* entrada;
    if(salioDeCiudadNatal == 0)
    {
        printf("Es hora de comenzar tu aventura, ve al laboratorio para elegir tu primer pokemon! \n");
        printf("Escribe 'ir al laboratorio' para ir hacia el laboratorio.\n");
        entrada = scanf("%s\n", entrada);
    }
    return 0;
}

int Ciudad()
{
    //codigo para mostrar lo que ocurre en una ciudad
    //
}

int ruta()
{
    //Codigo que controla el juego cuando se esta viajando entre ciudades
}

int Gimnasio()
{
    //codigo que controla las batallas en el gimnasio de una ciudad
    //NOTA: debe hacer que todas sean contra un pokemon de un mismo tipo
}

int CentroEntrenamiento()
{
    //codigo para controlar batallas en los centros de entrenamiento
}

int Liga()
{
    //control de batallas en la liga
    //NOTA: debe hacer que las batallas sean una detrás de otra, sin poder retroceder
}

/* FUNCION PRINCIPAL DEL JUEGO
Aqui se usan las demas funciones, llamandolas para los varios aspectos del juego y esta función*/
int Juego()
{
    char terminado = 0;

    while (terminado = 0)
    {

    }
}