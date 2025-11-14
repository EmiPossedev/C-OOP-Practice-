#include <iostream>
#include <numeric>
#include <list>
#include <fstream>
using namespace std;
/**
a) Diseñe una función genérica promedio(...) que reciba una lista (list) 
de datos de cualquier tipo y calcule el promedio de los elementos.
b) Escriba un programa en C++ que sea un cliente de la función promedio(...). 
El programa debe invocar la función tres veces para las siguientes listas:
i) Una lista de números flotantes ingresados por el usuario desde el teclado.
ii) Una lista de números enteros generados aleatoriamente en el rango de 1 a 100.
iii) Una lista de números complejos 
(struct Complejo { float p_real, p_imag; }) que deben leerse
desde un archivo binario "complejos.dat". 
Nota: implemente todas las funciones auxiliares que considere
necesarias para que el programa funcione
**/
// Mi struct complejo
struct complejo{
	float p_real,p_imag;
};
// Sobrecarga de operadores
complejo operator+(const complejo &c1, const complejo &c2){
	complejo s; 
	s.p_real = c1.p_real + c2.p_real;
	s.p_imag = c1.p_imag+c2.p_imag;
	return s;
}
complejo operator/(const complejo &c1,int cant){
	complejo c;
	c.p_real = c1.p_real/cant;
	c.p_imag = c1.p_imag/cant;
	return c;
}
// Mi plantilla
template<typename T>
T promedio(list<T> &lst){
	T suma = accumulate(lst.begin(),lst.end(), T()); // Funcion accumulate pide un iterador desde y otro hasta, y un 3er arg desde donde inicia el acumulador
	return suma/lst.size();
}

// Funcion para leer y llenar mi lista de complejos
void LeerComplejos(string archivo,list<complejo>&comp){
	complejo c;
	fstream bin(archivo,ios::binary|ios::in);
	while(bin.read(reinterpret_cast<char*>(&c),sizeof(c))){
		comp.push_back(c);
	}
	bin.close();
}

int main() {
	
	/// Inciso i
	int cantDatos;
	cout << "Ingrese la cantidad de datos a leer: "; 
	cin >> cantDatos;
	list<float> flot;
	for(int i=0;i<cantDatos;i++) { 
		float aux;
		cout << "Dato[" << i << "]= "; 
		cin >> aux;
		flot.push_back(aux);
	}
	float promedioFlot = promedio<float>(flot);
	cout << "Promedio flotantes: " << promedioFlot << endl;
	
	/// Inciso ii
	list<int> enteros;
	int cantEnteros;
	cout <<"Cuantos enteros quieres ver?: ";
	cin >> cantEnteros;
	for(int i=0;i<cantEnteros;i++) { 
		float aux = 1 + rand() % (100 - 1) + 1;
		enteros.push_back(aux);
	}
	float promedioInt = promedio<int>(enteros);
	cout << "Promedio enteros: " << promedioInt << endl;
	
	/// Inciso iii
	list<complejo>comp;
	LeerComplejos("complejos.dat",comp);
	complejo prom = promedio<complejo>(comp);
	cout << "Promedio: " << prom.p_real << " + " << prom.p_imag << endl;
	
	return 0;
}

