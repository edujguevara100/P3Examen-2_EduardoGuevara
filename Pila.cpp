#include "Pila.h"
#include <string>
using namespace std;

Pila::Pila(){
	
}

Simbolo* Pila::getPrimero(){
	return primero;
}


Pila::~Pila(){

}

void Pila::push(Simbolo* nuevo){
	nuevo->setAnterior(primero);
	primero = nuevo;
}

string Pila::pop(){
	string simb = primero->getSimbolo();
	primero = primero->getAnterior();
	return simb;
}

bool Pila::isEmpty(){
	if(primero == NULL){
		return true;
	}else{
		return false;
	}
}

string Pila::verActual(){
	return primero->getSimbolo();
}
