#include <iostream>
#include <fstream>

using namespace std;

/*
Escriba un programa que genere un archivo binario con una lista de 100 enteros 
ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego 
escriba otro programa que permita insertar (no reemplazar) un nuevo dato de 
tipo entero, ingresado por el usuario, en el archivo manteniendo el orden 
creciente. Importante: no debe utilizar arreglos/vectores auxiliares.
*/

int main() {
	/// Solicito los datos al usuario
	string nombreArchivo;
	cout << "Ingrese el nombre del archivo(con la extensión .dat): ";
	cin >> nombreArchivo;
	
	int nuevoNumero;
	cout << "Ingrese el entero a insertar: ";
	cin >> nuevoNumero;
	
	/// Abrir archivo en modo lectura/escritura
	fstream bin(nombreArchivo, ios::binary | ios::in | ios::out);
	if(!bin.is_open()){ 
		throw runtime_error("Error: No se pudo abrir el archivo.");} //Compruebo
	
	/// Calculo la cantidad actual de enteros
	bin.seek(0, ios::end);
	int cantEnterosActual = bin.tellg() / sizeof(int);
	cout << "Cantidad de enteros actual: " << cantEnterosActual << endl;
	for(int i = 0; i<cantEnterosActual; i++){
			
		}
	
	return 0;
}

