#include <iostream>
using namespace std;

/// Ejercicio 5
/*
Implemente una clase llamada Complejo para representar un número complejo. 
Sobrecargue los operadores <<, >>, +, -, * e == para mostrar, leer, sumar, 
restar, multiplicar y comparar respectivamente dos objetos de tipo Complejo.
Compruebe el funcionamiento de los operadores desde un programa cliente.

*/

class Complejo{
private:
	int pReal;
	int pCompleja;
public:
	Complejo(){}
	Complejo(int real, int complejo) : pReal(real), pCompleja(complejo){}
	int Ver_ParteReal() const { return pReal; }
	int Ver_ParteCompleja() const { return pCompleja; }
};

ostream& operator<<(ostream &os, const Complejo &c){
	os << c.Ver_ParteReal() << " + " << c.Ver_ParteCompleja() << "i";
	return os;
}

istream& operator>>(istream &is, Complejo &r){
	int real, compl;
	is >> real >> compl;
	r = Complejo(real,compl);
	return is;
}


int main() {
	
	return 0;
}

