#include <iostream>
#include <string>
#include <vector>
using namespace std;
/// Inicio Clase Persona
class Persona{
private:
	string apenom;
	int fecha_nacimiento;
public:
	Persona(string ap, int fn):apenom(ap), fecha_nacimiento(fn){}
	Persona(){}
	string Ver_nombre(){return apenom;}
	int CalcularEdad(int fac){return (fac - fecha_nacimiento)/10000;}
};
/// Fin Clase Persona

/// Inicio Clase Alumno
class Alumno : public Persona{
	float prom; int cantMat;
public: 
	// Constructor
	Alumno(string an, int fn, float p, int cm): Persona(an,fn), prom(p), cantMat(cm){}
	Alumno(){}
	void AgregarMateria(int nueva_nota){
		prom = ((prom*cantMat) + nueva_nota) / cantMat+1;
		cantMat++;
	}
		float VerProm(){return prom;}
		
		int VerCantMat(){return cantMat;
		}
		
		int CalcularMeritoAcademico(){
			return prom*cantMat;
		}
};
/// Fin Clase Alumno

/// Inicio Clase Docente
class Docente : public Persona{
	int fecha_Ingr;
public:
	// Constructor de clase Docente
	Docente(string ap, int fn, int fecIng): Persona(ap,fn), fecha_Ingr(fecIng){}
	Docente(){}
	int CalcularAntiguedad(int fac){return (fac-fecha_Ingr)/10000;}
};
/// Fin clase Docente

/// Creo Clase Curso por composicion
class Curso{
	string materia;
	Docente profesor;
	int cupoMax;
	vector<Alumno> alumnos;
public: 
	// Defino los constructores
	Curso(string nomMat, Docente d, int cantMaxAlum): materia(nomMat), profesor(d), cupoMax(cantMaxAlum){} 
	Curso(){};
	
	void AgregarAlumno(Alumno &a){
		if(alumnos.size() < cupoMax){
			alumnos.push_back(a);
		}
	}
		float MejorPromedio(){
			int mayorProm = alumnos[0].VerProm();
			for(size_t i=1;i<alumnos.size();i++) { 
				if(alumnos[i].VerProm() > mayorProm){
					mayorProm = alumnos[i].VerProm();
				}
			}
			return mayorProm;
		}
			
			void MostrarAlumnos(){
				for(size_t i=0;i<alumnos.size();i++) { 
					cout << "Nombre: " << alumnos[i].Ver_nombre() << " con promedio " << alumnos[i].VerProm() << " en " << alumnos[i].VerCantMat() << " materias." << '\n';
				}
			}
				
};
/// Final Clase Curso	

int main(int argc, char *argv[]) {
	
	Persona Tomi("Tomi Bourquin",20031221);
	cout << "Nombre Persona: " << Tomi.Ver_nombre() << '\n';
	cout << "Edad Persona: " << Tomi.CalcularEdad(20250905) << '\n';
	cout << '\n';
	Alumno Emi("Emi Posse", 20030926, 7.0, 6);
	cout << "Nombre Alumno: " << Emi.Ver_nombre() << '\n';
	cout << "Edad Alumno: " << Emi.CalcularEdad(20250926) << '\n';
	cout << "Promedio Alumno: " << Emi.VerProm() << '\n'; 
	cout << '\n';
	Docente Vallejos("Manuel Alfredo Vallejos", 19650530, 19950701);
	cout << "Nombre Docente: " << Vallejos.Ver_nombre() << '\n';
	cout << "Edad Docente: " << Vallejos.CalcularEdad(20250905) << '\n';
	cout << "Antiguedad en la facultad: " << Vallejos.CalcularAntiguedad(20250905) << '\n';
	cout << '\n';
	
	cout << "VAMOS A CREAR UN CURSO" << '\n';
	string nombreMat; int cantCupos;
	cout << "Ingrese el nombre de la materia: "; cin >> nombreMat;
	cout << "Ingrese la cantidad de cupos: "; cin >> cantCupos;
	Curso Poo(nombreMat, Vallejos, cantCupos);
	
	/// Rellenamos el vector Alumnos
	cout << "Llenemos el curso de alumnos!!" << '\n';
	for(int i=0;i<cantCupos;i++) { 
		string nombre; int fechaNac, cantMat; float prom;  
		cout << "Ingrese nombre: "; cin >> nombre;
		cout << "Ingrese fecha de nacimiento: "; cin >> fechaNac;
		cout << "Ingrese el promedio del alumno: "; cin >> prom;
		cout << "Ingrese la cantidad de materias: "; cin >> cantMat;
		Alumno nuevo(nombre, fechaNac, prom, cantMat);
		Poo.AgregarAlumno(nuevo);
	}
	cout << '\n';
	cout << "VAMOS A VER LOS ALUMNOS EN EL CURSO" << '\n';
	Poo.MostrarAlumnos();
	
	return 0; 
}
