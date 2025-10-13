#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* 
Utilizando notación de punteros, generar un arreglo dinámico y lineal de N elementos 
numéricos enteros, con valores aleatorios entre 1000 y 1500, y muestre en pantalla 
la dirección de memoria del mayor elemento. N es un dato ingresado por el usuario
*/

// Funcion para mostrar el arreglo dinamico y la direccion de cada elemento
void mostrar_arreglo (int *arreglo, int final){
	for(int i=0 ; i<final ; i++) { 
		cout << "Elemento[" << i+1 << "]= " << *(arreglo + i) << '\n';
		cout << "Direccion de memoria: " << (arreglo+i) << '\n';
		cout << '\n';
	}
}
	
int main() {
		
	int cant_val; 
	cout << "Ingrese la cantidad de valores del arreglo lineal: "; 
	cin >> cant_val;
	
	/// Reservo memoria para mi arreglo dinámico en el heap
	int *arreglo = new int[cant_val];
	
	/// Inicializo el generador de numeros random
	srand(time(0)); // Cambiar la semilla del rand()
	
	/// Lleno el arreglo con valores aleatorios entre 1000 y 1500
	for(int i=0 ; i<cant_val ; i++) { 
		*(arreglo+i) = 1000 + rand() % (1500 - 1000 +1);
	}
	
	/// Buscar y guardar el mayor elemento
	int *mayorVal = arreglo;
	for(int i=0 ; i<cant_val ; i++) { 
		if(*(arreglo+i) > *mayorVal){
			mayorVal = arreglo + i;
		}
	}
	
	/// Muestro mi arreglo completo
	mostrar_arreglo(arreglo, cant_val);
	
	/// Muestro el mayor valor y su direccion de memoria
	cout << "MAYOR VALOR: " << *mayorVal << '\n';
	cout << "DIRECCION DE MEMORIA: " << mayorVal << '\n';
	
	/// NO OLVIDARME DE LIBERAR LA MEMORIA
	delete [] arreglo;
	
	return 0;
}
