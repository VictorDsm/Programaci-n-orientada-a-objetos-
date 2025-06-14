#include <iostream>
#include <cmath>
using namespace std;

// Interfaz
class Figura {
public:
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Figura() {}
};

// Triángulo equilátero
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double area() const override {
        return (base * altura) / 2;
    }

    double perimetro() const override {
        return base * 3;
    }

    void mostrar() const override {
        cout << "Triangulo\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimetro: " << perimetro() << "\n\n";
    }
};

// Círculo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double area() const override {
        return M_PI * radio * radio;
    }

    double perimetro() const override {
        return 2 * M_PI * radio;
    }

    void mostrar() const override {
        cout << "Circulo\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimetro: " << perimetro() << "\n\n";
    }
};

// Fábrica
class FiguraFactory {
public:
    static Figura* crear(string tipo) {
        if (tipo == "triangulo") return new Triangulo(3, 4);
        if (tipo == "circulo") return new Circulo(2.5);
        return nullptr;
    }
};

// Principal
int main() {
    Figura* f1 = FiguraFactory::crear("triangulo");
    Figura* f2 = FiguraFactory::crear("circulo");

    if (f1) f1->mostrar();
    if (f2) f2->mostrar();

    delete f1;
    delete f2;

    return 0;
}
