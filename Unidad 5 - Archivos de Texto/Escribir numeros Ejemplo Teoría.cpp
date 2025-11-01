#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	ofstream archi("GuardarNumerosEjemploDeTeoria .txt",ios::trunc);
	if(!archi.is_open()){
		throw runtime_error("No se pudo abrir el archivo.");
	}
	
	cout << "Vamos a guardar 10 numeros en mi archivo" << endl;
	for(int i=1;i<=10;i++) { 
		/* 
		Así sería si leo los datos
		int num;
		cout << "Ingrese el valor " << i <<": ";
		cin >> num;
		archi << num << endl; */
		archi << rand()%100 << " ";
	}
	archi.close();
	cout << "Los 10 numeros se guardaron exitosamente." << endl;
	
	return 0;
}

