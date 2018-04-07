#ifndef PILA_H
#define PILA_H
#include <string>
#include "Simbolo.h"
using namespace std;

class Pila{
	private:
		Simbolo* primero;
	public:
		//void setAnterior(Pila*&);
		void push(Simbolo*);
		string pop();
		bool isEmpty();
		Simbolo* getPrimero();
		/*string getSimbolo();
		Pila* getAnterior();*/
		string verActual();
		Pila();
		~Pila();
};
#endif
