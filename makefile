temp:	main.o Pila.o Simbolo.o
		g++ main.o Pila.o Simbolo.o -o temp
main.o:	main.cpp Pila.h Simbolo.h
		g++ -c main.cpp
Pila.o:	Pila.cpp Pila.h Simbolo.h
		g++ -c Pila.cpp
Simbolo.o:	Simbolo.cpp Simbolo.h
		g++ -c Simbolo.cpp
