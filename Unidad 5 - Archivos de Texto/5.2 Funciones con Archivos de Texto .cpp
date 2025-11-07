#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
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
void ModificarAlumno(const string &nombreBuscado, float nota1, float nota2, const string &nombreArchivo){
	// Leo el archivo y lo paso todo a un vector
	ifstream archi(nombreArchivo);
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
		}
		v.push_back(a); // agrego los alumnos al vector
	}
	archi.close(); // cierro el archivo
	
	if(!encontrado){
		cout << "Alumno no encontrado en el archivo." << endl; // Aviso si no lo encuentro y lo muestro por consola
	}
	
	ofstream archiSalida(nombreArchivo);
	if(!archiSalida.is_open()){
		throw runtime_error("No se pudo abrir el archivo para escritura");
	}
	for(const auto &alumno : v){
		archiSalida << alumno.nombre << endl;
		archiSalida << alumno.n1 << " " << alumno.n2 << endl;
	}
	archiSalida.close();
	if(encontrado){ cout << "Modificación exitosa." << endl;}
}
/// Termina la funcion para modificar mi archivo 

/// Comienza la funcion para crear el archivo promedio
void GenerarPromedios(const string &nombreArchivo){
	// Aqui leo el archivo y lo guardo en un vector que voy a utilizar para escritura
	ifstream archiEntrada(nombreArchivo);
	if(!archiEntrada.is_open()){
		throw runtime_error("No se pudo abrir el archivo para lectura.");
	}
	vector<Alumno> v;
	Alumno a;
	while(getline(archiEntrada,a.nombre)){
		archiEntrada >> a.n1 >> a.n2;
		archiEntrada.ignore();
		v.push_back(a);
	}
	archiEntrada.close(); // NO olvidarse de cerrar el archivo
	
	ofstream archiSalida("promedios.txt");
	if(!archiSalida.is_open()){
		throw runtime_error("No se pudo abrir el archivo para escritura.");
	}
	// Aquí hago el encabezado con Nombre, Promedio y Condicion
	// decido el espacio en base a la cant de caracteres que reservé por columna
	archiSalida << left << setw(20) << "Nombre"
				<< right << setw(10) << "Promedio"
				<< setw(15) << "Condición" << endl;
	archiSalida << string(45,'-') << endl; // linea separadora 
	
	for(const Alumno &alumno: v){
		float promedio = (alumno.n1 + alumno.n2) / 2.0;
		string condicion; 
		if(promedio >= 60){
			condicion = "aprobado";
		} else { condicion = "reprobado";}
		
		archiSalida << left << setw(20) << alumno.nombre
			<< right << setw(10) << fixed << setprecision(2) << promedio
			<< setw(15) << condicion << endl;
		
	}
	archiSalida.close();
	cout << "Archivo promedios.txt creado exitosamente." << endl;
}
/// Termina la funcion para crear el archivo promedio
int main(){
	string nombreArchivo;
	cout << "Ingrese el nombre del archivo: ";
	cin >> nombreArchivo;
	cin.ignore();
	string nombreAlumno;
	cout << "Ingrese el nombre del alumno que quiera modificar: ";
	getline(cin,nombreAlumno);
	float nota1, nota2;
	cout <<"Ingrese las notas del primer y segundo examen: ";
	cin >> nota1 >> nota2;	
	ModificarAlumno(nombreAlumno,nota1,nota2,nombreArchivo);
	GenerarPromedios(nombreArchivo);
	
	return 0;
}
