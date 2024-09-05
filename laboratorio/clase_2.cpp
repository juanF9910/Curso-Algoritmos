#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para std::lower_bound

using namespace std; 

class SortedList {

    private:
        vector<string> seenStrings; // lista en la que guardamos las cadenas de acuerdo a su orden alfabético

        bool binary_search(const vector<string>& vec, const string& target); // método de búsqueda binaria
        
    public:
        SortedList(); 

        void add(const string& str); // Método add para agregar cadenas en orden alfabético

        bool check(const string& str); // Método check para buscar si una cadena ya fue agregada
};

SortedList::SortedList() {
    seenStrings = vector<string>(); // inicializamos el vector de cadenas
}

bool SortedList::binary_search(const vector<string>& vec, const string& target) { // método de búsqueda binaria
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = (left + right)/ 2;

        // Comparación lexicográfica
        if (vec[mid] == target) {
            return true;  // El string ha sido encontrado
        }
        else if (vec[mid] < target) {
            left = mid + 1;  // Buscar en la mitad derecha
        }
        else {
            right = mid - 1;  // Buscar en la mitad izquierda
        }
    }

    return false;  // El string no está en el vector
}

void SortedList::add(const string& str) {
    int left = 0;
    int right = seenStrings.size() - 1;

    // Implementación de búsqueda binaria para encontrar la posición correcta
    while (left <= right) {
        int mid = (left + right) / 2;

        if (seenStrings[mid] == str) {
            // La cadena ya existe, no hacer nada
            return;
        }
        else if (seenStrings[mid] < str) {
            left = mid + 1;  // Buscar en la mitad derecha
        }
        else {
            right = mid - 1;  // Buscar en la mitad izquierda
        }
    }

    // Insertar la cadena en la posición encontrada contada desde el origen
    seenStrings.insert( seenStrings.begin()+left, str); //ponemos el nuevo string en la posición encontrada
}

bool SortedList::check(const string& str) {
    return binary_search(seenStrings, str);
}

int main() {
    SortedList sl;

    sl.add("hola");
    sl.add("mundo");
    sl.add("hola");

    cout << sl.check("hola") << endl;  // 1
    cout << sl.check("mundo") << endl; // 1
    cout << sl.check("adios") << endl; // 0

    return 0;
}

/*
COMPLEJIDAD ESPACIAL: el vector seenstrings guarda n cadenas de tamaño promedio m, por lo que la complejidad espacial es O(n*m)

COMPLEJIDAD TEMPORAL: la función check usa la búsqueda binaria que tiene una complejidad temporal de O(log_2 n) ya que divide 
en cada iteración a la mitad el vector, la función add también hace uso de la búsqueda binaria para encontrar la posición correcta con complejidad O(log_2 n)
y luego añade el string en la posición correcta con complejidad O(n), por lo que la complejidad temporal de add es O(n).

*/