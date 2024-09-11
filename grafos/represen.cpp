#include <iostream>
using namespace std;

class Graph {
    private:
        int** adjMatrix;  // un puntero doble se interpreta como una matriz dinámica porque el primer puntero apunta a un array de punteros
        int size;

    public:
        // Constructor para inicializar la matriz y el n
        Graph(int n) : size(n) {
            adjMatrix = new int* [size];  // Creamos un puntero de tipo entero que apunta a un array de size punteros
            for (int i = 0; i < size; ++i) {
                adjMatrix[i] = new int[size];  // creamos un puntero que apunta a un array de size enteros, las filas. 
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

    g.printGraph();

    return 0;
}