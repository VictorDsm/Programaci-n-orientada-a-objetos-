#include <iostream>
#include <vector>
using namespace std;

// Clase base abstracta
class Figura {
public:
    virtual double area() = 0;  // Método virtual puro
    virtual ~Figura() {}        // Destructor virtual
};

// Clase Triángulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double area() override {
        return (base * altura) / 2.0;
    }
};

// Clase Cuadrado
class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double area() override {
        return lado * lado;
    }
};

// Clase Círculo
class Circulo : public Figura {
private:
    double diametro;
public:
    Circulo(double d) : diametro(d) {}
    double area() override {
        double radio = diametro / 2.0;
        return 3.1416 * radio * radio;
    }
};

int main() {
    // Arreglo de punteros a figuras
    vector<Figura*> figuras;
    figuras.push_back(new Triangulo(8, 4));
    figuras.push_back(new Cuadrado(5));
    figuras.push_back(new Circulo(10));

    // Mostrar áreas
    for (size_t i = 0; i < figuras.size(); ++i) {
        cout << "Área de la figura " << i + 1 << ": " << figuras[i]->area() << endl;
    }

    // Liberar memoria
    for (Figura* f : figuras) {
        delete f;
    }

    return 0;
}
