#include <iostream>
#include <vector>
using namespace std;

/*
Ej1 (30pts) a) Implemente una clase Funcion para modelar una función de un cine. 
Debe recibir en su constructor el nombre de la película, la cantidad total de
butacas, y el precio de cada entrada. Debe tener métodos para consultar estos
datos, para registrar la venta de una entrada, consultar la cantidad de butacas 
vendidas/disponibles y para calcular la recaudación de la función (cant de entradas
vendidas x precio de la entrada). b) Implemente una clase Cine que tenga un método 
para agregar una función, métodos para listar las funciones disponibles, un método 
para vender entradas (indicando el nro de función y la cantidad de entradas para esa
venta), y un método para conocer la recaudación total (sumando todas las funciones).
El método para vender entradas debe verificar si en esa función quedan suficientes 
entradas disponibles y retornar true/false indicando si pudo realizarse la venta. 
Nota: no se pide la función main, solo las dos clases
*/

/// Implemento la clase Funcion
class Funcion{
private:
	string pelicula;
	int cantButacasTotal;
	int cantButacasVendida= 0;
	float precio;
public:
	Funcion(){}
	Funcion(string peli, int total, float p): pelicula(peli), cantButacasTotal(total), precio(p) {}
	// Métodos para consultar los datos
	string VerPelicula() const { return pelicula;}
	int VerTotalButacas() const { return cantButacasTotal;}
	float VerPrecio() const { return precio;}
	// Metodo para vender entrada
	void VenderEntrada() { ++cantButacasVendida;}
	// Método para consultar la cantidad de butacas vendidas
	int VerCantVendida() const { return cantButacasVendida; }
	int VerCantTotal() const { return cantButacasTotal; }
	int VerCantDisponible() const { return cantButacasTotal-cantButacasVendida;}
	float VerRecaudacion() const { return precio*cantButacasVendida; }
	
};

/// Implemento la clase Cine
class Cine{
private: 
	vector<Funcion> funciones;
public:
	// Método para agregar una funcion al Cine
	void AgregarFuncion(Funcion f){ funciones.push_back(f);}
	int CantFunciones() const { return funciones.size();}
	Funcion& VerFuncion(int nro_funcion){return funciones[nro_funcion];}
	// Método para vender entradas
	bool VenderEntradas(int nro_funcion, int cantEntradas){
		// Si quiero vender entradas, tengo que verificar que todavía hayan disponibles
		if(funciones[nro_funcion].VerCantDisponible() >= cantEntradas){
			for(int i=0 ; i<cantEntradas ; i++) { 
				funciones[nro_funcion].VenderEntrada();
			}
				return true;
		}
		else {
		return false;
		}
	}
	float VerRecaudacionTotal() const {
		float total = 0.0;
		for(const Funcion &f : funciones){
			total += f.VerRecaudacion();
		}
		return total;
	}
	
};

int main() {
	
	return 0;
}

