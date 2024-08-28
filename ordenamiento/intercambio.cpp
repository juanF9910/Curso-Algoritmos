/*
implementaremos el algoritmo de ordenamiento por intercambio
*/
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void intercambio(vector<T> &lista, int n){

    for(int i = 0; i < n - 1; i++){ //+indice del elemento que quiero comparae
        for(int j = i + 1; j < n; j++){ // índice de los elementos a comparar
            if(lista[i] > lista[j]){ //si el elemento en la posición i es mayor al elemento en la posición j
                swap(lista[i], lista[j]); //intercambiamos los elementos
            }
        }
    }

}

int main(){
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();
    intercambio(lista, n); //llamamos a intercambio
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}