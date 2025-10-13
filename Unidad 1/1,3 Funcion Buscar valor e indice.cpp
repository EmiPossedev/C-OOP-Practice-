
/*  Escriba una función que utilice punteros para buscar y retornar la 
dirección de un entero dentro de un arreglo. Se pasan como parámetros el 
arreglo, su tamaño y el entero a buscar. Si el dato no se encuentra, debe 
retornar la dirección de memoria nula (nullptr). ¿Desde un programa 
cliente, cómo se obtiene el índice del elemento encontrado cuando la 
función no devuelve nullptr? */
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct arreglo {
	int *ptr; /// puntero al comienzo del arreglo
	int size; /// tamaño del arreglo
};

void rellenar_arreglo(arreglo &a){
	for(int i=0 ; i<a.size ; i++) { 
		*(a.ptr+i) = 1 + rand() % (100 - 1 + 1);
	}
}

void mostrar_arreglo (const arreglo &a){
	for(int i=0 ; i<a.size ; i++) { 
		cout << "Element[" << i+1 << "]= " << *(a.ptr+i) << endl;
	}
}

int* buscar_elem (arreglo a, int valor_buscado){
	
	for(int pos=0 ; pos<a.size ; pos++) { 
		if(*(a.ptr+pos) == valor_buscado){
			return a.ptr+pos;
		}
	}
	return nullptr;
}

int main() {
	/// Cambio ka semilla del random para que genere nuevos numeros
	srand(time(0));
	
	/// Declaro el arreglo y guardo su informacion agrupada en un struct 
	arreglo a; // declaro el struct con nombre a
	cout << "Ingrese la cantidad de elementos del arreglo: ";
	cin >> a.size; // guardo su tamaño en el elemento size del struct
	a.ptr = new int[a.size]; // pido a.size espacios de memoria para mi arreglo
	
	/// Relleno mi arreglo
	rellenar_arreglo(a);
	
	/// Lo muestro
	mostrar_arreglo(a);
	
	/// Y por ultimo, busco el valor y aviso si lo encontré
	int valor_buscado;
	cout << "Ingrese el valor buscado: ";
	cin >> valor_buscado;
	int *valor_encontrado = buscar_elem(a,valor_buscado);
	
	if (valor_encontrado != nullptr){
		cout << "Se encontró el valor buscado :)" << '\n';
		cout << "Posición: " << valor_encontrado-a.ptr + 1 << '\n'; /* es con base 0 para 
		el programador y +1 para el usuario porque cuenta desde 1 */
		cout << "Dirección de memoria: " << valor_encontrado << '\n';
	}
	else {
		cout << "No se encontró el valor buscado :(" << '\n';
	}
	
	/// NUNCA OLVIDARME DE BORRAR LA MEMORIA AL FINAL
	delete[] a.ptr; 
	
	return 0;
}
