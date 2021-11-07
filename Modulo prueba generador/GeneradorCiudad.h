#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "Variables.h"

#ifndef generadorCiudad
#define generadorCiudad

int bucleDeGeneradorDeCiudades(char random, char indice, char* instalacion[], char* cuentaGuaridas);
int GenerarCiudades(Ciudad* Lista, char cantidadCiudades, char maximoGimnasios);

#endif