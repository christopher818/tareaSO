#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Variables.h"

#ifndef generadorCiudad_c
#define generadorCiudad_c

int bucleDeGeneradorDeCiudades(char random, char indice, char* instalacion[], char* cuentaGimnasios, char maxGimnasios)
{
    switch(indice)
    {
        //Centro Pokemon
        case 0:
            if(random % 100 <= 90)
                *instalacion[0] = 1;
            else
                *instalacion[0] = 0;
            return 0;

        //Tienda
        case 1:
            if(random % 100 <= 83)
                *instalacion[1] = 1;
            else
                *instalacion[1] = 0;
            return 0;
            
        //Gimnasio
        case 2:
            if(random % 100 <= 75 && *cuentaGimnasios < maxGimnasios)
            {
                //cerrado y desbloqueable con guarida
                if(random % 100 <= 30)
                    {*instalacion[2] = 2;}
                //abierto
                else                    
                    {*instalacion[2] = 1;}
            }
            else
                *instalacion[2] = 0;
            return 0;

        //Centro de entrenamiento
        case 3: 
            if(random % 100 <= 33)
                *instalacion[3] = 1;
            else
                *instalacion[3] = 0;
            return 0;

        default:
            return 1;
    }
}

/* */
int GenerarGimnasiosYGuaridas(Ciudad* Lista)
{
    Ciudad* ciudadAEvaluar = Lista->cabeza;

    /* Se recorren todas las ciudades buscando las que tienen gimnasios bloquados.
    Se guarda su direccion en "ciudadAEvaluar" y luego se recorren las demas ciudades para ver si se ponen
    guaridas alli*/
    while (0 == 0)
    {
        /*Si tiene una guarida bloqueada, se recorren las demas ciudades como "AplicarGuarida".
        Si no tienen guarida y son una ciudad diferente, se lanza un dado a ver si se pone una guarida alli
        Y si se pone una guarida, se guarda la id de la ciudad con ella en la ciudad en "ciudadAEvaluar"
        y se rompe el bucle, si no, se continua hasta que se coloque la guarida*/
        if(ciudadAEvaluar->instalaciones[2]==2);
        {
            Ciudad* AplicarGuarida = Lista->cabeza;
            while( 0 == 0 )
            {
                time_t seed;
                srand(time(NULL));
                char random = rand();

                if (random % 100 <= 25)
                {
                    AplicarGuarida->instalaciones[4] = 1;
                    ciudadAEvaluar->guaridaEn = AplicarGuarida->id;
                    break;
                }
                if((AplicarGuarida->instalaciones[4] == 1 || AplicarGuarida->id == ciudadAEvaluar->id)
                && ciudadAEvaluar->sig != NULL)
                {
                    AplicarGuarida = ciudadAEvaluar->sig;
                    continue;
                }
                if (ciudadAEvaluar->sig == NULL)
                {
                    AplicarGuarida = Lista->cabeza;
                }
            }
        }

        if(ciudadAEvaluar ->sig == NULL)
        {
            break;
        }
        else
        {
            ciudadAEvaluar = ciudadAEvaluar->sig;
        }
    }
        
    return 0;
}

int GenerarCiudades(Ciudad* Lista, char cantidadCiudades, char maximoGimnasios)
{
    time_t seed;
    char random;
    char cuentaGimnasios = 0;
    printf("step2");
    char i, j;
    for( i = 0; i < cantidadCiudades; i++)
    {
        printf("step2");
        Ciudad* nueva = malloc(sizeof(Ciudad));

        nueva->id = ++i;
        for(j = 0; j < 4; j++)
        {
            srand(time(NULL));
            random = rand();
            printf("step3");
            char* auxPointer = nueva->instalaciones;
            printf("step3");
            char** funcPointer = &auxPointer;
            bucleDeGeneradorDeCiudades(random, j, funcPointer, &cuentaGimnasios, maximoGimnasios);
        }
    }


    return 0;
}

#endif
