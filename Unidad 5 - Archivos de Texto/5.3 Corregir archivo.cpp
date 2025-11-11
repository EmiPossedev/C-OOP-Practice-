#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
Un conjunto de archivos de texto contiene información guardada en el formato
que se muestra en el recuadro, donde cada línea contiene el nombre de un campo
y su respectivo valor separados por el signo igual (=). Las líneas que 
comienzan con el carácter numeral (#) deben ser ignoradas.

#ejemplo de archivo de configuración
materia=Programacion Orientada a Objetos
carrera=Ingeniería en Informática
facultad=Facultad de Ingeniería y Ciencias Hídricas
universidad=Universidad Nacional del Litoral
#esta linea hay que ignorarla, igual que las 3 últimas
nro_unidad=5
nombre_unidad=Flujos de entrada/salida
otro_campo=otro_valor
otro_campo_mas=otro_valor_mas
#campo_que_no_se_lee_1=basura
#campo_que_no_se_lee_2=basura
#campo_que_no_se_lee_3=basura

Escriba una clase llamada ConfigFile que permita interpretar el contenido de 
estos archivos. La clase debe poseer:
• un constructor que reciba el nombre del archivo y cargue sus datos en un 
vector de structs (cada elemento es struct con dos strings: campo y valor).
• un método para consultar el valor asociado a un campo
• un método para modificar el valor asociado a un campo
• un método para guardar el archivo con los datos actualizados
Nota: es aceptable que al guardar el archivo luego de hacer cambios se pierdan 
los comentarios originales
*/
struct Dato{
	string campo, valor;
};
class ConfigFile{
private:
	string nombreArchivo;
	vector<Dato> datos;
public:
	ConfigFile(){}
	ConfigFile(string nombreArchi) : nombreArchivo(nombreArchi){
		string linea, variable, valor;
		int posDelIgual;
		ifstream archiLectura(nombreArchivo);
		if(!archiLectura.is_open()){
			throw runtime_error("No se pudo abrir el archivo para lectura.");
		}
		while(getline(archiLectura,linea)){
			if(linea.substr(0,1) != "#" ){
				posDelIgual = linea.find("=");
				Dato d;
				d.campo = linea.substr(0,posDelIgual);
				d.valor = linea.substr(posDelIgual + 1, linea.length() - posDelIgual);
				datos.push_back(d);
			}
		}
		
	}
	// Método para ver la cantidad de datos
	int GetCantidadDeDatos() const { return datos.size(); }
	// Método para ver un valor segun un indice
	Dato GetValor(int indice) { return datos[indice]; }
	// Método para modificar una variable
	void ModificarValor(string campoBuscado, string valorNuevo){
		for(size_t i=0;i<datos.size();i++) { 
			if(datos[i].campo == campoBuscado){
				datos[i].valor = valorNuevo;
			}
		}
	}
	// Método para actualizar el archivo
	void ActualizarArchivo() {
		ofstream archiEscritura(nombreArchivo);
		if(!archiEscritura.is_open()){
			throw runtime_error("No se pudo abrir el archivo para escritura.");
		}
		for(size_t i=0;i<datos.size();i++) { 
			archiEscritura << datos[i].campo << " = " << datos[i].valor << endl;
		}
		archiEscritura.close();
	}	
};

int main() {
	ConfigFile c("Config1.txt");
	for(int i=0;i<c.GetCantidadDeDatos();i++) { 
		Dato d = c.GetValor(i);
		cout<<d.campo<<" = "<<d.valor<<endl;
	}
	cout<<endl<<endl;
	string campo,valor;
	cout<<"Ingrese nombre de variable : ";
	cin >> campo;
	cin.ignore();
	cout << "Ingrese nuevo valor de " << campo << " : ";
	getline(cin,valor);
	c.ModificarValor(campo,valor);
	c.ActualizarArchivo();
	return 0;
}

