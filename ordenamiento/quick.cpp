/*algoritmo quicksort*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
int particion(vector<T>& lista, int inicio, int fin){
    T pivote = lista[inicio]; //tomamos el primer elemento como pivote
    int i = inicio + 1; //el índice i empieza en el segundo elemento
    int f = fin; //el índice f empieza en el último elemento
    while(i <= f){
        if(lista[i] <= pivote){ //si el elemento en i es menor o igual al pivote
            i++; //incrementamos i
        }else if(pivote < lista[f]){ //si el elemento en f es mayor al pivote
            f--; //decrementamos f
        }else{
            swap(lista[i], lista[f]); //intercambiamos los elementos
        }
    }
    swap(lista[inicio], lista[f]); //intercambiamos el pivote con el elemento en f
    return f; //retornamos f
}

template <class T>
void quicksort(vector<T>& lista, int inicio, int fin){
    if(inicio < fin){ //si el inicio es menor al fin
        int pivote = particion(lista, inicio, fin); //particionamos la lista
        quicksort(lista, inicio, pivote - 1); //llamamos recursivamente a quicksort con la mitad izquierda
        quicksort(lista, pivote + 1, fin); //llamamos recursivamente a quicksort con la mitad derecha
    }
}

int main(){
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();
    quicksort(lista, 0, n-1); //llamamos a quicksort
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}
