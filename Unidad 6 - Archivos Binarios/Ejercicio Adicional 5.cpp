#include <iostream>
#include <fstream>
using namespace std;
/**
Proponga una clase Persona para representar a una persona a partir de su 
nombre, apellido y fecha de nacimiento con día, mes y año. Diseñe una clase 
llamada RecursosHumanos que permita manejar los datos de un grupo de personas.
La clase debe poseer métodos para:
	1. Guardar los datos de las personas en un archivo binario.
	2. Cargar los datos de las personas desde un archivo binario.
	3. Agregar una persona.
	4. Eliminar una persona a partir de su nombre o apellido.
	5. Indicar la cantidad de personas en la base de datos.
**/
class Persona{
private:
	string nombreApellido;
	int fechaNacimiento; // formato diaMesAño.
public:
	Persona(){}
	Persona(string nom, int fechaNac) : nombreApellido(nom), fechaNacimiento(fechaNac){}
	void CorregirDatos(string nomCorregido, int nacimientoCorregido){
		nombreApellido = nomCorregido;
		fechaNacimiento = nacimientoCorregido;
	}
};

class RecursosHumanos{
private:
	vector<Persona> personas;
public:
	RecursosHumanos(){}
	RecursosHumanos(){}
	void GuardarEnArchivoBinario(string nombreArchivoBinario){
		fstream bin(nombreArchivoBinario, ios::binary);
		if (!bin.is_open()){
			throw runtime_error("No se pudo guardar los datos en un archivo binario.");
		}
		
		bin.read(reinterpret_cast<char*>)
		
	}
};

int main() {
	
	return 0;
}

