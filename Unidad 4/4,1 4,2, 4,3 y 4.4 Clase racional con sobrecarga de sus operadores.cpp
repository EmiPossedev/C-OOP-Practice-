#include <iostream>
using namespace std;

/// Ejercicio 1
/* 
Implemente sobrecargas para los siguiente operadores:
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

/// Ejercicio 2
/*
Para la clase Racional utilizada en el ejercicio anterior, implemente 
los operadores relacionales <, <=, >, >=, == y !=
para comparar dos números racionales. Haga uso de dichos operadores 
desde un programa cliente.
*/

/// Ejercicio 3
/* 
Implemente sobrecargas para los operadores >> y << para leer un objeto de
tipo Racional desde la consola (mediante cin) y mostrarlo en pantalla 
(mediante cout). La lectura se debe realizar leyendo el numerador y denominador 
por separado (es decir, separados por un espacio o salto de línea). El 
operador << debe mostrar el numerador y el denominador separados por el 
carácter '/'. Analice: la sobrecarga de este operador, ¿debe realizarse 
dentro ofuera de una clase?
*/

class Racional {
private:
	int m_num, m_den;
public: 
	Racional(int num, int den) : m_num(num), m_den(den) { }
	int VerNum() const { return m_num; }
	int VerDen() const { return m_den; }
	
};

/// Comienzo Ej 1
Racional operator+(Racional r1, Racional r2){
	// Creo 2 variables auxiliares para el num y el den
	int nuevoNum = r1.VerNum() * r2.VerDen() + r2.VerNum() * r1.VerDen();
	int nuevoDen = r1.VerDen() * r2.VerDen();
	// Y las devuelvo juntas
	Racional aux(nuevoNum, nuevoDen);
	return aux;
}

Racional operator*(Racional r1, Racional r2){
	int nuevoNum = r1.VerNum() * r2.VerNum();
	int nuevoDen = r1.VerDen() * r2.VerDen();
	Racional aux(nuevoNum, nuevoDen);
	return aux;
}
/// Fin Ej1

/// Comienzo Ej2
bool operator<(Racional r1, Racional r2){	
	return (r1.VerNum()*r2.VerDen() < r2.VerNum()*r1.VerDen());
}

bool operator<=(Racional r1, Racional r2){	
	return (r1.VerNum()*r2.VerDen() <= r2.VerNum()*r1.VerDen());
}


bool operator>(Racional r1, Racional r2){
	return (r1.VerNum()*r2.VerDen() > r2.VerNum()*r1.VerDen());
}
	

bool operator>=(Racional r1, Racional r2){
	return (r1.VerNum()*r2.VerDen() >= r2.VerNum()*r1.VerDen());
}

bool operator==(Racional r1, Racional r2){
	return (r1.VerNum()*r2.VerDen() == r2.VerNum()*r1.VerDen());
}

bool operator!=(Racional r1, Racional r2){
	return !(r1==r2);
}
/// Fin Ej2

/// Comienzo Ej3
ostream& operator<<(ostream &os, const Racional &r){
	os << r.VerNum() << "/" << r.VerDen();
	return os;
}

istream& operator>>(istream &is, Racional &r){
	int num, den;
	is >> num >> den;
	// Ahora creo un nuevo objeto con los valores leídos y lo devuelvo
	r = Racional(num,den); // modifico el Racional afectado por el cin
	return is;
}
/// Fin Ej3

/// Comienzo Ej4
Racional& Racional operator++(){
	m_num = m_num + m_den; // Sumo al num el den, para qu aumente en 1
	return *this; // // Devuelvo una referencia al objeto luego de ser modificado
}

Racional Racional operator++(int){
	Racional copia(m_num , m_den); // Creo una copia del valor antes de modificarlo
	m_num = n_num + m_den; // Luego modifico
	return copia; // Pero retorno el valor sin modificar
}
///Fin Ej4

int main() {
	Racional a(3, 5), b(2, 3);
	Racional aux = a + b; /// Operador de asignacion
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	
	aux = a * b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	
	
	/// Breve aclaración del operador de asignación
	/*
	No es necesario sobrecargarl el operador de asignacion = porque el
	compilador genera automaticamente un operador de asignacion por defecto
	Y como la clase Racional solo contiene miembos de tipo primitivo, y 
	NO GESTIONA RECURSOS DINAMICOS, la asignacion por defecto no genera ningun
	conflicto. Por lo que no hay necesidad de un comportamiento personalizado
	para la asignacion en este caso
	*/
	cout << "Prueba de la sobrecarga de operadores de comparacion(devuelven booleanos)" << endl;
	if(a == b){cout << "Verdadero" << endl; } else cout << "Falso" << endl;
	if(a <= b){ cout << "Verdadero" << endl; } else cout << "Falso" << endl;
	if(a > b) {cout << "Verdadero" << endl; } else cout << "Falso" << endl;
	if(a != b) {cout << "Verdadero" << endl; } else cout << "Falso" << endl;
	
	return 0;
}
