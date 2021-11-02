#include <stdlib.h>
#include <stdio.h>
#include "Variables.h"

int bucleDeGeneradorDeCiudades(char random, char indice, char* instalacion[], char* cuentaGuaridas)
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
            if(random % 100 <= 75)
            {
                //cerrado y desbloqueable con guarida
                if(random % 100 <= 30)
                    {*instalacion[2] = 2; *cuentaGuaridas++;}
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

int GenerarCiudades(struct Ciudad* Lista, char cantidadCiudades)
{
    time_t seed;
    char random;
    char cuentaGuaridas = 0;
    srand(time(NULL));

    char i, j;
    for( i = 0; i < cantidadCiudades; i++)
    {
        struct Ciudad* nueva = malloc(6);

        nueva->id = ++i;
        for(j = 0; j < 4; j++)
        {
            random = rand();
            bucleDeGeneradorDeCiudades(random, j, nueva->instalaciones, &cuentaGuaridas);
        }
    }
    return 0;
}

int main()
{
    
}