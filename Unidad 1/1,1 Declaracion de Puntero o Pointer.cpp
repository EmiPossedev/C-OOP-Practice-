#include <iostream>
using namespace std;

/* 
Declare una variable entera común y otra variable entera utilizando memoria dinámica (almacenando su dirección
de memoria en un puntero). Asigne a la primera variable el valor 10 y a la segunda variable un valor ingresado
por el usuario. Muestre luego los valores y las direcciones de memoria de ambas variables. IMPORTANTE: No olvide
liberar la memoria de la segunda variable antes de salir*/

int main() {
	
	int var_comun; /// Variable entera comun
	int *ptr = new int; /// Variable entera dinámica
	var_comun = 10;
	cout << "Ingrese el valor de la variable dinámica: "; 
	cin >> *ptr;
	
	/// Muestro los valores y direcciones de memoria de ambas variables
	cout << "Valor de variable comun: " << var_comun << endl;
	cout << "Dirección de memoria de variable comun: " << &var_comun << endl;
	cout << "Valor al que apunta el puntero: " << *ptr << endl;
	cout << "Dirección de memoria del puntero: " << ptr << endl;
	
	/// Elimino el espacio de la variable dinámica
	delete ptr;

	return 0;
}

