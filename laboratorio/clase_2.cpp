#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para std::lower_bound

using namespace std; 

class SortedList {

    private:
        vector<string> seenStrings; // lista en la que guardamos las cadenas de acuerdo a su orden alfabético

        bool binary_search(const vector<string>& vec, const string& target); // método de búsqueda binaria
        string minuscula(const string& str); // Método para convertir a minúsculas.
        
    public:
        SortedList(); 

        void add(const string& str); // Método add para agregar cadenas en orden alfabético

        bool check(const string& str); // Método check para buscar si una cadena ya fue agregada
};

SortedList::SortedList() {
    seenStrings = vector<string>(); // inicializamos el vector de cadenas

}

// Método para convertir una cadena a minúsculas
string SortedList::minuscula(const string& str) { //en este caso como queremos tener una lista ordenada debemos tener en cuenta las minúsculas y mayúsculas
//que se manejan de forma diferente en el código ASCII, mezclar mayúsculas y minúsculas puede generar errores en la comparación de cadenas.
    string lowerStr = str;
    for (char& c : lowerStr) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // Convertimos a minúsculas sumando 32 (diferencia entre 'A' y 'a' en ASCII).
        }
    }
    return lowerStr;
}

// Método de búsqueda binaria
bool SortedList::binary_search(const vector<string>& vec, const string& target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

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

// Método para añadir cadenas de manera ordenada
void SortedList::add(const string& str) {
    string lowerStr = minuscula(str); // Convertimos la cadena a minúsculas antes de agregarla.

    int left = 0;
    int right = seenStrings.size() - 1;

    // Implementación de búsqueda binaria para encontrar la posición correcta
    while (left <= right) {
        int mid = (left + right) / 2;

        if (seenStrings[mid] == lowerStr) {
            // La cadena ya existe, no hacer nada
            return;
        }
        else if (seenStrings[mid] < lowerStr) {
            left = mid + 1;  // Buscar en la mitad derecha
        }
        else {
            right = mid - 1;  // Buscar en la mitad izquierda
        }
    }

    // Insertar la cadena en la posición encontrada
    seenStrings.insert(seenStrings.begin() + left, lowerStr); // Agregamos la cadena en la posición correcta
}

// Método para verificar si una cadena ya ha sido añadida
bool SortedList::check(const string& str) {
    string lowerStr = minuscula(str); // Convertimos la cadena a minúsculas antes de buscar.
    return binary_search(seenStrings, lowerStr); // Llama a la búsqueda binaria.
}

int main() {
    SortedList sl;

    sl.add("hola");
    sl.add("mundo");
    sl.add("Hola");

    cout << sl.check("hola") << endl;  // 1
    cout << sl.check("MUNDO") << endl; // 1, convierte a minúsculas 
    cout << sl.check("adios") << endl; // 0

    return 0;
}

/*
COMPLEJIDAD ESPACIAL: El vector seenStrings almacena n cadenas de tamaño promedio m, por lo que la complejidad espacial es O(n*m).

COMPLEJIDAD TEMPORAL: 
- El método `check` usa la búsqueda binaria, que tiene una complejidad temporal de O(log_2 n) ya que divide en cada iteración el vector a la mitad y 
también usa la función `minuscula` que tiene una complejidad O(m) 
debido a que recorre cada letra de la cadena. Por lo tanto, la complejidad temporal de `check` es O(log_2 n) + O(m) = O(m) en el peor caso, es decir, si todas 
letras con mayúsculas, si todas son minúsculas de entrada la complejidad sería O(log_2 n).
- El método `add` también usa búsqueda binaria para encontrar la posición correcta con complejidad O(log_2 n), y luego inserta el string 
en la posición correcta con complejidad O(n) debido al desplazamiento de los elementos en el vector, además también usa la función `minuscula` 
por lo que la complejidad temporal de `add` es O(n).
*/