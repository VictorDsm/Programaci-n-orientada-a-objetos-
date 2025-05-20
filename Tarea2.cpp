#include <iostream>
#include <cmath> // Para M_PI

using namespace std;

class Triangulo {
public:
    float base, altura;

    
    Triangulo(float b = 1, float h = 1) {
        base = b;
        altura = h;
    }

    float calcularArea() const {
        return (base * altura) / 2;
    }
};

class Circulo {
public:
    float radio;

    
    Circulo(float r = 1) {
        radio = r;
    }

    float calcularArea() const {
        return M_PI * radio * radio;
    }
};

int main() {
    
    Triangulo t1;
    Circulo c1;

    
    Triangulo t2(3, 4); // base = 3, altura = 4
    Circulo c2(2);      // radio = 2

    cout << "Triángulo por defecto (base=1, altura=1):" << endl;
    cout << "Área: " << t1.calcularArea() << endl;

    cout << "\nTriángulo personalizado (base=3, altura=4):" << endl;
    cout << "Área: " << t2.calcularArea() << endl;

    cout << "\nCírculo por defecto (radio=1):" << endl;
    cout << "Área: " << c1.calcularArea() << endl;

    cout << "\nCírculo personalizado (radio=2):" << endl;
    cout << "Área: " << c2.calcularArea() << endl;

    return 0;
}
