/*
implementareamos el algoritmo de ordenamiento merge 
recursivo
*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
void merge(vector<T>& lista, int inicio, int medio, int fin){
    int n1 = medio - inicio + 1; //tamaño de la mitad izquierda
    int n2 = fin - medio; //tamaño de la mitad derecha
    vector<T> izquierda(n1); //creamos un vector para la mitad izquierda
    vector<T> derecha(n2); //creamos un vector para la mitad derecha
    for(int i = 0; i < n1; i++){
        izquierda[i] = lista[inicio + i]; //llenamos el vector de la mitad izquierda
    }
    for(int i = 0; i < n2; i++){
        derecha[i] = lista[medio + 1 + i]; //llenamos el vector de la mitad derecha
    }
    int i = 0; //índice para la mitad izquierda
    int j = 0; //índice para la mitad derecha
    int k = inicio; //índice para la lista
    while(i < n1 && j < n2){
        if(izquierda[i] <= derecha[j]){ //si el elemento en la mitad izquierda es menor o igual al de la derecha
            lista[k] = izquierda[i]; //asignamos el elemento de la mitad izquierda a la lista
            i++; //incrementamos i
        }else{
            lista[k] = derecha[j]; //asignamos el elemento de la mitad derecha a la lista
            j++; //incrementamos j
        }
        k++; //incrementamos k
    }
    while(i < n1){
        lista[k] = izquierda[i]; //asignamos los elementos restantes de la mitad izquierda a la lista
        i++; //incrementamos i
        k++; //incrementamos k
    }
    while(j < n2){
        lista[k] = derecha[j]; //asignamos los elementos restantes de la mitad derecha a la lista
        j++; //incrementamos j
        k++; //incrementamos k
    }
}

template <class T>
void mergeSort(vector<T>& lista, int inicio, int fin){
    if(inicio < fin){ //si el inicio es menor al fin
        int medio = inicio + (fin - inicio) / 2; //sacamos la mitad de la lista
        mergeSort(lista, inicio, medio); //llamamos recursivamente a mergeSort con la mitad izquierda
        mergeSort(lista, medio + 1, fin); //llamamos recursivamente a mergeSort con la mitad derecha
        merge(lista, inicio, medio, fin); //mezclamos las dos mitades
    }
}

int main(){
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();
    mergeSort(lista, 0, n-1); //llamamos a mergeSort
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}