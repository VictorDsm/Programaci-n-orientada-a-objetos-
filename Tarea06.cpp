#include <iostream>
#include <cmath>
using namespace std;

// Interfaz de impresion
class FigPrinter {
public:
    virtual void imprimir(const string& nombre, double area, double perimetro) const = 0;
    virtual ~FigPrinter() {}
};

// Implementacion concreta que imprime en consola
class ConsolaFigPrinter : public FigPrinter {
public:
    void imprimir(const string& nombre, double area, double perimetro) const override {
        cout << nombre << "\n";
        cout << "Area: " << area << "\n";
        cout << "Perimetro: " << perimetro << "\n\n";
    }
};

// Interfaz de Figura
class Figura {
protected:
    FigPrinter* printer;
public:
    Figura(FigPrinter* p) : printer(p) {}
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Figura() {}
};

// Triangulo equilatero
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h, FigPrinter* p) : Figura(p), base(b), altura(h) {}

    double area() const override {
        return (base * altura) / 2;
    }

    double perimetro() const override {
        return base * 3;
    }

    void mostrar() const override {
        printer->imprimir("Triangulo", area(), perimetro());
    }
};

// Circulo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r, FigPrinter* p) : Figura(p), radio(r) {}

    double area() const override {
        return M_PI * radio * radio;
    }

    double perimetro() const override {
        return 2 * M_PI * radio;
    }

    void mostrar() const override {
        printer->imprimir("Circulo", area(), perimetro());
    }
};

// Fabrica
class FiguraFactory {
public:
    static Figura* crear(const string& tipo, FigPrinter* printer) {
        if (tipo == "triangulo") return new Triangulo(3, 4, printer);
        if (tipo == "circulo") return new Circulo(2.5, printer);
        return nullptr;
    }
};

// Principal
int main() {
    ConsolaFigPrinter printer;
    Figura* f1 = FiguraFactory::crear("triangulo", &printer);
    Figura* f2 = FiguraFactory::crear("circulo", &printer);

    if (f1) f1->mostrar();
    if (f2) f2->mostrar();

    delete f1;
    delete f2;

    return 0;
}
