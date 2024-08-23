/*
implementación del algoritmo de ordenamiento shell
este algiritmo consta de las siguientes fases:
1. Seleccionar un número entero k tal que 2^k - 1 <= n, n es el tamaño de la lista
2. Dividir la lista en 2^k sublistas
3. Ordenar cada sublista
4. Repetir los pasos 1 a 3 con k = k - 1
5. Repetir hasta que k = 0

la complejidad de este algoritmo es O(n^2)
*/
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void shell(vector<T> &lista, int n){
    for(int salto = n / 2; salto > 0; salto /= 2){ //dividimos el tamaño de la lista entre 2
        for(int i = salto; i < n; i++){ //recorremos la lista
            for(int j = i - salto; j >= 0; j -= salto){ //recorremos la lista
                if(lista[j] > lista[j + salto]){ //si el elemento en la posición j es mayor al elemento en la posición j + salto
                    swap(lista[j], lista[j + salto]); //intercambiamos los elementos
                }
            }
        }
    }
}

int main(){
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();
    shell(lista, n); //llamamos a shell
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}