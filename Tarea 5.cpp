#include <iostream>
using namespace std;

int main() {
    int opcion;

    cout << "===== MENU =====" << endl;
    cout << "1. Saludar" << endl;
    cout << "2. Sumar dos numeros" << endl;
    cout << "3. Salir" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Hola! Este es un saludo." << endl;
    } else if (opcion == 2) {
        int a, b;
        cout << "Ingresa dos numeros: ";
        cin >> a >> b;
        cout << "La suma es: " << a + b << endl;
    } else if (opcion == 3) {
        cout << "Saliendo del programa..." << endl;
    } else {
        cout << "Opcion no valida." << endl;
    }

    return 0;
}

