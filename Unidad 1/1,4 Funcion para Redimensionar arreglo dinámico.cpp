#include <iostream>
using namespace std;

struct array {
	int *ptr; // puntero 
	int size;
};

void rellenar_arreglo(array &a, int pos = 0){ // Puse un valor default para que empiece a rellenar desde ahí
	cout << "Ingrese los datos del arreglo" << '\n';
	for(int i=pos ; i<a.size ; i++) { 
		cout << "Elem[" << i+1 << "]= ";
		cin >> *(a.ptr+i);
	}
}

void mostrar_arreglo(const array &a){
	cout << "Los elementos del arreglo son: " << '\n';
	for(int i=0;i<a.size;i++) {
		cout << "Elem[" << i+1 << "]= " << *(a.ptr+i) << '\n';
	}
}

void redimensionar(array &a, int nuevo_tam){
	/// Verifico el nuevo tamaño
	if(nuevo_tam <= a.size){
		cout << "Error: el nuevo tamaño debe ser mayor al actual." <<'\n';
		return;
	}
	
	/// Creo un nuevo arreglo aux con mi nuevo tamaño
	int *aux = new int[nuevo_tam];
	
	/// Paso los datos de un arreglo al otro
	for(int i=0;i<a.size;i++) { 
	*(aux+i) = *(a.ptr+i); 
	}
	
	/// Relleno el resto de espacios vacios
	for(int i=a.size ; i<nuevo_tam ; i++) { 
		*(aux+i) = 0;
	}
	
	/// Primero libero la memoria del original
	delete [] a.ptr;
	/// Y asigno los valores del arreglo(struct array) aux a mi array original
	a.ptr = aux; 
	a.size = nuevo_tam;
}

int main() {
	
	array a; // Declaro el struct a
	cout << "Ingrese la cantidad de elementos del arreglo: ";
	cin >> a.size;
	a.ptr = new int[a.size]; // Lo inicializo con a.size elementos
	rellenar_arreglo(a); // Lo relleno con mi funcion
	mostrar_arreglo(a); // Lo muestro sin modificar
	/// Ahora le pregunto al usuario si quiere modificarlo
	char confirm;
	cout << "Si quiere redimensionarlo, ingrese 'y'(y=yes) o 'n'(n= no) si no: ";
	cin >> confirm;
	if (confirm == 'y'){
		int cant_elem_nuevos;
		cout << "Ingrese cuantos elementos quiere agregar: ";
		cin >> cant_elem_nuevos;
		int nuevo_tam = a.size + cant_elem_nuevos;
		redimensionar(a,nuevo_tam);
		rellenar_arreglo(a,a.size-cant_elem_nuevos);
	} else {
		cout << "El arreglo se mantiene igual." << '\n';
	}
	
	mostrar_arreglo(a);
	
	/// NUNCA OLVIDARSE DE LIBERAR LA MEMORIA
	delete[] a.ptr;

	return 0;
}

