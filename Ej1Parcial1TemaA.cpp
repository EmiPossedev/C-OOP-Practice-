#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Añadido para usar setw

using namespace std;

class Entrada{
private:
    int nroAsiento;
    string tipo;
    float precio;
    bool vendida; 
public:
    // Constructores
    Entrada(){}
    Entrada(int asiento, string tipoAsiento, float p): 
    nroAsiento(asiento), tipo(tipoAsiento), precio(p) { vendida = false;}
    // Metodos para consultar datos
    int MostrarAsiento() const {return nroAsiento;}
    string MostrarTipo() const {return tipo;}
    float MostrarPrecio() const {return precio;}
    bool EstaVendida() const {return vendida;}
    // Metodos para registrar la venta
    void vender(){vendida = true;}
};

class Show{
private:
    string nombre;
    vector<Entrada> entradas;
public:
    Show(){}
    Show(string n): nombre(n) {}
    // Metodos adicionales
    string VerNombre(){return nombre;}
    void HabilitarEntradas(string tipo, float precio, int desde, int hasta){
    for(size_t nro = desde ; nro <= hasta ; nro++){
        entradas.push_back(Entrada(nro,tipo,precio));
        }
    }
    bool Vender(int nroAsiento){
        for(size_t i = 0; i<entradas.size(): i++){
        if(entradas[i].MostrarAsiento() == nroAsiento and entradas[i].EstaVendida()==false){
            entradas[i].vender(); // La marco como vendida
            return true; // Devuelvo true como venta exitosa
        }
    }
        return false; // Si ya está vendida, retorno false como venta fallida
    }
    void consultarEntradas() const {
        cout << "Lista completa de entradas: " << endl;
        cout 
        << setw(10) <<"Nro de asiento " 
        << setw(10) << "Tipo "
        << setw(10) << "Precio "
        << setw(10) << "Estado" << endl;
        for(size_t i = 0; i<entradas.size(); i++){
            cout 
            << setw(10) << entradas[i].MostrarAsiento()
            << setw(10) << entradas[i].MostrarTipo()
            << setw(10) << entradas[i].MostrarPrecio();
            if(entradas[i].EstaVendida()) {
                cout << setw(10) << "Vendida";
            } else {
                cout << setw(10) << "Disponible";
            }
            cout << endl;
        }  
    }
};


int main(){


    return 0;
}