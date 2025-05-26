#include <iostream>
#include <vector>
using namespace std;

class Figura {
public:
    virtual double area() = 0;  
    virtual ~Figura() {}        
};

class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double area() override {
        return (base * altura) / 2.0;
    }
};

class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double area() override {
        return lado * lado;
    }
};

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
  
    vector<Figura*> figuras;
    figuras.push_back(new Triangulo(8, 4));
    figuras.push_back(new Cuadrado(5));
    figuras.push_back(new Circulo(10));

    
    for (size_t i = 0; i < figuras.size(); ++i) {
        cout << "Área de la figura " << i + 1 << ": " << figuras[i]->area() << endl;
    }

    
    for (Figura* f : figuras) {
        delete f;
    }

    return 0;
}
