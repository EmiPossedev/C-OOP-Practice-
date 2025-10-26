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
	int VerParteReal() const { return pReal; }
	int VerParteCompleja() const { return pCompleja; }
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

Complejo operator+(const Complejo &c1, const Complejo &c2){
	return Complejo(
		c1.VerParteReal() + c2.VerParteReal(),
		c1.verParteCompleja() + c2.VerParteCompleja()
	);
}

Complejo operator-(const Complejo &c1, const Complejo &c2){
	return (
		c1.VerParteReal() - c2.VerParteReal(),
		c1.VerParteCompleja() - c2.VerParteCompleja()
	);
}

Complejo operator*(const Complejo &c1, const Complejo &c2){
	int parteReal = c1.VerParteReal() * c2.VerParteReal() - c1.VerParteCompleja() * c2.VerParteCompleja();
	int parteImaginaria = c1.VerParteReal() * c2.VerParteCompleja() + c1.VerParteCompleja() * c2.VerParteReal();
	Complejo c3(parteReal,parteImaginaria);
	return c3;
}

bool operator==(const Complejo &c1, const Complejo &c2){
	return (
		c1.VerParteReal() == c2.VerParteReal() && c1.VerParteCompleja() == c2.VerParteCompleja()
	); // Si se cumplen estas condiciones, son iguales.
}

int main() {
	
	return 0;
}

