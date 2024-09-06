#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Definimos una clase Node que representa un nodo que contiene un vector de 26 punteros que apuntan a otros nodos (uno para cada letra del alfabeto) 
y un booleano que indica si el nodo es el final de una palabra. */

class Node {
    public:
        vector<Node*> lista; // Vector de punteros a nodos hijos, uno por cada letra del alfabeto (26 en total).
        bool isEndOfWord; // Indica si el nodo es el final de una palabra en el Trie.

        // Constructor: inicializa el nodo como no terminal (isEndOfWord = false) 
        // y el vector children con 26 posiciones, todas apuntando a nullptr.
        Node() : isEndOfWord(false), lista(26, nullptr) {}
};

// Clase que representa el sitema completo.
class Sistema {

    private:
        Node* root; // Puntero a la raíz del sistema, que siempre está vacía al inicio.

        // Convierte un carácter a su índice correspondiente en el vector (0 a 25).
        // Si el carácter está en mayúsculas, se convierte primero a minúsculas.

        int charToIndex(char c) { //esta función tiene una complejidad O(1)
            if (c >= 'A' && c <= 'Z') {
                c += 32; // Convertimos la letra a minúsculas si está en mayúsculas.
            }
            return c - 'a'; // Retorna el índice de la letra (0 para 'a', 1 para 'b', ..., 25 para 'z').
        }

    public:
        // Constructor: inicializa el sistema enlazado creando un nodo raíz vacío.
        Sistema() {
            root = new Node(); // Inicializamos la raíz del Trie con un nuevo nodo.
        }

        // Método para añadir una palabra al
        void add(const string& str) {
            Node* node = root; // Comenzamos desde la raíz del sistema
            for (char c : str) {
                int index = charToIndex(c);  // Convertimos la letra a un índice entre 0 y 25.
                if (node->lista[index] == nullptr) { // Si no hay nodo para la letra actual, lo creamos.
                    node->lista[index] = new Node();
                }
                node = node->lista[index];  // Avanzamos al nodo correspondiente a la letra actual.
            }
            node->isEndOfWord = true;  // Marcamos el último nodo como final de la palabra.
        }

        // Método para verificar si una palabra existe en el Trie.
        bool check(const string& str) {
            Node* node = root;  
            for (char c : str) {
                int index = charToIndex(c);  // Convertimos la letra minúscula a índice.
                if (node->lista[index] == nullptr) { // Si no existe el nodo para la letra actual, la palabra no está en
                    return false;
                }
                node = node->lista[index];  // Avanzamos al nodo correspondiente.
            }
            return node->isEndOfWord;  // Verificamos si el último nodo es el final de una palabra válida.
        }
};

int main() {
    Sistema sistema;

    // Añadir palabras
    sistema.add("hola");
    sistema.add("mundo");
    sistema.add("HOLAa");
    sistema.add("bello");

    // Verificar si las palabras están
    cout << sistema.check("hola") << endl;      // 1 (existe)
    cout << sistema.check("HOLA") << endl;     // 1 (existe)
    cout << sistema.check("MUNDO") << endl;     // 1 (existe, mayúsculas convertidas a minúsculas)
    cout << sistema.check("mundhol") << endl;   // 0 (no existe como palabra completa)
    cout << sistema.check("llo") << endl;       // 0 (no existe)

    return 0;
}

/*
COMPLEJIDAD ESPACIAL: 
El sistema almacena n nodos, donde n es el número total de letras insertadas. 
Cada nodo tiene un vector de 26 punteros, y cada uno puede apuntar a otro nodo o ser nullptr, 
además de un booleano que indica si el nodo es el final de una palabra.
Por lo tanto, la complejidad espacial es O(n * 26), aunque puede simplificarse a O(n) 
dado que 26 es una constante.

COMPLEJIDAD TEMPORAL:
- El método add tiene una complejidad O(m), donde m es la longitud de la palabra a añadir, 
  ya que se recorre una vez cada letra de la palabra.
- El método check también tiene una complejidad O(m), ya que recorre cada letra de la palabra 
  para verificar si existe en el Trie.

*/