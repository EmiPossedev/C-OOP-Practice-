#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string nombreArchivo = "enteros.dat";
    int nuevoNumero;
    
    cout << "Ingrese el entero a insertar: ";
    cin >> nuevoNumero;
    
    // Abrir archivo en modo lectura/escritura
    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
    
    if(!archivo.is_open()){
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return 1;
    }
    
    // ===== PASO 1: Calcular cantidad actual de enteros =====
    archivo.seekg(0, ios::end);
    int cantidadActual = archivo.tellg() / sizeof(int);
    
    cout << "Cantidad actual de numeros: " << cantidadActual << endl;
    
    // ===== PASO 2: Buscar posición de inserción =====
    int posicionInsercion = 0;
    archivo.seekg(0, ios::beg);
    
    int numeroLeido;
    while(archivo.read(reinterpret_cast<char*>(&numeroLeido), sizeof(int))){
        if(numeroLeido >= nuevoNumero){
            // Encontramos la posición
            break;
        }
        posicionInsercion++;
    }
    
    cout << "Posicion de insercion: " << posicionInsercion << endl;
    
    // ===== PASO 3: Desplazar elementos hacia la derecha =====
    // Empezar desde el FINAL y mover hacia atrás
    for(int i = cantidadActual - 1; i >= posicionInsercion; i--){
        // Leer el elemento en posición i
        archivo.seekg(i * sizeof(int), ios::beg);
        int temp;
        archivo.read(reinterpret_cast<char*>(&temp), sizeof(int));
        
        // Escribirlo en posición i+1
        archivo.seekp((i + 1) * sizeof(int), ios::beg);
        archivo.write(reinterpret_cast<char*>(&temp), sizeof(int));
    }
    
    // ===== PASO 4: Insertar el nuevo número =====
    archivo.seekp(posicionInsercion * sizeof(int), ios::beg);
    archivo.write(reinterpret_cast<char*>(&nuevoNumero), sizeof(int));
    
    archivo.close();
    
    cout << "\nNumero " << nuevoNumero << " insertado exitosamente.\n" << endl;
    
    // ===== MOSTRAR RESULTADO =====
    archivo.open(nombreArchivo, ios::binary | ios::in);
    
    cout << "Contenido del archivo (primeros 20 numeros):" << endl;
    int contador = 0;
    while(archivo.read(reinterpret_cast<char*>(&numeroLeido), sizeof(int)) && contador < 20){
        cout << numeroLeido << " ";
        contador++;
    }
    cout << "..." << endl;
    
    archivo.close();
    
    return 0;
}
