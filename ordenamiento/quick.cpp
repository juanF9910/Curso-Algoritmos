#include <iostream>
#include <vector>
using namespace std;

template <class T>
int particion(vector<T> &lista, int inicio, int fin){ //esta función particiona la lista(por referencia) una vez
    //primero debe seleccionarse un pivote, en este caso se selecciona el primer elemento,
    // todos los elementos menores a este se colocan a la izquierda y los mayores a la derecha
    T pivote = lista[inicio]; 
    int i = inicio + 1; //el índice i empieza en el segundo elemento
    int f = fin; //el índice f empieza en el último elemento
    while(i <= f){ 
        if(lista[i] <= pivote){ //si el elemento en i es menor o igual al pivote
            i++; //me aceroo más a la mitas desde la izquierda
        }else if(pivote < lista[f]){ //si el elemento en f es mayor al pivote
            f--; //me acerco más a la mitad desde la derecha
        }else{ //si el elemento en i es mayor al pivote y el elemento en f es menor o igual al pivote
            swap(lista[i], lista[f]); //intercambiamos los elementos
        }
    }
    swap(lista[inicio], lista[f]); //ponemos el pivote en la posición f y ahora en nuevo pivote es f
    return f; //retornamos f que es la posición del pivote
}

template <class T>
void quicksort(vector<T>& lista, int inicio, int fin){
    if(inicio < fin){ //si el inicio es menor al fin
        int pivote = particion(lista, inicio, fin); //particionamos la lista y las ordena por referencia
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

/* la complejidad de quicksort es O(n log n) en el caso promedio y O(n^2) en el peor caso
*/
