#include <iostream>

using namespace std;

template <class T>
bool busquedaSecuencial(T* arreglo, int tamano, T valor) {
    
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == valor) {
            return true;
        }
    }
    return false;
}

int main() {
    char arreglo[] = {'a', 'b', 'c', 'd', 'e'};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    bool resultado = busquedaSecuencial(arreglo, tamano, 'd');
    cout<<resultado<<endl;
    return 0;
}