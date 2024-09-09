#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
        int** adjMatrix;  // Un puntero doble para la matriz dinámica
        int size;

        // Método recursivo auxiliar para DFS, DFS significa Depth First Search o Búsqueda en Profundidad
        void DFSUtil(int v, vector<bool>& visited) const {
            // Marcar el nodo como visitado e imprimirlo
            visited[v] = true;
            cout << v << " ";

            // Recorrer los vértices adyacentes no visitados
            for (int i = 0; i < size; ++i) {
                if (adjMatrix[v][i] == 1 && !visited[i]) {
                    DFSUtil(i, visited);
                }
            }
        }

    public:
        // Constructor para inicializar la matriz y el número de vértices
        Graph(int n) : size(n) {
            adjMatrix = new int*[size];  
            for (int i = 0; i < size; ++i) {
                adjMatrix[i] = new int[size];  
                for (int j = 0; j < size; ++j) {
                    adjMatrix[i][j] = 0;  // Inicializar la matriz con ceros
                }
            }
        }

        // Método para añadir una arista
        void addEdge(int u, int v) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;  // Grafo no dirigido
        }

        // DFS desde un vértice dado
        void DFS(int start) const {
            vector<bool> visited(size, false);  // Inicializar todos los nodos como no visitados
            DFSUtil(start, visited);  // Llamada a la función auxiliar para DFS
            cout << endl;
        }

        // Método para imprimir la matriz
        void printGraph() const {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        // Destructor para liberar memoria
        ~Graph() {
            for (int i = 0; i < size; ++i) {
                delete[] adjMatrix[i];  // Liberar cada fila
            }
            delete[] adjMatrix;  // Liberar el array de punteros
        }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Matriz de adyacencia:" << endl;
    g.printGraph();

    cout << "DFS desde el nodo 0:" << endl;
    g.DFS(0);  // Realizar DFS comenzando desde el nodo 0

    return 0;
}