#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
En un archivo de texto llamado lista.txt, como el que se muestra en el recuadro, se 
encuentran los nombres y notas de los alumnos de una comisión de Programación Orientada a Objetos.
Lopez Javier
56 90
Garcia Ana
77 81
Farias Daniel
60 62
a) Escriba una función que reciba el nombre de un alumno y dos notas, y modifique el archivo 
reemplazando las dos notas de ese alumno.
b) Escriba una función que lea la lista del archivo y genere otro archivo de texto promedios.txt 
con una tabla donde cada línea posea el nombre, el promedio, y la condición final de cada uno de 
los alumnos. Ayuda: utilice manipuladores de flujo (setw, right, left, fixed, setprecision) para 
dar formato a la tabla del archivo que se genera en b.
*/

struct Alumno{
	string nombre;
	float n1, n2;
};

/// Empieza la funcion para modificar mi archivo
void ModificarAlumno(string &nombreBuscado, float nota1, float nota2){
	// Leo el archivo y lo paso todo a un vector
	ifstream archi("lista.txt");
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo para lectura");
	}
	vector<Alumno> v;
	Alumno a;
	bool encontrado = false;
	while(getline(archi, a.nombre)){
		archi >> a.n1 >> a.n2;
		archi.ignore();
		if(a.nombre == nombreBuscado){ // acá lo modifico
			a.n1 = nota1;
			a.n2 = nota2;
			encontrado = true;
			modi
		}
		v.push_back(a); // agrego los alumnos al vector
	}
	archi.close(); // cierro el archivo
	
	if(!encontrado){
		cout << "Alumno no encontrado en el archivo." << endl; // Aviso si no lo encuentro y lo muestro por consola
	}
	
	ostream archiSalida("lista.txt");
	if(!archiSalida.is_open()){
		throw runtime_error("No se pudo abrir el archivo para escritura");
	}
	for(const auto &v : v){
		archiSalida << alumno.nombre << endl;
		archiSalida << alumno.n1 << " " << alumno.n2 << endl;
	}
	archiSalida.close();
	if(encontrado){ cout << "Modificación exitosa." << endl;}
} 
	/// Termina la funcion para modificar mi archivo 
	
	/// Comienza la funcion para crear el archivo promedio
	void GenerarPromedios(){
		ifstream archiSalida
	}
	
int main(){
	vector<Alumno> v;
	ifstream archi("lista.txt");
	
	
	return 0;
}
