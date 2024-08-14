#include <iostream>

using namespace std;
/*para la búsqueda binaria se necesita que el arreglo esté ordenado
de menor a mayor o de mayor a menor, los pasos son:
1. Seleccionar el elemento del medio del arreglo.
2. Si el elemento del medio es igual al valor buscado, se ha encontrado el valor.
3. Si el elemento del medio es menor al valor buscado, se busca en la mitad derecha del arreglo.
4. Si el elemento del medio es mayor al valor buscado, se busca en la mitad izquierda del arreglo.
5. Se repiten los pasos 1 al 4 hasta que se encuentre el valor o se recorra todo el arreglo.
6. Si se recorre todo el arreglo y no se encuentra el valor, se devuelve falso.
*/
template <class T>
bool busquedaBinaria(T* arreglo, int tamano, T valor) {
    int inicio = 0;
    int fin = tamano - 1; 
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2; //sacamos la mitad del arreglo
        if (arreglo[medio] == valor) {
            return true;
        }
        if (arreglo[medio] < valor) {
            inicio = medio + 1; //modifico el inicio para tomar la mitad de la derecha
        } else {
            fin = medio - 1; //modifico el fin para tomar la mitad de la izquierda
        }   
    }    
    return false;
}

int main() {
   int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    bool resultado = busquedaBinaria(arreglo, tamano, 5);
    cout<<resultado<<endl;
    return 0;
}