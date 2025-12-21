#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Puntuacion{
	char nombreJugador[50];
	int puntaje;
};

class TablaPuntuaciones{
private:
	string nombreArchivo;
	Puntuacion* puntuaciones;
	int capacidad;
	int cantidad;
	
public:
	TablaPuntuaciones(string archivo, int maxPuntuaciones) {
		nombreArchivo = archivo;
		capacidad = maxPuntuaciones;
		cantidad = 0;
		puntuaciones = new Puntuacion[capacidad];
		
		cargarDesdeArchivo();
	}
	
	~TablaPuntuaciones() {
		guardarEnArchivo();
		delete[] puntuaciones;
	}
	
	// ? VERSIÓN SIMPLE: Lee registro por registro
	void cargarDesdeArchivo() {
		ifstream archivo(nombreArchivo, ios::binary);
		
		if (!archivo.is_open()) {
			cout << "Archivo nuevo, tabla vacía" << endl;
			cantidad = 0;
			return;
		}
		
		// Lee cuántos hay
		archivo.read((char*)&cantidad, sizeof(int));
		
		// Lee uno por uno con un FOR
		for (int i = 0; i < cantidad; i++) {
			archivo.read((char*)&puntuaciones[i], sizeof(Puntuacion));
		}
		
		archivo.close();
		cout << "Cargados " << cantidad << " puntajes" << endl;
	}
	
	// ? VERSIÓN SIMPLE: Guarda registro por registro
	void guardarEnArchivo() {
		ofstream archivo(nombreArchivo, ios::binary);
		
		if (!archivo.is_open()) {
			cout << "Error al guardar" << endl;
			return;
		}
		
		// Guarda cuántos hay
		archivo.write((char*)&cantidad, sizeof(int));
		
		// Guarda uno por uno con un FOR
		for (int i = 0; i < cantidad; i++) {
			archivo.write((char*)&puntuaciones[i], sizeof(Puntuacion));
		}
		
		archivo.close();
		cout << "Guardados " << cantidad << " puntajes" << endl;
	}
	
	// ? VERSIÓN SIMPLE: Inserción más directa
	void insertarPuntaje(string nombre, int puntaje) {
		// Si está llena y el puntaje no califica, descarta
		if (cantidad == capacidad && puntaje <= puntuaciones[cantidad-1].puntaje) {
			cout << "? No califica (puntaje muy bajo)" << endl;
			return;
		}
		
		// Busca dónde va
		int posicion = 0;
		while (posicion < cantidad && puntuaciones[posicion].puntaje > puntaje) {
			posicion++;
		}
		
		// Mueve todos hacia abajo desde esa posición
		for (int i = cantidad - 1; i >= posicion; i--) {
			if (i + 1 < capacidad) {
				puntuaciones[i + 1] = puntuaciones[i];
			}
		}
		
		// Inserta el nuevo
		strcpy(puntuaciones[posicion].nombreJugador, nombre.c_str());
		puntuaciones[posicion].puntaje = puntaje;
		
		// Incrementa si no estaba llena
		if (cantidad < capacidad) {
			cantidad++;
		}
		
		cout << "? Insertado en posición " << (posicion + 1) << endl;
	}
	
	void mostrar() {
		cout << "\n==== TOP " << capacidad << " ====" << endl;
		for (int i = 0; i < cantidad; i++) {
			cout << (i+1) << ". " << puntuaciones[i].nombreJugador 
				<< " - " << puntuaciones[i].puntaje << endl;
		}
		cout << endl;
	}
};

int main() {
	TablaPuntuaciones tabla("puntajes.dat", 5);
	
	tabla.mostrar();
	
	// Prueba insertando varios
	tabla.insertarPuntaje("Ana", 1000);
	tabla.insertarPuntaje("Luis", 1500);
	tabla.insertarPuntaje("Maria", 800);
	tabla.insertarPuntaje("Carlos", 2000);
	tabla.insertarPuntaje("Pedro", 1200);
	
	tabla.mostrar();
	
	// Intenta uno que no califica
	tabla.insertarPuntaje("Jorge", 500);
	
	// Intenta uno que SÍ califica
	tabla.insertarPuntaje("Sofia", 1800);
	
	tabla.mostrar();
	
	return 0;
}
