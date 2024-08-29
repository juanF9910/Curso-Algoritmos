/*
implementaremos el algoritmo de ordenamiento raidix sort, este algoritmo es un algoritmo de ordenamiento no comparativo
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//función para obtener el dígito en la posición pos
int obtener_digito(int num, int pos){
    return (num / pos) % 10;
}

//función para obtener el dígito más grande
int obtener_digito_mas_grande(vector<int> &v){
    int max = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

//función para ordenar el vector v en la posición pos
void contar_sort(vector<int> &v, int pos){
    int n = v.size();
    vector<int> output(n);
    vector<int> count(10, 0); //inicializamos el vector count con 0
    for(int i = 0; i < n; i++){
        count[obtener_digito(v[i], pos)]++;
    }
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        output[count[obtener_digito(v[i], pos)] - 1] = v[i];
        count[obtener_digito(v[i], pos)]--;
    }
    for(int i = 0; i < n; i++){
        v[i] = output[i];
    }
}

//función para ordenar el vector v
void radix_sort(vector<int> &v){
    int max = obtener_digito_mas_grande(v);
    for(int pos = 1; max / pos > 0; pos *= 10){
        contar_sort(v, pos);
    }
}

int main(){
    vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radix_sort(v);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
