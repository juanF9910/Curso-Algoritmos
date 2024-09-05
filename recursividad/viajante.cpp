#include <iostream>
#include <vector>
#include <algorithm>
//problema de knapsack o mochila, este problema se puede afrontar desde dos perspectivas, grafos o backtracking(programación dinámica)
using namespace std;

// Función para encontrar la mejor solución al problema del viaje usando backtracking
void encontrar_viajante(int indice, int peso_restante, int valor_actual, const vector<int> &pesos, 
    const vector<int> &valores, vector<int> &solucion, vector<int> &mejor_solucion, int n, int &mejor_valor) {
    
    if (peso_restante == 0) { // Si el peso restante es cero, significa que hemos encontrado una solución
    // ahora comparamos si es mejor que la mejor solución encontrada hasta ahora
        if (valor_actual > mejor_valor) { 
            mejor_valor = valor_actual;
            mejor_solucion = solucion;
        }
        return; //condición de parada
    }

    if (indice == n) { // Si hemos recorrido todos los elementos del conjunto
        return; //condición de parada
    }

    // Exploramos el caso en el que el elemento actual no se incluye en la solución
    encontrar_viajante(indice + 1, peso_restante, valor_actual, pesos, valores, solucion, mejor_solucion, n, mejor_valor);

    // Si el peso restante es mayor o igual al peso del elemento actual, lo incluimos en la solución
    if (peso_restante >= pesos[indice]) {
        solucion.push_back(indice);
        //tarea básica (básico para backtracking) es agregar el elemento actual a la solución y llamar a la función recursivamente

        //exploramos si el elemento actual se incluye en la solución 
        encontrar_viajante(indice + 1, peso_restante - pesos[indice], valor_actual + valores[indice], 
            pesos, valores, solucion, mejor_solucion, n, mejor_valor);
        
        //si con el elemento actual no se obtiene la mejor solución, lo quitamos de la solución
        solucion.pop_back(); // Quitamos el elemento del vector solución para explorar otras posibilidades
    }
}

// Función para imprimir la solución
void imprimir(const vector<int> &solucion) {
    for (int i : solucion) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> pesos = {10, 7, 5, 18, 12, 20, 15}; // Pesos de los elementos del conjunto
    vector<int> valores = {100, 70, 50, 180, 120, 200, 150}; // Valores de los elementos del conjunto
    int peso_objetivo = 40; // Peso máximo permitido
    vector<int> solucion; // Vector para guardar la solución actual
    vector<int> mejor_solucion; // Vector para guardar la mejor solución encontrada
    int mejor_valor = 0; // Mejor valor encontrado, se inicializa en 0

    encontrar_viajante(0, peso_objetivo, 0, pesos, valores, solucion, mejor_solucion, pesos.size(), mejor_valor);

    cout << "Mejor solución encontrada: ";
    imprimir(mejor_solucion);
    cout << "Valor total: " << mejor_valor << endl;

    return 0;
}

// la complejidad de el algoritmo de knapsack es O(2^n), ya que en cada 
// llamada recursiva se generan dos llamadas recursivas adicionales