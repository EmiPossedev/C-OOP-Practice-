#include <iostream>
#include <fstream>
using namespace std;


/// Programa para leer el archivo
int main() {
	ifstream archi("GuardarNumerosEjemploDeTeoria .txt");
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo.");
	}
	
	// La condicion de corte es cuando no pueda seguir leyendo y retorne falso
	// Se utiliza cuando no sabemos la cantidad de datos que vamos a leer
	int x;
	while(archi>>x){
		cout << x << endl;
	}
	
	
	
	return 0;
}

