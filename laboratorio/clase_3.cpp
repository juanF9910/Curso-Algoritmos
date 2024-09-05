#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase que representa un nodo en el Trie
class Node {

    public:
        Node();//children tiene 26 elementos(punteros), cada uno inicializado en nullptr
        vector<Node*> children; //vamos a definir un vector de punteros a otros nodos del mismo tipo
        bool isEndOfWord; // Marca si el nodo es el final de una palabra
};

Node::Node(){
    isEndOfWord = false;
    children = vector<Node*>(26, nullptr);
}

// Clase que representa el Trie completo
class Trie {

    private:
        Node* root;

        // Convertir una letra en un índice (asumiendo solo letras minúsculas)
        int charToIndex(char c) {
            return c - 'a'; //entrega números del 0 al 25
        }

    public:
        Trie() {
            root = new Node();
        }

        // Método para añadir una cadena al Trie
        void add(const string& str) {
            Node* node = root;  // Comenzamos desde la raíz
            for (char c : str) {
                int index = charToIndex(c);  // Convertimos la letra a índice del 0 al 25
                if (node->children[index] == nullptr) {
                    node->children[index] = new Node();  // Creamos un nuevo nodo si no existe
                }
                node = node->children[index];  // Avanzamos al siguiente nodo
            }
            node->isEndOfWord = true;  // Marcamos el final de la palabra
        }

        // Método para verificar si una cadena ya ha sido añadida
        bool check(const string& str) {
            Node* node = root;  // Comenzamos desde la raíz
            for (char c : str) {
                int index = charToIndex(c);  // Convertimos la letra a índice
                if (node->children[index] == nullptr) {
                    return false;  // Si no existe el siguiente nodo, la palabra no está en el Trie
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
    trie.add("holistico");

    // Verificar si las palabras existen en el Trie
    cout << trie.check("hola") << endl;     // 1 (existe)
    cout << trie.check("mundo") << endl;    // 1 (existe)
    cout << trie.check("holistico") << endl; // 1 (existe)
    cout << trie.check("hol") << endl;      // 0 (no existe como palabra completa)
    cout << trie.check("adios") << endl;    // 0 (no existe)

    return 0;
}