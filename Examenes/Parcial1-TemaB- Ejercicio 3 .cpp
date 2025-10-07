#include <iostream>
#include <string>
using namespace std;

/*
(30pts) En la interfaz de una aplicación se necesitan varios tipos de botones que 
se distinguen por su comportamiento cuando se los presiona: hay botones que alternan 
entre 2 estados (prendido/apagado, como un interruptor de una luz), botones que hacen 
algo mientras se los mantiene presionados (como la tecla de un piano, que suena mientras 
esté presionada, o el botón de un timbre), y los botones que hacen algo solo la primera 
vez que se los presiona (como el botón de un detonador). Se quiere poder definir para 
cada tipo de botón una clase diferente (clases Interruptor, Tecla, Detonador). Cada una 
debe: - permitir definir en su constructor una etiqueta para el botón, y luego consultarla. 
- contar con un método presionar y otro soltar, que retornen true si la acción enciende el 
dispositivo conectado y false si lo apaga (por ejemplo: una tecla enciende al presionar y 
apaga al soltar; un detonador enciende solo la primera vez que se pulsa; un interruptor alterna 
entre encendido y apagado en cada presión). - un método para consultar el tipo de botón 
a) Defina las clases de solo 2 de los 3 tipos de botones (puede elegir cualquier par), y 
cualquier otra clase extra que crea necesaria y/o conveniente para implementarlas. 
b) Escriba una función de prueba que reciba un botón (que debe poder ser de cualquier tipo), 
informe en pantalla el tipo y la etiqueta; y luego lo presione y suelte 5 veces, informando 
en cada caso si enciende o apaga. Nota: no se pide la función main, solo las clases y la 
función de prueba del b).
*/

/// Clase Madre: Boton
class Boton {
private: 
	string tipo;
	string etiqueta;
public:
	// Defino un constructor que reciba su etiqueta y luego permita consultarla
	Boton(){}
	Boton(string t, string e): tipo(t),etiqueta(e) {}
	// Metodos para consultar su tipo y etiqueta
	string VerTipo() const { return tipo;}
	string VerEtiqueta() const { return etiqueta;}
	// Metodos para presionar y Soltar
	virtual bool Presionar() = 0;
	virtual bool Soltar() = 0;
	// No olvidarme del destructor si utilizo metodos virtuales en una clase Madre
	virtual ~Boton(){}
};

/// Clase Hija: Interruptor
class Interruptor : public Boton{
private: 
	bool encendido = false; // Unico atributo indicando si el Interruptor está encendido o no
public:
	Interruptor(){}
	Interruptor(string etiq): Boton("Interruptor",etiq) {};
	bool Presionar() override { 
		encendido = not encendido;
		return encendido;
	}
	bool Soltar() override {
		return encendido;
	}
};
/// Clase Hija: Detonador
class Detonador : public Boton {
private:
	bool primera_vez = true;
public:
	Detonador(){}
	Detonador(string etiq) : Boton("Detonador",etiq) {}
	bool Presionar() override {
		if(primera_vez) {
			primera_vez = false;
			return true;
		} else {
			return false;
		}
	}
	bool Soltar() override { return false;}
};

/// Clase Hija: Tecla
class Tecla : public Boton{
public:
	Tecla(){}
	Tecla(string etiq) : Boton("Tecla",etiq) {}
	// Una tecla enciende al presionar
	bool Presionar () override { return true; }
	// Y apaga al soltar
	bool Soltar () override { return false; }
};

/// Item B: La funcion de prueba
void Prueba(Boton &b){
	cout << "Tipo: " << b.VerTipo() << endl;
	cout << "Etiqueta: " << b.VerEtiqueta() << endl;
	for(int i=0 ; i<5 ; i++) { 
		if(b.Presionar()) {
			cout << "Encendido" << endl;
		} else {
			cout << "Apagado" << endl;
		}
		if(b.Soltar()){
			cout << "Encendido" << endl;
		} else {
			cout << "Apagado" << endl;
		}
	}
}

int main() {
		cout << "Ejercicio de Polimorfismo de BOTONES" << endl;
	return 0;
}

