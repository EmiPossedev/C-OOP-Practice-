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

#include <iostream>
#include <fstream>
using namespace std;

struct Par{
	int prim;
	double seg;
};

int main(){
	fstream archi("nuevobin.datos", ios::binary | ios::in | ios::ate);
	if(not archi.is_open()){throw runtime_error("No se pudo abrir el archivo");}
	int tam_bytes = arfchi.tellg();
	int cant = tam_bytes / sizeof(Par);
	archi.seekg(0);
	Par p;
	for(int i=0;i<cant;i++){
				archi.read(reinterpret_cast<char*>(&p), sizeof(p));
				cout << p.prim << " " << p.seg << endl;
}

// No hay que olvidarse de cerrar el archivo	
archi.close();

return 0
}

/*
OBSERVACIONES: 
-No se pueden grabar objetos en un archivo binario ni nada que involucre punteros
-Hay que grabar dato por dato


#include <iostream>
#include <fstream>
using namespace std;
struct par{int prim; double seg;};
int main(int argc, char *argv[]) {
	fstream archi("nuevobin.dat",ios::binary|ios::in|ios::out|ios::ate);
	if (not archi.is_open())
		throw runtime_error("No se pudo abrir el archivo");
	
	int tam_bytes=archi.tellg();
	int cant=tam_bytes/sizeof(par);
	archi.seekg(0,ios::beg);
	par p;
	for (int i=0; i <cant; i++)
	{  archi.read(reinterpret_cast<char*>(&p),sizeof(p));
	   cout<<p.prim<<" "<<p.seg<<endl;	}	
	p.prim=100; p.seg=33.339;
	//modificar el 3er par en el archivo binario
	chi.seekg(2*sizeof(p),ios::beg);
	archi.write(reinterpret_cast<char*>(&p),sizeof(p));
	archi.close();
	return 0;	
}

/*
#include <iostream>
#include <fstream>
using namespace std;
struct par{int prim; double seg;};
int main(int argc, char *argv[]) {
	ofstream archi("nuevobin.dat",ios::binary);
	if (not archi.is_open())
		throw runtime_error("No se pudo abrir el archivo");
	
	par p;
	p.prim=23; p.seg=29.891;
	archi.write(reinterpret_cast<char*>(&p), sizeof(p));
	
	p.prim=40; p.seg=81.311;
	archi.write(reinterpret_cast<char*>(&p), sizeof(p));
	
	p.prim=55; p.seg=3.877;
	archi.write(reinterpret_cast<char*>(&p), sizeof(p));
	
	cout<<"Archivo creado"<<endl;
	archi.close();
	return 0;
}
*/










