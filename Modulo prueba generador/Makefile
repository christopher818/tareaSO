Printer: Printer.o GeneradorCiudad.o  Variables.o Apagado.o GeneradorPokemon.o
	cc Printer.o GeneradorCiudad.o Apagado.o GeneradorPokemon.o Variables.o -o Printer

Printer.o: Printer.c GeneradorCiudad.h  Variables.h
	cc -c -g Printer.c
	 
GeneradorCiudad.o: GeneradorCiudad.c GeneradorCiudad.h Variables.h
	cc -c GeneradorCiudad.c

Variables.o: Variables.c Variables.h
	cc -c Variables.c

GeneradorPokemon.o: GeneradorPokemon.c GeneradorPokemon.h Variables.h 
	cc -c GeneradorPokemon.c

Apagado.o: Apagado.c Apagado.h
	cc -c Apagado.c InputFlusher.c InputFlusher.h