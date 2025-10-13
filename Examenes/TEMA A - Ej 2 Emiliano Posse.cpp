#include <iostream>
using namespace std;

/* 
a) Escriba una función para buscar un elemento en un arreglo de enteros,
recibiendo el puntero al comienzo de los datos, la cantidad de elementos, 
y el valor que se busca. La función debe retornar un puntero al elemento 
encontrado, o el puntero nulo si no está. b) En un programa cliente, permita 
al usuario ingresar un arreglo de N valores (N es dato), y luego utilice la 
función para buscar y reemplazar todas las ocurrencias del valor -1 por el 
valor 42. Por cada reemplazo, informe el índice al que corresponde el elemento 
modificado dentro del arreglo.
*/

/// Creo la funcion
int* buscarElemen(int *ptr, int cant, int valorBuscado){
	for(int i=0;i<cant;i++) { 
		if(*(ptr+i) == valorBuscado){
			return ptr+i;
		}
	}
	return nullptr;
}

/// Creo una para mostrar los valores
void mostrarVectorDinamico(int* ptr, int hasta){
	for(int i=0;i<hasta;i++) { 
		cout << "V[" << i+1 << "]= " << *(ptr+i) << endl;
	}
}
	
int main() {
	/// Creo el arreglo dinamico
	int n;
	cout << "Ingrese la cantidad de valores del arreglo: "; 
	cin >> n;
	int* p = new int[n];
	/// Permito al usuario ingresar los datos del arreglo
	cout << "Ingrese los datos del arreglo" << endl;
	for(int i=0 ; i<n ; i++) { 
		cin >> *(p+i);
	}
	
	/// Lo muestro antes de ser modificado
	cout << "Vector antes de ser modificado" << endl;
	mostrarVectorDinamico(p,n);
	
	cout << "Pasa por un proceso de filtrado..." << endl;
	cout << endl;
	
	/// Busco los valores y los reemplazo
	int *ocurrencia = buscarElemen(p,n,-1);
	while(ocurrencia != nullptr){
		cout << "Encontrado en la posicion: " << (ocurrencia - p) + 1 << endl;
		*ocurrencia = 42 ;
		ocurrencia = buscarElemen(p,n,-1);
	}
	
	cout << "Vector despues de ser modificado" << endl;
	mostrarVectorDinamico(p,n);
	
	delete [] p;
	return 0;
}

