#include <iostream>
#include <vector>
using namespace std;

/*
Considere el struct Alimento { string nombre, tipo; int calorias; }; Se 
quiere modelar la alimentación de ciertos animales, y para ello se los 
divide en carnívoros (solo comen alimento de tipo "carne"), herbívoros 
(solo comen alimentos de tipo "vegetal"), insectivoros (solo comen alimentos
de tipo "insecto"), y omnívoros (comen todo). Se quiere implementar cada 
tipo de animal en una clase propia (clases Carnivoro, Herbivoro, Omnivoro, 
Insectivoro). Cada clase debe: - poder definir en su constructor la especie 
del animal, y luego consultarla - tener un método "Comer" que reciba un 
"Alimento" y retorne verdadero si lo puede comer o falso si no - llevar 
internamente la cuenta de cuántas calorías consume (se deben sumar en el método 
comer) y luego poder consultar ese total. a) Defina solo 2 de las 4 clases 
propuestas: Herbivoro y Omnivoro; y cualquier otra clase extra que crea 
necesaria y/o conveniente para implementarlas. b) Implemente una función de 
prueba que reciba un animal (que debe poder ser cualquiera de los 4 tipos), 
y un vector de alimentos: la función debe intentar hacer comer al animal todos
los alimentos del vector, e informar cuáles rechaza y el conteo de calorías 
final de dicho animal. Nota: no se pide la función main, solo las clases y la 
función de prueba del b).
*/

//Considere el struct Alimento { string nombre, tipo; int calorias; };
struct Alimento{
	string nombre, tipo;
	int calorias;
};

/// Mi clase madre "Animal"
class Animal{
private:
	string especie;
protected:
	float calorias;
public:
	Animal(){}
	// Los metodos que me piden
	Animal(string e) : especie(e), calorias(0) {};
	int VerCalorias() const { return calorias; }
	string VerEspecie() const { return especie; }
	virtual bool Comer(Alimento a) = 0 ; 
	// Un destructor virtual
	virtual ~Animal(){}
};

/// Mi clase hija "Carnivoro"
class Carnivoro : public Animal {
public:
	Carnivoro(){}
	Carnivoro(string espec) : Animal(espec) {}
	bool Comer(Alimento a) override {
		if(a.tipo == "carne") {
			calorias += a.calorias;
			return true;
		} else {
			return false;
		}
	}
};

/// Mi clase hija "Herviboro"
class Herviboro : public Animal {
public:
	Herviboro(){}
	Herviboro(string espec): Animal(espec){}
	bool Comer(Alimento a) override {
		if(a.tipo == "vegetal") {
			calorias += a.calorias;
			return true;
		} else {
			return false;
		}
	}
};

/// Mi clase hija "Insectivoro"
class Insectivoro : public Animal {
public:
	Insectivoro(){}
	Insectivoro(string espec) : Animal(espec) {}
	bool Comer(Alimento a) override {
		if(a.tipo == "insecto"){
			calorias += a.calorias;
			return true;
		} else {
			return false;
		}
	}
};

/// Mi clase hija "Omnivoro"
class Omnivoro : public Animal {
public:
	Omnivoro(){}
	Omnivoro(string espec) : Animal(espec){}
	bool Comer(Alimento a) override {
		calorias += a.calorias;
		return true;
	}
};

/// Ahora hago la funcion que me pidieron para probar darle de Comer
/* 
Implemente una función de 
prueba que reciba un animal (que debe poder ser cualquiera de los 4 tipos), 
y un vector de alimentos: la función debe intentar hacer comer al animal todos
los alimentos del vector, e informar cuáles rechaza y el conteo de calorías 
final de dicho animal. Nota: no se pide la función main, solo las clases y la 
función de prueba del b).
*/

void ProbarAlimentos(Animal &chewbacca, const vector<Alimento> &a){
	for(size_t i=0 ; i<a.size() ; i++) { 
		// Un caso en el que le gusta la comida
		if(chewbacca.Comer(a[i])){
			cout << "Le gusta: " << a[i].nombre << endl;
		} else {
			cout << "No le gusta: " << a[i].nombre << endl;
		}
	}
	cout << "Cantidad de calorias final: " << chewbacca.VerCalorias() << " cal. " << endl;
}

	/// Hago un main de prueba
int main() {
	
	Herviboro chewbacca("chewbacca");
	vector<Alimento> v;
	cout << "Ingrese los datos de los alimentos del vector de alimentos" << endl;
	int cant;
	cout << "Cantidad de alimentos: ";
	cin >> cant;
	v.resize(cant);
	for(size_t i=0;i<v.size();i++) { 
		cout << "Ingrese el nombre del alimento: "; cin >> v[i].nombre;
		cout << "Ingrese el tipo del alimento(carne,vegetal,insecto): "; cin >> v[i].tipo;
		cout << "Ingrese la cantidad de calorias del alimento: "; cin >> v[i].calorias;		
	}
	
	ProbarAlimentos(chewbacca,v);
	
	return 0;
}

