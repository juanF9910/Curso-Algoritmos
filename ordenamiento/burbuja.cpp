#include <iostream>
#include <vector>
using namespace std;

/* En este código vamos a realizar el ordenamiento de un array siguiendo el método burbuja */
/*los números más pequeños suben hasta el inicio del arreglo, ordenamos de menor a mayor*/

template <class T>
void cambiar_pos(T* lista, int i, int j){
    T aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}


template <class T>    
void burbuja(T* lista, int n){
    for(int i = 0; i < n; i++){ //recorro la lista n veces 
        for(int j = 0; j < n-i-1; j++){ //en cada recorrido voy desde el inicio hasta el penúltimo elemento
            if(lista[j] > lista[j+1]){
                cambiar_pos(lista, j, j+1);
            }
        }
    }
}

int main(){
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();
    burbuja(&lista[0], n);  // Pasamos el vector por referencia
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}

