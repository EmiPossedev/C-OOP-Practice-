#include <iostream>
#include <fstream>
using namespace std;

/* 
Escriba un programa que cargue en un vector de strings una lista de palabras 
desde un archivo de texto (que contendrá una palabra por línea), muestre en 
pantalla la cantidad de palabras leídas, las ordene en el vector 
alfabéticamente, y reescriba el archivo original con la lista ordenada. 
Ayuda: para ordenar un vector v de principio a fin puede utilizar la 
sentencia sort(v.begin(), v.end());.
*/

int main() {
	
	// Abro el archivo y corroboro que se abra bien
	vector<string> v;
	ifstream archi("palabras.txt");
	if(!archi,is_open()){
		throw runtime_error("No se pudo abrir el archivo.");
	}
	// Leo las palabras
	string palabra;
	cout << "Las palabras son: " << endl;
	while(archi>>palabra){
		cout << palabra << ", ";
	}
	
	
	return 0;
}

