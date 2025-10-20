#include <iostream>
using namespace std;


/* 
mplemente sobrecargas para los siguiente operadores:
• El operador + para sumar dos objetos de la clase Racional.
• El operador * para multiplicar un objeto de tipo Racional por un entero.
Finalmente, compruebe el funcionamiento de los operadores con el siguiente programa cliente:
int main() {
Racional a(3, 5), b(2, 3);
Racional aux = a + b;
cout << aux.VerNum() << '/' << aux.VerDen() << endl;
aux = a * b;
cout << p.VerNum() << '/' << p.VerDen() << endl;
}
Si ocurren errores de compilación, explique su causa e implemente las correcciones necesarias. 
Analice: ¿Qué otro operador se utiliza para la clase Racional en éste programa cliente? 
¿Por qué no es necesario sobrecargarlo?
*/
class Racional {
private:
	int m_num, m_den;
public:
	Racional(int num, int den) : m_num(num), m_den(den) { }
	int VerNum() const { return m_num; }
	int VerDen() const { return m_den; }
	
};

Racional operator+(Racional r1, Racional r2){
	Racional aux ( (r1.VerNum()*r2.VerDen() + r2.VerNum()*r1.VerDen()) ,r1.VerDen()*r2.VerDen());
	return aux;
}

Racional operator*(Racional r1, Racional r2){
	
}

int main() {
	Racional a(3, 5), b(2, 3);
	Racional aux = a + b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	
	/*
	aux = a * b;
	cout << p.VerNum() << '/' << p.VerDen() << endl;
	*/
	
	return 0;
}
