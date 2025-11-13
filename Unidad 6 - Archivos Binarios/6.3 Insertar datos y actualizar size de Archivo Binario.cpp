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
	
	/// Paso 1: Calculo la cantidad actual de enteros
	bin.seekg(0, ios::end);
	int cantEnterosActual = bin.tellg() / sizeof(int);
	cout << "Cantidad de enteros actual: " << cantEnterosActual << endl;

	/// Paso 2: Busco posicion de inserción
	int posInsercion = 0;
	bin.seekg(0, ios::beg);

	int nro;
	while(bin.read(reinterpret_cast<char*>(&nro), sizeof(int)) ){
		if(nro >= nuevoNumero){
					// Encontramos la posicion y dejamos apuntada la posicion
				 break;
		}
		posInsercion++;
	}
	
	cout << "Posicion de insercion: " << posInsercion << endl;

	/// Paso 3: Desplazar los elementos hacia la derecha
	 // Empiezo desde el final y voy hacia atrás
		for(int i = cantEnterosActual - 1; i>=posInsercion; i--){
			// Leo el elemento en posición i
			int aux;
			bin.seekg(i * sizeof(int), ios::beg);
			bin.read(reinterpret_cast<char*>(&aux), sizeof(int));
			// Lo escribo en posicion i+1
			bin.seekp((i+1) * sizeof(int), ios::beg);
			bin.write(reinterpret_cast<char*>(&aux), sizeof(int));
			}
/// Paso 4: Inserto el nuevo número
			bin.seekp(posInsercion * sizeof(int), ios::beg);
			bin.write(reinterpret_cast<char*>(&nuevoNumero), sizeof(int));
			
			bin.close(); // cierro el archivo
		
			cout << "El numero " << nuevoNumero << " fue insertado exitosamente." << endl;

	/// Muestro el resultado
			// Abro el archivo para lectura
			bin.open(nombreArchivo, ios::binary | ios::in);
			int cantMostrar;
			cout << "Enteros en el archivo" << endl << "Cuantos enteros desea ver del archivo? ";
			cin >> cantMostrar;
			int contador = 0, intLeido;
			while(bin.read(reinterpret_cast<char*>(&intLeido), sizeof(int)) && contador < cantMostrar){
								cout << "Entero "<< contador <<": " << intLeido << endl;
								contador++; 
			}
			bin.close();

	return 0;
}

