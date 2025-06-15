#include <iostream>
#include <vector>
using namespace std;

class RepoVector {
private:
    vector<float> areas;
public:
    // Guarda un area en el repositorio, regresa la nueva cantidad de elementos
    int Save(float area) {
        areas.push_back(area);
        return areas.size();
    }

    // Obtiene el area guardado en el indice dado, o -1 si no existe
    float GetArea(int index) {
        if (index >= 0 && index < (int)areas.size()) {
            return areas[index];
        }
        return -1.0f; // valor para indicar error
    }
};

int main() {
    RepoVector repo;

    repo.Save(12.5f);
    repo.Save(9.8f);
    repo.Save(15.3f);

    cout << "Area en indice 0: " << repo.GetArea(0) << "\n";
    cout << "Area en indice 2: " << repo.GetArea(2) << "\n";
    cout << "Area en indice 5 (no existe): " << repo.GetArea(5) << "\n";

    return 0;
}
