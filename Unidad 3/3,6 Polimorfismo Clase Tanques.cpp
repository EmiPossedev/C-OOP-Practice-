#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.1416;
/*Una fábrica de tanques los hace de forma de cilindro y de esfera. En ambos 
envases debemos rotular el volumen en ??3 y el peso en ????. Modele una clase 
base Tanque con un constructor que reciba el peso, un método para consultarlo, 
y un método virtual para calcular su volumen. Modele la clase hija Cilindro que 
se construirá a partir de los argumentos adicionales radio y altura, cuya 
fórmula de volumen es: área de la base * altura, donde el área de
la base se calcula como ?? * radio2; y otra clase hija Esfera con el radio 
como argumento adicional, cuya fórmula de volumen es: 4 3 * ?? * radio3. En 
el programa principal debe usar un único puntero de tipo Tanque para crear primero
un Cilindro y mostrar su volúmen, y luego una Esfera y también mostrar su volúmen.
*/

class Tanque{
private:
	float peso;
public:
	Tanque(){}
	Tanque(float p): peso(p){}
	virtual float CalcularVolumen() = 0;
	float MostrarPeso(){return peso;}
	virtual ~Tanque(){}
};

class Cilindro : public Tanque{
private: 
	float radio;
	float altura;
public:
	Cilindro(){}
	Cilindro(float p, float r, float a): Tanque(p), radio(r), altura(a){}
	float CalcularVolumen() override {
		return pi*radio*radio*altura;
	}
};

class Esfera : public Tanque{
private:
	float radio;
public:
	Esfera(){}
	Esfera(float p, float r): Tanque(p) ,radio(r){}
	float CalcularVolumen() override {
		return (4.0/3.0) * pi * pow(radio,3);
	}
};

int main() {
	
	Tanque *t = nullptr;
	t = new Cilindro(100, 2, 5);
	cout << "Volumen de Cilindro: " << t->CalcularVolumen() << " m3." << endl;
	cout << "Peso del Cilindro: " << t -> MostrarPeso() << endl;
	delete t;
	
	t = new Esfera(80, 3);
	cout << "Volumen de Esfera: " << t->CalcularVolumen() << " m3."<< endl;
	delete t;
	
	return 0;
}

