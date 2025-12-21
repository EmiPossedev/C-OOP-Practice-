#include <iostream>
#include <fstream>
using namespace std;
/**
Ejemplo de template con clase geneçérica para gestionar registros directamente 
sobre un archivo binario
La clase debe tener métodos para:
1) Obtener la cantidad de registros
2) Consultar un registro
3) Añadir un registro
4) Modificar un registro
**/

template<typename T>
class ArchivoBinario {
private:
	fstream bin; /* no hace falta destructor porque la clase se destruye sola
	cerrando el archivo abierto */
public:
	// Constructor que abre mi archivo binario
	ArchivoBinario(string nombreArchi) : bin(nombreArchi, ios::binary | ios::in | ios::out){}
	int CantDatos(){
		bin.seekg(0, ios::end); // me voy hasta el final
		return bin.tellg()/sizeof(T);
	}
	T GetValor(int i){
		bin.seekg(i*sizeof(T)); // Me vuelvo a la pos
		T f;
		bin.read(reinterpret_cast<char*>(&f), sizeof(T));
		return f;
	}
	void Agregar(T valor){
		bin.seekp(0, ios::end);
		bin.write(reinterpret_cast<char*>(&valor), sizeof(T));
	}
	void Modificar(int pos, T valor){
		bin.seekp(pos*sizeof(T));
		bin.write(reinterpret_cast<char*>(&valor), sizeof(T));
	}
	
};

/** El struct Par es innecesario, ya existe el pair en la biblioteca estándar
	Es solo con fines didacticos jajjaja
**/
// Si quiero especializar mi plantilla para un tipo de dato no primitivo
// Si en mi clase no le pedí utilizar operadores, no hace falta sobrecarga de operadores
// Solo le pedí un constructor por defecto
template<typename T1, typename T2>
struct Par{
	T1 primero;
	T2 segundo;
};

int main() {
	ArchivoBinario< Par<float, double> > archi("float.dat");
	
//	Utilizando un struct Par generico
	Par<int,double> p;
	p.primero = 0,
	p.segundo = 3.1416;
	
	Par<string,float> p2;
	p2.primero = "Hola mundo!";
	p2.segundo = 0.0;
	
	return 0;
}

