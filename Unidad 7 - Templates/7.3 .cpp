#include <iostream>
using namespace std;

/// Funciones para generar secuencias de datos, serán usadas por punteros a funciones
int getint(){return 100 + rand()% 400;}  /// generar int aleatorios
float getfloat(){return (100 + rand()% 400) / 1.345;}
string getstr() {
	string s(5+rand()%5, 'a'); // entre 5 y 10 'a's
	for (char &c : s) c += rand()%('z'-'a'); // sumandole algo entre 0 y 27
	return s;
}
template<typename T>
class VectorDinamico{
private:
	T *v;
	int n;
public:
	VectorDinamico(int cant):n(cant){
		v = new T[n];
	}
	
	/// templatizamos el constructor para poder pasarle un puntero a
	/// funcion
	template<typename PFunc>
	VectorDinamico(int cant, PFunc f) { // 4.
		v = new T[n];
		for (int i=0; i<n; ++i)	v[i] = f();
		n = cant;
	}
	int size(){return n;}
	T getdato(int i){return v[i];}
	
	~VectorDinamico(){delete []v;}
};

int main() {
	VectorDinamico<int>v(10,getint);
	for(int i=0;i<v.size();i++) { 
		cout<<v.getdato(i)<<"  ";
	}
	cout<<endl<<endl;
	VectorDinamico<string>vs(10,getstr);
	for(int i=0;i<vs.size();i++) { 
		cout<<vs.getdato(i)<<"  ";
	}
	return 0;
}

