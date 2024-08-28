#include <iostream>
#include <vector>
using namespace std;

/*los números más pequeños suben hasta el inicio del arreglo, ordenamos de menor a mayor*/
//LA LISTA está ordenada desde el final hasta la posición i
template <class T>

void cambiar_pos(T* lista, int i, int j){
    T aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}


template <class T>    
void burbuja(T* lista, int n){
    for(int i = 0; i < n; i++){ //recorro la lista n veces 

        for(int j = 0; j < n-i-1; j++){ //el -i es porque hasta la componente i el arreglo ya está ordenado    
            if(lista[j+1] < lista[j]){
                cambiar_pos(lista, j, j+1); //donde estaba j pongo el j+1 y viceversa
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

