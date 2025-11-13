#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

/*
Con un software de tratamiento de imagenes llamado 
WellDesign se han generado 78 archivos con los nombres
”design1.wds”, ”design2.wds”, … ”design78.wds”. El
software fue creado para Windows XP. Estos archivos 
presentan el problema que en el sistema operativo Windows
10 al tratar de abrirlos con WellDesign presentan un
molesto mensaje. Al consultar al soporte técnico de
la empresa que desarrolló WellDesign nos mencionan
que si se modifica la cabecera de cada archivo se 
soluciona el problema. A partir del byte 178 se debe
reemplazar ”mswxp” por ”msw10”, y a partir del byte
239 reemplazar el valor entero 2003 por el valor 
2016. Escriba un programa en C++ que realice esas
correcciones en los 78 archivos almacenados.
*/

void CorregirArchivo(string nombreArchivo){
	fstream bin(nombreArchivo, ios::binary | ios::out | ios::in;)
	bin.seekp(178, ios::beg);
	bin.write("msw10",5);
	bin.seekp(239, ios::beg);
	int n = 2016;
	bin.write(reinterpret_cast<char*>(&n), sizeof(int));
	bin.close();
}

int main(){
	cout << "Iniciando el procesamiento de datos..." << endl;
	for(int i=0; i<78; i++){
		string nombreArchivoBinario = "design" + to_string(i) + ".wds";
		CorregirArchivo(nombreArchivoBinario);
	}

	return 0;
}