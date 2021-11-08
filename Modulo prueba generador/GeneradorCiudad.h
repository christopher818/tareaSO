#include <stdlib.h>
#include <stdio.h>
#include "Variables.h"

#ifndef generadorCiudad
#define generadorCiudad

int bucleDeGeneradorDeCiudades(char random, char indice, char* instalacion[], char* cuentaGimnasios, char maxGimnasios);
int GenerarCiudades(Ciudad* Lista, char cantidadCiudades, char maximoGimnasios);

#endif