#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
a) Escriba a través de un programa C++ un archivo binario llamado grupo.dat, 
formado por un conjunto de 200 pares de números generados aleatoriamente.
Cada par de datos se conforma por un entero y flotante.
b) Escriba otro programa que lea el archivo generado por el primero para
verificar si se escribieron correctamente.
*/

struct Par{
	int entero;
	float flotante;
};

int main(){
	srand(time(0));
	string nombreArchivoBinario;
	cout << "Ingrese el nombre del archivo binario que desea(con la extension .dat): ";
	cin >> nombreArchivoBinario;
	fstream bin(nombreArchivoBinario, ios::binary | ios::out);
	if(!bin.is_open()){ throw runtime_error("No se pudo abrir el archivo para escritura."); }
	for(int i = 0; i < 200; i++){
		Par p;
		p.entero = 100 + rand() % (500 - 100 + 1);
		p.flotante = 100.0 + rand() % (500 - 100 + 1);
		bin.write((char*) &p, sizeof(p));
	}
	bin.close();
	cout << "Se escribió el archivo con los 200 pares" << endl;
	
	fstream binr(nombreArchivoBinario, ios::binary | ios:: in);
	if(!binr.is_open()){ throw runtime_error("No se pudo abrir el archivo para lectura."); }
	int cantMostrar;
	cout << "Ingrese la cantidad a mostrar: ";
	cin >> cantMostrar;
	while(cantMostrar > 200){
		cout << "Cantidad de personas invalida, debe ser menor a 200, ingreselo de nuevo: ";
		cin >> cantMostrar;
	}
	Par p;
	int contador = 0;
	while(binr.read(reinterpret_cast<char*>(&p), sizeof(Par))){
		contador++;
		if(contador <= cantMostrar){
			cout << "Entero numero: " << contador << endl;
			cout << p.entero << ", " << p.flotante << endl;
		}
	}	
	binr.close();
	
	return 0;
}
