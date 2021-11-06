main: main.o GeneradorCiudad.o InputFlusher.o PokemonMenu.o Variables.o Apagado.o batallaPokemon.o Escenas.o GeneradorPokemon.o Juegos.o PokemonMenu.o
	cc main.o GeneradorCiudad.o InputFlusher.o PokemonMenu.o Variables.o Apagado.o batallaPokemon.o Escenas.o GeneradorPokemon.o Juegos.o PokemonMenu.o -o main

main.o: main.c GeneradorCiudad.h InputFlusher.h PokemonMenu.h Variables.h
	cc -c main.c 
GeneradorCiudad.o: GeneradorCiudad.c GeneradorCiudad.h Variables.h
	cc -c GeneradorCiudad.c
PokemonMenu.o: PokemonMenu.c PokemonMenu.h InputFlusher.h Variables.h
	cc -c PokemonMenu.c
Variables.o: Variables.c Variables.h
	cc -c Variables.c
InputFlusher.o: InputFlusher.c InputFlusher.h
	cc -c InputFlusher.c

Apagado.o: Apagado.c Apagado.h
	cc -c Apagado.c

batallaPokemon.o: batallaPokemon.c batallaPokemon.h GeneradorPokemon.h Apagado.h
	cc -c batallaPokemon.c

Escenas.o: Escenas.c Escenas.h Variables.h 
	cc -c Escenas.c

GeneradorPokemon.o: GeneradorPokemon.c GeneradorPokemon.h Variables.h 
	cc -c GeneradorPokemon.c

Juegos.o: Juegos.c Juegos.h Variables.h 
	cc -c Juegos.c

#siempre debe haber una linea en blanco al final