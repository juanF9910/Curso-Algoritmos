#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase que representa un nodo en el Trie
class Node {
    public:
        vector<Node*> children; //vamos a definir un vector de punteros a otros nodos del mismo tipo
        bool isEndOfWord; // Marca si el nodo es el final de una palabra
        Node(): isEndOfWord(false), children(26, nullptr) {} //children tiene 26 elementos(punteros), cada uno inicializado en nullptr
};


// Clase que representa el Trie completo
class Trie {

    private:

        Node* root; //puntero que apunta a la letra inicial de la palabra

        int charToIndex(char c) {
            return c - 'a'; //esta operación entrega un número entre 0 y 25, que es el índice de la letra del abecedario.
        }

    public:

        Trie() {
            root = new Node(); //constructor, inicializamos el puntero root con un nuevo nodo
        }

        // Método para añadir una palabra al Trie
        void add(const string& str) {
            Node* node = root; //un nodo hace referencia a una listra
            for (char c : str) {
                int index = charToIndex(c);  // Convertimos la letra a índice del 0 al 25
                if (node->children[index] == nullptr) { // Si el puntero en la posición index es nullptr
                    node->children[index] = new Node();  // Creamos un nuevo nodo si no existe
                }
                node = node->children[index];  // Movemos el puntero al siguiente nodo
            }
            node->isEndOfWord = true;  // Marcamos el último nodo como final de palabra
        }

        // Método para verificar si una cadena ya ha sido añadida
        bool check(const string& str) {
            Node* node = root;  // Comenzamos desde la raíz
            for (char c : str) {
                int index = charToIndex(c);  // Convertimos la letra a índice
                if (node->children[index] == nullptr) {
                    return false;  // Si no existe el siguiente nodo, asociado al indice de la letra correspondiente de str 
                }

                node = node->children[index];  // Avanzamos al siguiente nodo
            }
            return node->isEndOfWord;  // Verificamos si es el final de una palabra válida
        }
};

int main() {
    Trie trie;

    // Añadir palabras al Trie
    trie.add("hola");
    trie.add("mundo");
    trie.add("bello");

    // Verificar si las palabras existen en el Trie
    cout << trie.check("hola") << endl;     // 1 (existe)
    cout << trie.check("mundo") << endl;    // 1 (existe)
    cout << trie.check("holistico") << endl; // 0 (no existe)
    cout << trie.check("mundhol") << endl;      // 0 (no existe como palabra completa)
    cout << trie.check("llo") << endl;    // 0 (no existe)

    return 0;
}

/*
COMPLEJIDAD ESPACIAL: el Trie guarda n nodos, cada uno con 26 punteros a otros nodos, por lo que la complejidad espacial es O(n*26*L) 
donde L es el tamaño promedio de las palabras

COMPLEJIDAD TEMPORAL: el método add tiene una complejidad temporal de O(m) ya que recorre la palabra de tamaño m, el método check 
también tiene una complejidad temporal de O(m) ya que recorre la palabra de tamaño m


*/