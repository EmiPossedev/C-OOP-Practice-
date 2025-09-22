#include <iostream>
using namespace std;

/*Ejercicio 3
Diseñe una clase Polinomio que contenga:
1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
2. un método que permita cambiar un coeficiente.
3. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
4. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
5. una función que permita sumar dos polinomios retornando un tercer polinomio con el resultado
(ej. p_res = Sumar(p1, p2);). ¿Cómo variaría si en lugar de ser una función 
libre fuera un método de la clase? Verifique el funcionamiento de la función Sumar(...) 
mediante un programa cliente
*/

class Polinomio {
private:
	int *coef; // Array dinámico para los coeficientes
	int grado;
	
public:
	// Constructor por defecto
	Polinomio (int g): grado(g), coef(new int[grado+1]){ // creo un array dinámico con +1 por el T.I
	/// Inicializo todos los coeficientes en 0
	for(int i=0 ; i<=grado ; i++) { 
		*(coef+i) = 0;
		}
	}
	
	/// Constructor de copia
	Polinomio(const Polinomio &otro){
		grado = otro.grado;
		coef = new int[otro.grado+1];
		
		// Copio el contenido
		for(int i=0 ; i<=grado ; i++) { 
			*(coef+i) = *(otro.coef+i);
		}
	}
	
	
	
	/// Destructor para liberar memoria
	~Polinomio(){
		delete [] coef;
	}
};

int main() {

	
	
	return 0;
}

