# Resumen de Sobrecarga de Operadores en C++

## Definición
La sobrecarga de operadores en C++ es una característica que permite redefinir el comportamiento de los operadores para tipos de datos definidos por el usuario. Esto significa que se pueden usar operadores como `+`, `-`, `*`, etc., con objetos de clases personalizadas, haciendo que su uso sea más intuitivo.

## Reglas
1. **Declaración**: La sobrecarga debe declararse como una función amiga o como un método de la clase.
2. **Número de argumentos**: La cantidad y el tipo de argumentos pueden variar, dependiendo del operador.
3. **Retorno**: El operador puede devolver un valor que depende de la operación realizada.
4. **No se pueden cambiar**: No se puede cambiar la precedencia o la asociatividad de los operadores.

## Operadores No Sobrecargables
Algunos operadores no pueden ser sobrecargados, como:
- `::` (alcance)
- `.` (miembro)
- `.*` (miembro de puntero)
- `?:` (ternario)
- `sizeof`

## Ejemplo Práctico de Sobrecarga
```cpp
#include <iostream>
using namespace std;

class Complejo {
public:
    float real, imag;

    Complejo(float r, float i) : real(r), imag(i) {}

    // Sobrecarga del operador +
    Complejo operator+(const Complejo& obj) {
        return Complejo(real + obj.real, imag + obj.imag);
    }

    void mostrar() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complejo c1(3.0, 2.0), c2(1.0, 7.0);
    Complejo c3 = c1 + c2; // Uso del operador sobrecargado
    c3.mostrar(); // Salida: 4.0 + 9.0i
    return 0;
}
```

## Ventajas
- **Legibilidad**: Hace que el código sea más fácil de leer y utilizar.
- **Intuición**: Permite que los objetos se comporten como tipos de datos primitivos.
  
## Desventajas
- **Confusión**: Puede llevar a confusiones si no se utiliza correctamente.
- **Rendimiento**: La sobrecarga puede tener un costo en términos de rendimiento.

## Consideraciones para Escribir Código Limpio
1. **Consistencia**: Mantener un uso consistente de la sobrecarga de operadores en toda la clase.
2. **Simplicidad**: Evitar sobrecargar operadores de manera que puedan ser malinterpretados.
3. **Documentación**: Documentar el comportamiento sobrecargado de los operadores para que otros desarrolladores puedan entender su uso fácilmente.
