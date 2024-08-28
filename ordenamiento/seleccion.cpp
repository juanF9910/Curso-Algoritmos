#include <iostream>

using namespace std;    

/*
los pasos de este algoritmo son:
    1. Buscar el elemento más pequeño en la lista
    2. Intercambiarlo con el primer elemento
    3. Buscar el siguiente elemento más pequeño y repetir el proceso
    4. Repetir hasta que la lista esté ordenada
*/

//LA LISTA  QUE QUEDA A LA IZQUIERDA DE LA POSICIÓN i ESTÁ ORDENADA
template <class T>
void ord_seleccion(T* lista, int n){
    for(int i = 0; i < n-1; i++){ //recorro cada componente

        //SELECCIONO EL MÍNIMO COMO ELEMENTO EN EL QUE VOY

        int min = i; //la lista que está detrás de i ya está ordenada, ent asumimos que i es el menor elemento de la lista no ordenada 
        for(int j = i+1; j < n; j++){ //recorremos la lista desde el segundo elemento HASTA el último   
            if(lista[j] < lista[min]){ //si encontramos un elemento más pequeño
                min = j;
            }
        }
        swap(lista[i], lista[min]); //intercambiamos el elemento más pequeño con el primer elemento
    }
}

int main(){
    
    int lista[] = {5, 3, 1, 4, 2};
    int n = sizeof(lista)/sizeof(lista[0]);
    ord_seleccion(lista, n);
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}