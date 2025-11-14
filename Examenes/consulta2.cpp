#include <iostream>
#include <fstream>
using namespace std;
/**
Implemente una función genérica que reciba el nombre de un archivo binario 
que guarda muchos datos de un cierto tipo, y dos valores A y B de 
ese mismo tipo. La función debe buscar en el archivo al valor A, 
y reemplazarlo por B (en todas las ocurrencias, puede estar más de una vez)
; y retornar el nro de reemplazos realizados. La función
debe operar directamente sobre el archivo (no usar un arreglo
, std::vector, std::list o cualquier otro contenedor)
**/
template<typename T>
int reemplazar(string NombreArchivo,T A, T B){
	int cantidad = 0;
	// Averiguo cuantos datos hay en mi archivo
	fstream bin(archivo,ios::binary|ios::in|ios::out|ios::ate);
	int cant = bin.tellg()/sizeof(T);
	// Y empiezo a leerlo desde el principio
	bin.seekg(0,ios::beg);
	for(int i=0 ; i<cant ; i++) { 
		T dato;
		bin.read(reinterpret_cast<char*>(&dato),sizeof(dato));
		if(dato == A){
			bin.seekp(i * sizeof(T));
			bin.write(reinterpret_cast<char*>(&B),sizeof(B));
			cantidad++;
		}
	}
	return cantidad;
}

template<typename T>
int reemplazar2(string NombreArchivo,T A, T B){
	int cantidad = 0;
	fstream bin(archivo,ios::binary|ios::in|ios::out);
	T dato;
	while(bin.read(reinterpret_cast<char*>(&dato),sizeof(dato))){ // el puntero avanza
		if(dato == A){
			bin.seekp(bin.tellg() - sizeof(T)); // retrocedo a la posicion anterior
			bin.write(reinterpret_cast<char*>(&B),sizeof(B));
			cantidad++;
		}
	}
	
	return cantidad;
}

	
int foo(string nomArch,T A,T B){
	int reemp=0;
	fstream bin(nomArch,ios::binary|ios::in|ios::out);
	T aux;int in=0;
	while(bin.read((char*)&aux,sizeof(aux))){
		if(aux==A){
			bin.seekp(in*sizeof(T));
			bin.write(reinterpret_cast<char>*(&B), sizeof(B));
			reemp++;
		}
		in++;
	}
	return reemp;
}

int main() {
	
	return 0;
}

