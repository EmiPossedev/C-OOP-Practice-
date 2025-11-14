#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
/**
Implemente una función to_list que reciba un string conteniendo una 
lista de datos entre llaves y separados por coma, y retorne una 
std::list<string> con los datos individuales. Un ejemplo del string que recibe podría
ser "{FuPro,POO,AED,Ing Soft}"; y la std::list resultante debería 
contener 4 elementos: "FuPro", "POO", "AED", e "Ing Soft".

b) Implemente una función to_string que haga lo contrario: reciba una 
std::list<string> y  la convierta en un solo string con el formato del ejemplo 
(agregue las llaves y las comas para armar un único string).

c) Implemente una función reemplazar que reutilice las dos anteriores para 
reemplazar en una lista que recibe como un único string, un
elemento dado, por otro. La lista y ambos elementos son argumentos de la función:

Ej: reemplazar(“{FuPro,POO,AED}",
”POO”, ”Prog II”) cambiaría la lista por “{FuPro,Prog II,AED}". 
La función debe retornar true si realizó el reemplazo, false
si el elemento a reemplazar no estaba en la lista.
**/

list<string>to_list(string cadena){
	list<string>ls;
	string aux;
	cadena.erase(0,1); /// elimino {
	cadena.erase(cadena.length()-1,1); /// elimino }
	stringstream ss;
	ss<<cadena;
	while(getline(ss,aux,',')){
		ls.push_back(aux);
	}
	return ls;
}
/*
list<string>to_list2(string cadena){
	list<string>ls;
	string aux;
	cadena.erase(0,1); /// elimino {
	cadena.erase(cadena.length()-1,1); /// elimino }
	size_t pos = cadena.find(',');
	while(pos != string::npos){
		aux = cadena.substr(0,pos);
		ls.push_back(aux);
		cadena.erase(0,pos+1);
		pos = cadena.find(',');
	}
	ls.push_back(cadena);
	return ls;
}
*/
string to_string(const list<string> &ls){
	string aux = "";
	for(auto it = ls.begin(); it!= ls.end(); it++){
		if(aux == ""){
			aux = "{" + *it;}
		else{
			aux+="," + *it;
		}
	}
	aux+="}";
	return aux;
}

bool reemplazar(string &cadena, string buscado, string reemp){
	list<string>ls = to_list(cadena);
	auto it = find(ls.begin(),ls.end(),buscado);
	if(it != ls.end()){
		*it = reemp;
		cadena = to_string(ls);
		return true;
	}
	return false;
}
int main() {
    string aux = "{FuPro,POO,AED,Ing Soft}";
	
	list<string> ls = to_list(aux);
	for(auto it = ls.begin(); it!= ls.end(); it++){
		cout<<*it<<endl;
	}
	cout<<endl<<endl;
	cout<<to_string(ls)<<endl;
	cout<<endl<<endl;
	
	bool cambio =  reemplazar(aux,"FuPro","CAD II");
	if(cambio){
		cout<<aux<<endl;
	}
	
	return 0;
}

