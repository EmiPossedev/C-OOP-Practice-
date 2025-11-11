#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
Se tiene un archivo inscriptos.txt con una lista de nombres de alumnos
inscriptos al cursado de Fundamentos de Programación. Se desea distribuir los 
estudiantes en comisiones de práctica de no más de 30 alumnos. Escriba un 
programa que determine cuantas comisiones deberían formarse de acuerdo a la 
cantidad de inscriptos y reparta los alumnos en comisiones de igual tamaño 
(igual dentro de lo posible podría ser que algunas comisiones tengan un alumno 
más que las otras), guardando la lista de alumnos de cada comisión en archivo
de texto comision1.txt, comision2.txt, … comisionN.txt.
Ayuda: puede utilizar la clase stringstream como auxiliar para concatenar en 
un string texto y números para formar
los nombres de los archivos.
*/

void LeerLista(string nombreArchivo, vector<string> &lista){
	ifstream archiLectura(nombreArchivo);
	if(!archiLectura.is_open()){ throw runtime_error("No se pudo abrir el archivo para lectura."); }
	string nombre;
	while(getline(archiLectura,nombre)){
		lista.push_back(nombre);
	}
	archiLectura.close();
}

void GenerarComisiones(const int &cantAlumnosPorCom){
	int nro = 1;
	int conteo = 0;
	string nombre;
	ofstream archiEscritura("Comision"+to_string(nro)+".txt");
	if(!archiEscritura.is_open()){ throw runtime_error("No se pudo abrir el archivo para escritura");}
	ifstream archiLectura("Inscriptos.txt");
	if(!archiLectura.is_open()){ throw runtime_error("No se pudo abrir el archivo para lectura");}
	while(getline(archiLectura,nombre)){
		archiEscritura << nombre << endl;
		conteo++;
		if(conteo == cantAlumnosPorCom){
			archiEscritura.close();
			conteo = 0;
			nro++;
			archiEscritura.open("Comision"+to_string(nro)+".txt");
		}
	}
	archiEscritura.close();
	archiLectura.close();
}
	
	
int main() {
	
	int cantPorComision = 0;
	vector<string>lista;
	LeerLista("Inscriptos.txt",lista);
	cout << lista.size() << " inscriptos." << endl;
	cout << "Ingrese la cantidad de alumnos por comision: ";
	cin >> cantPorComision;
	/// Acá genero las comisiones
	GenerarComisiones(cantPorComision);
	
	return 0;
}

