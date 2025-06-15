#include <iostream>
using namespace std;

class RepoArrFloat {
private:
    static const int MAX = 100;    // Tamaño maximo del arreglo
    float areas[MAX];
    int count;                    // Cuantos elementos se han guardado

public:
    RepoArrFloat() : count(0) {}

    // Guarda un area, devuelve indice o -1 si lleno
    int Save(float area) {
        if (count >= MAX) return -1; // arreglo lleno
        areas[count] = area;
        return count++;              // retorna indice donde guardo
    }

    // Obtiene area por indice, retorna -1 si indice invalido
    float GetArea(int index) {
        if (index < 0 || index >= count) return -1.0f;
        return areas[index];
    }

    // Para mostrar cuantas areas se guardaron
    int Size() const {
        return count;
    }
};

// Ejemplo de uso
int main() {
    RepoArrFloat repo;

    int i1 = repo.Save(12.5f);
    int i2 = repo.Save(20.3f);

    cout << "Area en i1: " << repo.GetArea(i1) << "\n";
    cout << "Area en i2: " << repo.GetArea(i2) << "\n";

    cout << "Total guardados: " << repo.Size() << "\n";

    return 0;
}
