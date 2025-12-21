#include <iostream>
#include <vector>
using namespace std;

struct Persona {
	string nombre;string apellido;int dni;
};
template<typename T>
T mayor(vector<T>v){
	T m = v[0];
	for(int i=0;i<v.size();i++) if(v[i] > m)m=v[i];
	return m;
}
bool operator>(const Persona &p1, const Persona &p2) { // 3
	return p1.dni<p2.dni; // menor dni=más viejo
}	

int main() {
	vector<int>v(10);
	for(int i=0;i<10;i++) { 
		v[i] = 100 + rand() % 300;
		cout<<v[i]<< "  ";
	}
	cout<<endl<<endl;
	int may = mayor<int>(v);
	cout<<"El entero mayor es "<<may<<endl<<endl;
	
	vector<float>f(10);
	for(int i=0;i<10;i++) { 
		f[i] = (100 + rand() % 300) / 1.1123;
		cout<<f[i]<< "  ";
	}
	cout<<endl<<endl;
	float mayf = mayor<float>(f);
	cout<<"El float mayor es "<<mayf<<endl;
	cout<<endl<<endl;
	
	vector<Persona>p;
	p.push_back({"MANUEL","VALLEJOS",17222360});
	p.push_back({"GRACIELA","TABERNA",24818968});
	p.push_back({"AGUSTIN","VALLEJOS",48327156});
	
	Persona mayp = mayor<Persona>(p);
	cout<<"La persona mayor es "<<mayp.nombre<<" "<<mayp.apellido<<endl;
	
	return 0;
}

