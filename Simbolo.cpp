#include "Simbolo.h"
#include <string>
using namespace std;

Simbolo::Simbolo(string simb){
	simbolo = simb;
}

Simbolo::~Simbolo(){

}

string Simbolo::getSimbolo(){
	return simbolo;
}

Simbolo* Simbolo::getAnterior(){
	return anterior;
}

void Simbolo::setAnterior(Simbolo*& nuevo){
	anterior = nuevo;
}
