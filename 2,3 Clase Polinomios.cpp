#include <iostream>
using namespace std;

/*Ejercicio 3
Dise�e una clase Polinomio que contenga:
1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
2. un m�todo que permita cambiar un coeficiente.
3. un m�todo evaluar que permita evaluar el polinomio para un valor dado de la variable x.
4. el/los m�todos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
5. una funci�n que permita sumar dos polinomios retornando un tercer polinomio con el resultado
(ej. p_res = Sumar(p1, p2);). �C�mo variar�a si en lugar de ser una funci�n 
libre fuera un m�todo de la clase? Verifique el funcionamiento de la funci�n Sumar(...) 
mediante un programa cliente
*/

class Polinomio {
private:
	int *coef; // Array din�mico para los coeficientes
	int grado;
	
public:
	// Constructor por defecto
	Polinomio (int g): grado(g), coef(new int[grado+1]){ // creo un array din�mico con +1 por el T.I
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

