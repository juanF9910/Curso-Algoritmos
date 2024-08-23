#include <iostream>

using namespace std;    

/*
los pasos de este algoritmo son:
    1. Buscar el elemento más pequeño en la lista
    2. Intercambiarlo con el primer elemento
    3. Buscar el siguiente elemento más pequeño y repetir el proceso
    4. Repetir hasta que la lista esté ordenada
*/

template <class T>
void ord_seleccion(T* lista, int n){

    for(int i = 0; i < n-1; i++){

        int min = i; //asumimos que el primer elemento es el más pequeño

        for(int j = i+1; j < n; j++){ //recorremos la lista desde el segundo elemento
            if(lista[j] < lista[min]){ //si encontramos un elemento más pequeño
                min = j;
            }
        }
        //procedemos a intercambiar los elementos
        T aux = lista[i];
        lista[i] = lista[min]; //en la posición i pongo el que era el mínimo
        lista[min] = aux; //ponemos en la posición del mínimo a aux
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