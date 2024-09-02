#include <iostream>
using namespace std;

class Graph {
    
    public:

        Graph(int n) { // Constructor
            size = n;
            adjMatrix = new int*[n]; //puntero a un arreglo de punteros
            // Crear una matriz de adyacencia de tamaño n x n
            for (int i = 0; i < n; i++) {
                adjMatrix[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    adjMatrix[i][j] = 0;
                }
            }
        }

        // Método para agregar una arista (u, v) al grafo
        void addEdge(int u, int v) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;  // Si el grafo es no dirigido
        }

        // Método para imprimir la matriz de adyacencia
        void printGraph() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        ~Graph() {
            for (int i = 0; i < size; i++) {
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
        }

private:
    int** adjMatrix;
    int size;
};

int main() {
    int numNodes = 5;

    // Crear un grafo con 5 nodos
    Graph g(numNodes);

    // Agregar aristas
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Imprimir el grafo
    g.printGraph();

    return 0;
}