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

void ModificarAlumno(string &nombreBuscado, float nota1, float nota2, string &nombreArchivo){
	ifstream archi(nombreArchivo);
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo para lectura");
	}
	vector<Alumno> v;
	Alumno a;
	bool encontrado = false;
	/// Acá guardo los datos para sobreescribirlos en mi archivo luego
	while(getline(archi,a.nombre)){
		archi >> a.n1 >> a.n2;
		archi.ignore();
		if(a.nombre == nombreBuscado){
			a.n1 = nota1;
			a.n2 = nota2;
			encontrado = true;
		}
		v.push_back(a);
	}
	archi.close();

	return v;
}


int main(){
	vector<Alumno> v;
	ifstream archi("lista.txt");
	

	return 0;
}