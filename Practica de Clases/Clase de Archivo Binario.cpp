#include <iostream>
#include <fstream>
using namespace std;

struct Par{
	int prim;
	double seg;
};

int main(){

	ofstream archi("nuevobin.datos",ios::binary);
	if(not archi.is_open()){ // Necesito comprobar que el archivo esta abierto
		throw runtime_error("No se pudo abrir el archivo");
	}
	
	Par p;
	p.prim = 23;
	p.seg = 29.891;
	// Escribo los datos en mi nuevo archivo binario
	archi.write(reinterpret_cast<char*>(&p), sizeof(p));
	// Agrego mas datos
	Par g;
	g.prim = 1;
	g.seg = 2.001;
	archi.write()reinterpret_cast<char*>(&g), sizeof(g));

	cout<<"Archivo creado"<<endl;
	/// No olvidarme de cerrar el archivo
	archi.close();
return 0;
}