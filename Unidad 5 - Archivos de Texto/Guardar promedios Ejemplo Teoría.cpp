#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Alumno {
	string nombre;
	int n1, n2, n3;
};

int main() {
	ifstream archi("3 parciales.txt");
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo.");
	}
	
	vector<Alumno> v;
	Alumno a;
	
	/// Acá leo todos los datos
	while (getline(archi,a.nombre) && archi >> a.n1 >> a.n2 >> a.n3){
	// Y si la lectura funciona correctamente, guardo todo en mi vector
	cout << a.nombre << endl;
	cout << a.n1 << " " << a.n2 << " " << a.n3 << endl;
	v.push_back(a);
	archi.ignore();
	}
	archi.close(); // cierro el archivo luego de utilizarlo
	
	/// Acá guardo los promedios
	ofstream archi2("3 parciales.txt", ios::trunc);
	for(size_t i=0 ; i<v.size() ; i++) { 
		archi2 << v[i].nombre << endl;
		float prom = (v[i].n1 + v[i].n2 + v[i].n3) / 3.0;
		archi2 << prom << endl;
	}
	archi2.close(); // NO olvidarse de cerrar el archivo
	
	return 0;
}

