#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void bucketSort(vector<T> &arr) {
    int n = arr.size();

    // 1. Crear los buckets (cubos)
    vector<vector<T>> buckets(n);

    // 2. Distribuir los elementos en los buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Suponiendo que los elementos están en el rango [0, 1)
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. Ordenar los elementos dentro de cada bucket
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Concatenar los buckets ordenados
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    std::cout << "Array original: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr);

    std::cout << "Array ordenado: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}