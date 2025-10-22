#include <iostream>
using namespace std;

int foo (int* p, int* q, int hasta){
	for(int i=0;i<hasta;i++) { 
		if(*(p+i) != *(q+i)){
			return i;
		}
	}
	return -1;
}

int main() {
	
	int n;
	cout << "Ingrese el tamaño de los arreglos: ";
	cin >> n;
	int* p = new int[n];
	int* q = new int[n];
	cout << "Ingrese los datos del primer arreglo" << endl;
	for(int i=0;i<n;i++){
		cout << "p[" << i << "]= ";
		cin >> *(p+i);
	}
	cout << "Ingrese los datos del segundo arreglo" << endl;
	for(int i=0;i<n;i++){
		cout << "q[" << i << "]= ";
		cin >> *(q+i);
	}
	
	// Verificar diferencias en un solo bucle
	bool hayDif = false;
	for(int i=0; i<n; i++) {
		if(p[i] != q[i]) {
			cout << "Difieren en: " << i << endl;
			hayDif = true;
		}
	}
	
	if (!hayDif){
		cout << "Los arreglos no difieren." << endl;
	}
	
	delete [] p;
	delete [] q;
	
	return 0;
}
