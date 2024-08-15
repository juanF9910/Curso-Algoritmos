#include <iostream>
#include <vector>

using namespace std;

/*Este algoritmo también ordena de menor a mayor*/
/*los pasos son:
1. Seleccionar el primer elemento de la lista.
2. Si el elemento actual es menor al anterior, se intercambian.
3. Se repiten los pasos 1 y 2 hasta que se recorra toda la lista.

*/
template <class T>
void ord_insercion(T* lista, int n) {
    int pos;
    T aux; 
    //vamos a recorrer toda la lista
    for(int i=0; i<n; i++){
        pos=i; 
        aux=lista[i];
        //mientras la posición sea mayor a 0 y el elemento anterior sea mayor al actual
        while((pos>0) && (lista[pos-1]>aux)){
            lista[pos]=lista[pos-1]; //el elemento actual se convierte en el anterior
            pos--; //decrementamos la posición
        }
        lista[pos]=aux; //el elemento actual se convierte en el auxiliar

    }
}

int main() {
    vector<int> lista = {5, 3, 1, 4, 2};
    int n = lista.size();

    // Pasar el puntero al primer elemento del vector
    ord_insercion(&lista[0], n); //los vectores no se pueden pasar directamete como punteros
    //toca pasar el puntero al primer elemento del vector
    
    // Mostrar el vector ordenado
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
    return 0;
}