#include <iostream>
#include <cmath> // Para M_PI

using namespace std;

class Triangulo {
public:
    float base, altura;
    
    Triangulo(float b=1, float h=1) {
        base=b;
        altura=h;
    }
    float calcularArea() const {
        return (base*altura)/2;
    }
};

class Circulo {
public:
    float radio;
    
    Circulo(float r=1) {
        radio=r;
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

    cout << "Triangulo por defecto (base=1, altura=1):" << endl;
    cout << "Area: " << t1.calcularArea() << endl;

    cout << "\nTriangulo personalizado (base=3, altura=4):" << endl;
    cout << "Area: " << t2.calcularArea() << endl;

    cout << "\nCirculo por defecto (radio=1):" << endl;
    cout << "Area: " << c1.calcularArea() << endl;

    cout << "\nCirculo personalizado (radio=2):" << endl;
    cout << "Area: " << c2.calcularArea() << endl;

    return 0;
}
