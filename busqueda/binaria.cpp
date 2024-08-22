#include <iostream>

using namespace std;

template <class T>
bool busquedaBinaria(T* arreglo, int tamano, T valor) {
    int inicio = 0;
    int fin = tamano - 1; 

    while(inicio <= fin) {
        int medio = (inicio + fin) / 2; //sacamos la mitad del arreglo
        
        if(arreglo[medio] == valor) {
            return true;
        }
        if (arreglo[medio] < valor) {
            inicio = medio + 1; //modifico el inicio para tomar la mitad de la derecha
        }else {
            fin = medio - 1; //modifico el fin para tomar la mitad de la izquierda
        }   
    }    
    return false;
}

template <class T>
bool busqueda_recursive(T* arreglo, T valor, int inicio, int fin){

    if (inicio > fin) {
        return false;
    }

    int medio = (inicio + fin) / 2; //sacamos la mitad del arreglo
    
    if (arreglo[medio] == valor) { //caso base o condición de parada
        return true;
    }
    if (arreglo[medio] < valor) {
        return busqueda_recursive(arreglo, valor, medio + 1, fin); //modifico el inicio para tomar la mitad de la derecha
    } else {
        return busqueda_recursive(arreglo, valor, inicio, medio - 1);  //modifico el fin para tomar la mitad de la izquierda
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    
    bool resultado = busquedaBinaria(arreglo, tamano, 5);
    bool resultado1 = busqueda_recursive(arreglo, 5, 0, tamano - 1);
    
    cout << "Resultado busquedaBinaria: " << resultado << endl;
    cout << "Resultado busqueda_recursive: " << resultado1 << endl;
    
    return 0;
}