#include <iostream>
using namespace std;

/* 
Ej2 (25pts) a) Escriba una función que reciba dos punteros señalando dos 
posiciones en un arreglo de enteros. La función debe poner en 0 todos los 
valores del arreglo entre esas dos posiciones (incluyendo ambas), y retornar 
la cantidad de valores modificados. b) En un programa cliente, permita al 
usuario ingresar un arreglo de N valores (N es dato), luego ingresar dos 
índices, y utilice la función poner en cero todas las posiciones entre dichos
índices. Informe el arreglo completo modificado y la cantidad de cambios realizados.
*/

/// La funcion pedida
int PonerEn0(int* desde, int* hasta){
	int valores_modificados = 0;
	int cant = (hasta - desde)+1;
	for(int i=0 ; i<cant ; i++) { 
		*(desde+i) = 0;
		++valores_modificados;
	}
	return valores_modificados;
}
	
int main() {
	/// Reservo la memoria para el nuevo arreglo de memoria dinamica
	int n;
	cout << "Ingresar la cantidad de valores del arreglo: ";
	cin >> n;
	int* a = new int[n];
	
	/// Relleno el arreglo
	cout << "Ingrese los valores de los elementos del arreglo"<< endl;
	for(int i=0;i<n;i++) { 
		cin >> *(a+i);
	}
	
	/// Pido los indices al usuario y utilizo la funcion
	int i1, i2;
	cout << "Ingrese los indices para modificar el arreglo" << endl;
	cout << "Desde(inclusive): "; cin >> i1;
	cout << "Ingrese hasta(inclusive): "; cin >> i2;
	int cantValoresModificados = PonerEn0(a+i1-1, a+i2-1); // Le sumo los indices al puntero para utilizarlos
	cout << "Cantidad de valores modificados: " << cantValoresModificados << endl;
	cout << "Arreglo resultante:" << endl;
	for(int i=0 ; i<n ; i++) { 
		cout << "a[" << i+1 << "]= " << *(a+i) << endl;
	}
	
	delete [] a;
	
	return 0;
}
