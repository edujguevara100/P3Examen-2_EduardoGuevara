#ifndef SIMBOLO_H
#define SIMBOLO_H
#include <string>
using namespace std;

class Simbolo{
	private:
		string simbolo;
		Simbolo* anterior;
	public:
		Simbolo(string);
		~Simbolo();
		string getSimbolo();
		Simbolo* getAnterior();
		void setAnterior(Simbolo*&);
};
#endif
