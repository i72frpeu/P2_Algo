main: main.o funciones_comunes.o exponente_matriz.o ajustes.o sistemaEcuaciones.o
	g++ main.o funciones_comunes.o exponente_matriz.o ajustes.o sistemaEcuaciones.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

funciones_comunes.o: funciones_comunes.cpp
	g++ -c funciones_comunes.cpp -o funciones_comunes.o

exponente_matriz.o: exponente_matriz.cpp
	g++ -c exponente_matriz.cpp -o exponente_matriz.o

ajustes.o: ajustes.cpp
	g++ -c ajustes.cpp -o ajustes.o

sistemaEcuaciones: sistemaEcuaciones.cpp
	g++ -c sistemaEcuaciones -o sistemaEcuaciones.o

clean:
	rm main.o funciones_comunes.o exponente_matriz.o main
