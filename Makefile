main: main.o GeneradorCiudad.o InputFlusher.o PokemonMenu.o Variables.o
	cc main.o GeneradorCiudad.o InputFlusher.o PokemonMenu.o Variables.o -o main

main.o: main.c GeneradorCiudad.h InputFlusher.h PokemonMenu.h Variables.h
	cc -c main.c 
GeneradorCiudad.o: GeneradorCiudad.c GeneradorCiudad.h Variables.h
	cc -c GeneradorCiudad.c
PokemonMenu.o: PokemonMenu.c PokemonMenu.h InputFlusher.h
	cc -c PokemonMenu.c
Variables.o: Variables.c Variables.h
	cc -c Variables.c
InputFlusher.o: InputFlusher.c InputFlusher.h
	cc -c InputFlusher.c

#siempre debe haber una linea en blanco al final