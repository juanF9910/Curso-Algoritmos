#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &v, int left, int right) {
    if (left >= right) return;
    
    int i = left, j = right;
    double pivot = v[(left + right) / 2];
    while (i <= j) {
        while (v[i] < pivot) i++; //me muevo en la lista izquierda hasta encontrar un elemento mayor al pivote
        while (v[j] > pivot) j--; //me muevo en la lista derecha hasta encontrar un elemento menor al pivote
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (left < j) quicksort(v, left, j);
    if (i < right) quicksort(v, i, right);
}

int main(){

    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quicksort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}