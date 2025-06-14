#include <iostream>
using namespace std;

// Interfaz del repositorio
class IRepoFigGeo {
public:
    virtual void SaveArea(float area) = 0;
    virtual ~IRepoFigGeo() {}
};

// Repositorio MySQL
class RepoMySql : public IRepoFigGeo {
public:
    void SaveArea(float area) override {
        cout << "[MySQL] Area guardada: " << area << endl;
    }
};

// Repositorio CSV
class RepoCSV : public IRepoFigGeo {
public:
    void SaveArea(float area) override {
        cout << "[CSV] Area guardada: " << area << endl;
    }
};

// Clase base para figuras
class FigGeo {
protected:
    float area;
    IRepoFigGeo* repo;
public:
    FigGeo(IRepoFigGeo* r) : area(0), repo(r) {}
    virtual float calcArea() = 0;
    virtual void PrintDetails() = 0;

    void saveArea() {
        area = calcArea();
        if (repo) repo->SaveArea(area);
    }
};

// Cuadrado
class Square : public FigGeo {
    float lado;
public:
    Square(float l, IRepoFigGeo* r) : FigGeo(r), lado(l) {}

    float calcArea() override {
        return lado * lado;
    }

    void PrintDetails() override {
        cout << "Cuadrado -> lado = " << lado << ", area = " << area << endl;
    }
};

// Triángulo
class Triangle : public FigGeo {
    float base, altura;
public:
    Triangle(float b, float h, IRepoFigGeo* r) : FigGeo(r), base(b), altura(h) {}

    float calcArea() override {
        return (base * altura) / 2;
    }

    void PrintDetails() override {
        cout << "Triangulo -> base = " << base << ", altura = " << altura << ", area = " << area << endl;
    }
};

// Círculo
class Circle : public FigGeo {
    float radio;
public:
    Circle(float r, IRepoFigGeo* repo) : FigGeo(repo), radio(r) {}

    float calcArea() override {
        return 3.14 * radio * radio;
    }

    void PrintDetails() override {
        cout << "Circulo -> radio = " << radio << ", area = " << area << endl;
    }
};

// Programa principal
int main() {
    RepoMySql mysql;
    RepoCSV csv;

    Square c1(2.0, &mysql);
    c1.saveArea();
    c1.PrintDetails();

    Triangle t1(3.0, 4.0, &mysql);
    t1.saveArea();
    t1.PrintDetails();

    Circle cir1(1.5, &csv);
    cir1.saveArea();
    cir1.PrintDetails();

    return 0;
}
