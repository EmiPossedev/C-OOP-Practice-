#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct articulo{
	char codigo[12];
	char descripcion[50];
	char categoria[20];
	float precio;
};

template<typename T>
class ManejaArchivo{
	string nomarch;
	int cantidad;
	vector<T> lista;
public:
	ManejaArchivo(string nom):nomarch(nom){
		fstream bin(nomarch,ios::binary|ios::in|ios::ate///siempre me olvido que esta chagar te tira al final);
		cantidad = bin.tellg()/sizeof(T);
		T dato;
		bin.seekg(0);
		while(bin.read(reinterpret_cast<char*>(&dato),sizeof(dato))){
			lista.push_back(dato);
		}
		bin.close();
	}
	
	int size(){return cantidad;}
	///T getdato(int pos){return lista[pos];} ///esta es la forma facil si podemos usar vectores
    T getdato(int pos){///de esta forma es sin un vector xd
		///este caso es si solo piden acceder a un dato, si tenemos que reescribir el 
		///archivo si o si necesitamos la clase vector, y claramente un vector auxiliar para escribir toda la shit
		fstream bin(nomarch,ios::binary|ios::in);
		T dato;
		bin.seekg(pos*sizeof(dato));
		bin.read(reinterpret_cast<char*>(&dato),sizeof(dato));
		bin.close();
		return dato;
	}
	
	///aca se escribe sobre un byte determinado, por lo que no hace falta usar vector
	///¿donde usar vector? cuando se requiera un auxiliar
	/// en criollo: tenes que sacar un dato a la bosta y que no exista mas.,
	void putdato(int pos){
		fstream bin(nomarch,ios::binary|ios::out);
		T dato;
		bin.seekg(pos*sizeof(dato));
		bin.write(reinterpret_cast<char*>(&dato),sizeof(dato));
		bin.close();
	}
	
	

};

int main(int argc, char *argv[]) {
	
	ManejaArchivo<int>m("datosint.dat");
	
	
	return 0;
}

