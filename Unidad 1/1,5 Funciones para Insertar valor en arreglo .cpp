#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct array {
	int *ptr;
	int size;
};

void mostrar_arreglo(const array &a){
	for(int i=0;i<a.size;i++) { 
		cout << "Elem[" << i+1 << "]= " << *(a.ptr+i) << '\n';
	}
}

void insertar(array &a,int pos, int valor){
	*(a.ptr+pos) = valor;
}

void rellenar_arreglo__din_aleat(array &a, int valor_min, int valor_max){
	for(int i=0;i<a.size;i++) { 
		*(a.ptr+i) = valor_min + rand() % (valor_max - valor_min + 1);
	}
}

int main() {
	srand(time(0)); // Cambio la semilla del srand
	/// Declaro el array a
	array a;
	cout << "Ingrese el tamaño del arreglo: "; // Pido cant. de elementos
	cin >> a.size;
	a.ptr = new int[a.size]; // Pido memoria para a.size elementos
	
	/// Pido sus valor min y max
	int val_max, val_min;
	cout << "Ingrese el valor min: ";
	cin >> val_min;
	cout << "Ingrese el valor max: ";
	cin >> val_max;
	
	/// Genero el arreglo y lo muestro
	rellenar_arreglo__din_aleat(a,val_min,val_max);
//	mostrar_arreglo(a);
	
	/// Le pregunto al usuario si quiere agregar un valor
	char confirm;
	cout << "Ingrese si desea agregar un valor(y=si, n=no) : ";
	cin >> confirm;
	
	if(confirm == 'y'){
		int valor, pos;
		cout << "Ingrese la posicion donde desea agregar un valor: ";
		cin >> pos;
		cout << "Ingrese el valor: "; 
		cin >> valor;
		insertar(a,pos-1,valor);
		cout << "El arreglo modificado es: "<< endl;
		mostrar_arreglo(a);
	} else {
		cout << "El arreglo se mantiene igual." << endl;
	}
	
	delete [] a.ptr;
	
	return 0;
}

