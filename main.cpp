#include "Pila.h"
#include <iostream>
#include <string>
#include "Simbolo.h"
#include <typeinfo>
using namespace std;

int menu();
void print(int,Pila*);
void llenar(int, Pila*&, string);
int syr(Pila*&,int);
int multi(Pila*&,int);
float divi(Pila*&,int);
float agrupar(Pila*&,int);

int main(){
	int op = 0;
	string sin = "";
	Pila* pila = new Pila();
	string cadena;
	int sum = 0;
	int mult = 0;
	float div = 0;
	float agrup = 0;
	int flag = 1;
	bool val = true, val1 = true, val2 = true, val3 = true, val4 = true;
	while(op != 7){
		switch(op = menu()){
			case 1:
				cout<<"Ingrese la cadena(el primer caracter debe ser un numero)"<<endl;
				cin>>cadena;
				for(int i = 0; i < cadena.length(); i++){
					if((int)cadena[i] <= 57 && (int)cadena[i] >= 40){

					}else{
						val1 = false;
					}
				}
				if(cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '/' || cadena[0] == '=' || val1 == false){
					cout<<"No es operable"<<endl;
				}else if((pila->getPrimero())->getSimbolo() != "+" && (pila->getPrimero())->getSimbolo() != "-"
						&& (pila->getPrimero())->getSimbolo() != "*" && (pila->getPrimero())->getSimbolo() != "/"
						&& val1 != false){
					llenar(cadena.length(),pila,cadena);
					cout<<"El contenido de la pila es:"<<endl;
					print(cadena.length(),pila);
					llenar(cadena.length(),pila,cadena);
					sum = syr(pila,cadena.length());
					cout<<"La respuesta es: "<<sum<<endl;
				}
				break;
			case 2:
				cout<<"Ingrese la cadena(el primer caracter debe ser un numero)"<<endl;
				cin>>cadena;
				for(int i = 0; i < cadena.length(); i++){
					if((int)cadena[i] <= 57 && (int)cadena[i] >= 40){

					}else{
						val2 = false;
					}
				}
				if(cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '/' || cadena[0] == '=' || val2 == false){
					cout<<"No es operable"<<endl;
				}else /*if((pila->getPrimero())->getSimbolo() != "+" && (pila->getPrimero())->getSimbolo() != "-"
						&& (pila->getPrimero())->getSimbolo() != "*" && (pila->getPrimero())->getSimbolo() != "/")*/{
					llenar(cadena.length(),pila,cadena);
					cout<<"El contenido de la pila es:"<<endl;
					print(cadena.length(),pila);
					llenar(cadena.length(),pila,cadena);
					mult = multi(pila,cadena.length());
					cout<<"El resultado es: "<<mult<<endl;
				}
				break;
			case 3:
				cout<<"Ingrese la cadena(el primer caracter debe ser un numero)"<<endl;
				cin>>cadena;
				for(int i = 0; i < cadena.length(); i++){
					if(cadena[i] == '0'){
						if(cadena[i+1] == '/'){
							cout<<"No se puede dividir entre 0"<<endl;
							val = false;
						}
					}
					if((int)cadena[i] <= 57 && (int)cadena[i] >= 40){

					}else{
						val3 = false;
					}
				}
				if(cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '*' || cadena[0] == '/' || val3 == false){
					cout<<"No es operable"<<endl;	
				}else if(val != false && val3 != false){
					llenar(cadena.length(),pila,cadena);
					cout<<"El contenido de la pila es:"<<endl;
					print(cadena.length(),pila);
					llenar(cadena.length(),pila,cadena);
					div = divi(pila,cadena.length());
					cout<<"El resultado es: "<<div<<endl;
				}
				break;
			case 4:
				cout<<"Ingrese la cadena(el primer caracter debe ser un numero)"<<endl;
				cin>>cadena;
				for(int i = 0; i < cadena.length(); i++){
					if((int)cadena[i] <= 57 && (int)cadena[i] >= 40){

					}else{
						val4 = false;
					}
				}
				if(cadena[0] == '+' || cadena[0] == '-' || cadena[0] == '*' || cadena[0] == '/' 
					|| cadena[0] == '(' || cadena[0] == ')' || val4 == false){
					cout<<"No es operable"<<endl;
				}else{
					llenar(cadena.length(),pila,cadena);
					cout<<"El contenido de la pila es:"<<endl;
					print(cadena.length(),pila);
					llenar(cadena.length(),pila,cadena);
					agrup = agrupar(pila,cadena.length());
					cout<<"El resultado es: "<<agrup<<endl;
				}
				break;
			case 5:
				cout<<"Ingrese una cadena(el primer caracter debe ser el nombre de la variable)"<<endl;
				cin>>cadena;
				break;
			case 6:
				cout<<"Ingrese una cadena"<<endl;
				cin>>cadena;
				llenar(cadena.length(),pila,cadena);
				cout<<pila->verActual()<<endl;;
				while(flag == 1 && (pila->getPrimero())->getAnterior() != NULL){
					cout<<"Desea hacer pop(1 si 2 no)"<<endl;
					cin>>flag;
					if(flag == 1 && (pila->getPrimero())->getAnterior() != NULL){
						pila->pop();
						cout<<pila->verActual()<<endl;
					}
				}
				break;
			default:
				op = 7;
				break;
		}
		val1 = true;
		val2 = true;
		val3 = true;
		val4 = true;
	}
	delete pila;
	return 0;
}

int menu(){
	int op;
	cout<<"1: Suma y resta"<<endl
		<<"2: Multiplicacion"<<endl
		<<"3: Division"<<endl
		<<"4: Agrupacion"<<endl
		<<"5: Asignacion"<<endl
		<<"6: Imprimir el valor actual de la pila"<<endl
		<<"7: Salir"<<endl;
	cin>>op;
	return op;
}

void print(int size, Pila* pila){
	for(int i = 0; i < size; i++){
		cout<<pila->pop()<<" ";
	}
	cout<<endl;
}

void llenar(int size, Pila*& pila, string cadena){
	string sin = "";
	for(int i = 0; i < size; i++){
		sin += cadena[i];
		pila->push(new Simbolo(sin));
		sin = "";
	}
}

int syr(Pila*& pila, int size){
	int acum = 0;
	for(int i = 0; i < size; i++){
		if((pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"){
			if((pila->getPrimero())->getSimbolo() == "+"){
				pila->pop();
				acum += stoi(pila->pop());
				i++;
			}else{
				pila->pop();
				acum -= stoi(pila->pop());
				i++;
			}
		}else{
			acum = stoi(pila->pop());
		}
	}
	return acum;
}

int multi(Pila*& pila, int size){
	int acum = 0;
	for(int i = 0; i < size; i++){
		if((pila->getPrimero())->getSimbolo() == "*"){
			pila->pop();
			acum *= stoi(pila->pop());
			i++;
		}else{
			acum = stoi(pila->pop());
		}
	}
	return acum;
}

float divi(Pila*& pila, int size){
	float acum = 0;
	for(int i = 0; i < size; i++){
		if((pila->getPrimero())->getSimbolo() == "/"){
			pila->pop();
			acum /= stoi(pila->pop());
			i++;
		}else{
			acum = stoi(pila->pop());
		}
	}	
	return acum;
}

float agrupar(Pila*& pila, int size){
	float acum = 0;
	for(int i = 0; i < size; i++){
		if((pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
				|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
				|| (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){

			if((pila->getPrimero())->getSimbolo() == "+"){
				pila->pop();
				i++;
				while((pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
					|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
					|| (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){
					pila->pop();
					i++;
				}
				acum += stoi(pila->pop());
			}else if((pila->getPrimero())->getSimbolo() == "-"){
				pila->pop();
				i++;
				while((pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
					|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
					|| (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){
					pila->pop();
					i++;
				}
				acum -= stoi(pila->pop());
			}else if((pila->getPrimero())->getSimbolo() == "*"){
				pila->pop();
				i++;
				while((pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
					|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
					|| (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){
					pila->pop();
					i++;
				}
				acum *= stoi(pila->pop());
			}else if((pila->getPrimero())->getSimbolo() == "/"){
				pila->pop();
				i++;
				while((pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
					|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
					|| (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){
					pila->pop();
					i++;
				}
				acum /= stoi(pila->pop());
			}else if((pila->getPrimero())->getSimbolo() == "("){
				pila->pop();
				//i++;
				while(/*(pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
					|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
					||*/ (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){
					pila->pop();
					i++;
				}
			}else if((pila->getPrimero())->getSimbolo() == ")"){
				pila->pop();
				//i++;
				while(/*(pila->getPrimero())->getSimbolo() == "+" || (pila->getPrimero())->getSimbolo() == "-"
					|| (pila->getPrimero())->getSimbolo() == "*" || (pila->getPrimero())->getSimbolo() == "/"
					||*/ (pila->getPrimero())->getSimbolo() == "(" || (pila->getPrimero())->getSimbolo() == ")"){
					pila->pop();
					i++;
				}
			}
		}else{
			acum = stoi(pila->pop());
		}
	}
	return acum;
}
