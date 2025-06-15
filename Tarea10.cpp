#include <iostream>
using namespace std;

void ejemploBasico() {
    cout << "Ejemplo 1: Puntero basico a una variable\n";
    int x = 10;
    int* p = &x;

    cout << "Valor de x: " << x << "\n";
    cout << "Direccion de x: " << &x << "\n";
    cout << "Valor de p (direccion de x): " << p << "\n";
    cout << "Valor apuntado por p: " << *p << "\n\n";
}

void ejemploModificar() {
    cout << "Ejemplo 2: Modificar variable a traves de puntero\n";
    int x = 5;
    int* p = &x;

    *p = 20;

    cout << "Nuevo valor de x: " << x << "\n\n";
}

void ejemploArreglos() {
    cout << "Ejemplo 3: Punteros y arreglos\n";
    int arr[3] = {10, 20, 30};
    int* p = arr;

    cout << "Primer elemento: " << *p << "\n";
    cout << "Segundo elemento: " << *(p + 1) << "\n";

    cout << "Recorrer arreglo con punteros:\n";
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << *(p + i) << "\n";
    }
    cout << "\n";
}

void ejemploPunteroAPuntero() {
    cout << "Ejemplo 4: Punteros a punteros\n";
    int x = 50;
    int* p = &x;
    int** pp = &p;

    cout << "Valor de x: " << x << "\n";
    cout << "Valor apuntado por p: " << *p << "\n";
    cout << "Valor apuntado por pp: " << **pp << "\n\n";
}

void incrementar(int* p) {
    (*p)++;
}

void ejemploFuncion() {
    cout << "Ejemplo 5: Punteros y funciones\n";
    int x = 10;
    incrementar(&x);
    cout << "x despues de incrementar: " << x << "\n\n";
}

int main() {
    ejemploBasico();
    ejemploModificar();
    ejemploArreglos();
    ejemploPunteroAPuntero();
    ejemploFuncion();

    return 0;
}
