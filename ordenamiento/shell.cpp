#include <iostream>
#include <vector>
using namespace std;

template <class T>
void shellSort(vector<T> &lista, int n) {
    // El bucle principal controla el tamaño del "salto" que determina cuántos
    // elementos hay en cada sublista. Comienza con la mitad del tamaño
    // del vector y se reduce a la mitad en cada iteración.
    for (int salto = n / 2; salto > 0; salto /= 2) {
        
        // Este bucle recorre la lista desde el índice 'salto' hasta el final.
        for (int i = salto; i < n; i++) {
            
            // Este bucle recorre hacia atrás desde el índice 'i' hasta el principio,
            // comparando y ordenando elementos que están separados por 'salto'.
            for (int j = i - salto; j >= 0; j -= salto) {
                
                // Si el elemento actual es mayor que el elemento en la posición 'salto' adelante,
                // intercambiamos los elementos.
                if (lista[j] > lista[j + salto]) {
                    swap(lista[j], lista[j + salto]);
                }
            }
        }
    }
}

int main() {
    // Definimos una lista de enteros que queremos ordenar.
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();  // Obtenemos el tamaño de la lista.
    
    // Llamamos a la función de ordenamiento Shell para ordenar la lista.
    shellSort(lista, n);
    
    // Imprimimos la lista ordenada.
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
    
    return 0;
}

//la complejidada de este algoritmo es O(n^2) en el peor de los casos y O(n log n) en el mejor de los casos