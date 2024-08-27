#include <iostream>
#include <vector>
using namespace std;


void imprimir(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
// Función para encontrar la solución al problema del peso total
bool encontrar_peso_total(int indice, int peso_restante, const vector<int> &pesos, vector<int> &solucion, int n) {
    if (peso_restante == 0) { // Si el peso restante es 0, entonces hemos encontrado una solución
        return true; //condición de parada
    }
    if (indice == n) { // Si hemos recorrido todos los elementos del conjunto y no hemos encontrado una solución
        return false; //condición de parada
    }

    // Exploramos el caso en el que el elemento actual no se incluye en la solución
    if (encontrar_peso_total(indice + 1, peso_restante, pesos, solucion, n)) {
        return true; // Si encontramos una solución, retornamos verdadero
    }

    // Si el peso restante es mayor o igual al peso del elemento actual, lo incluimos en la solución
    if (peso_restante >= pesos[indice]) {
        solucion.push_back(pesos[indice]);

        //tarea básica
        if (encontrar_peso_total(indice + 1, peso_restante - pesos[indice], pesos, solucion, n)) {
            return true; 
        } else {
            solucion.pop_back(); // Si no encontramos una solución, quitamos el elemento del vector solución
        }
    }
    return false;
}

int main() {
    vector<int> pesos = {10, 7, 5, 18, 12, 20, 15}; // Pesos de los elementos del conjunto
    int peso_objetivo = 40; // Peso total que se debe hallar
    vector<int> solucion; // Vector para guardar la solución

    if (encontrar_peso_total(0, peso_objetivo, pesos, solucion, pesos.size())) {
        cout << "Solución encontrada: ";
        for (int peso : solucion) {
            cout << peso << " ";
        }
        cout << endl;
    } else {
        cout << "No hay solución" << endl;
    }

    return 0;
}