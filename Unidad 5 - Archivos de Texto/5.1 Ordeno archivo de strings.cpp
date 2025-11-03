#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
	if(!archi.is_open()){
			throw runtime_error("No se pudo abrir el archivo para lectura.");
	}
	// Leo las palabras y las guardo en mi vector
	string palabra;
	cout << "Las palabras son: " << endl;
	while(archi>>palabra){
			cout << palabra << " ";
			v.push_back(palabra);
	}
	cout << "Se leyeron " << v.size() << " palabras." << endl;
 archi.close();
	// Acá ordeno alfabeticamente las palabras en el vector con la funcion sort()
	sort(v.begin(),v.end());
	ofstream archi2("palabras.txt",ios::trunc); // bandera trunc para sobreescribir el archivo
	if(!archi2.is_open()){
		 		throw runtime_error("No se pudo abrir el archivo para escritura.");}

	cout << "Palabras ordenadas: " << endl;
 for(const auto &palabra : v){
				cout << palabra << " "; 
    archi2 << palabra << endl;
}
 archi2.close();

	return 0;
}

