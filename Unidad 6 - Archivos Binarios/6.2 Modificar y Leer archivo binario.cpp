#include <iostream>
#include <fstream>
using namespace std;


/*
Escriba un programa abra el archivo generado en el ejercicio anterior y
solicite al usuario que ingrese un entero, un flotante y una posición. 
El programa debe sobrescribir el par en la posición ingresada por el 
usuario por el nuevo par. Luego muestre la lista de datos en consola 
mostrando un par por línea.
*/

struct Par{
	int entero;
	float flotante;
};


int main() {
	
	/// Solicito los datos al usuario
	string nombreArchivoBinario;
	cout << "Ingrese el nombre del archivo binario que desea(con la extension .dat): ";
	cin >> nombreArchivoBinario;
	fstream bin(nombreArchivoBinario, ios::binary | ios::in | ios::out);
	Par p;
	cout << "Ingrese la parte entera del par: ";
	cin >> p.entero;
	cout << "Ahora la parte flotante: ";
	cin >> p.flotante;
	int pos;
	cout << "Ingrese en que posición desea agregar el par: ";
	cin >> pos;
	
	/// Luego me posiciono y escribo en la posicion
	bin.seekp((pos-1) * sizeof(p)); // En pos-1 porque el usuario ingresa en base 1
	bin.write(reinterpret_cast<char*>(&p), sizeof(p)); // Sobreescribo la posicion
	
	/// Ahora leo el archivo y lo muestro en consola
	cout << "Los pares que están en mi archivo son: " << endl;
	bin.seekg(0); // voy al inicio del archivo porque el puntero quedó al final
	while(bin.read(reinterpret_cast<char*>(&p), sizeof(p)) ){
		cout << p.entero << " - " << p.flotante << endl;
	}
	bin.close();
	
	return 0;
}

