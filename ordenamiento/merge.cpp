/*
implementareamos el algoritmo de ordenamiento merge 
recursivo
*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
void merge(vector<T> &lista, int inicio, int medio, int fin){ //función para mezclar dos mitades de la lista 

    int n1 = medio - inicio + 1; //tamaño de la mitad izquierda
    int n2 = fin - medio; //tamaño de la mitad derecha
    
    vector<T> izquierda(n1); //creamos un vector para la mitad izquierda, EL () se usa para inicializar el vector, el número de elementos es n1
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

    while(i < n1 && j < n2){ //
        if(izquierda[i] <= derecha[j]){ //si el elemento en la mitad izquierda es menor o igual al de la derecha
            lista[k] = izquierda[i]; //asignamos el elemento de la mitad izquierda a la lista
            i++; //incrementamos i
        }else{
            lista[k] = derecha[j]; //asignamos el elemento de la mitad derecha a la lista
            j++; //incrementamos j
        }
        k++; //incrementamos k
    }

    while(i < n1){ //si quedan elementos en la mitad izquierda por asignar a la lista los asignamos
        lista[k] = izquierda[i]; //asignamos los elementos restantes de la mitad izquierda a la lista
        i++; //incrementamos i
        k++; //incrementamos k
    }

    while(j < n2){ //si quedan elementos en la mitad derecha por asignar a la lista los asignamos
        lista[k] = derecha[j]; //asignamos los elementos restantes de la mitad derecha a la lista
        j++; //incrementamos j
        k++; //incrementamos k
    }
}

template <class T>
void mergeSort(vector<T>& lista, int inicio, int fin){ /*entregamos una lista por referencia, el índice del inicio y del índice del final de la lista*/

    if(inicio < fin){ //si el inicio es menor al fin, caso base o condición de parada
        int medio=(inicio+fin)/2; 
        mergeSort(lista, inicio, medio); //ordenamos la mitad izquierda de la lista
        mergeSort(lista, medio + 1, fin); //ordenamos la mitad derecha de la lista
        merge(lista, inicio, medio, fin); //mezclamos las dos mitades que ya están ordenadas.
    }
}

int main(){
    vector<int> lista = {5, 3, 1, 4, 2, 5, 7, 8, 8, 2, 3};
    int n = lista.size();
    mergeSort(lista, 0, n-1); //llamamos a mergeSort
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}

