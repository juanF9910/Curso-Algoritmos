/*
en este algoritmo vamos a usar el método backtracking para encontrar una solución al problema del salto del caballo
*/

#include <iostream>
#include <vector>
using namespace std;

//tamaño del tablero
#define N 8

//función para imprimir la solución
void imprimir(vector<vector<int>> &solucion){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << solucion[i][j] << " ";
        }
        cout << endl;
    }
}

//función para verificar si la posición es válida
bool es_valido(int x, int y, vector<vector<int>> &solucion){
    return (x >= 0 && x < N && y >= 0 && y < N && solucion[x][y] == -1); //-1 significa que la posición no ha sido visitada, y que la posición es válida,
    //está dentro del tablero
}

//función para resolver el problema del salto del caballo

bool resolver_salto_caballo(int x, int y, int mov, vector<vector<int>> &solucion, vector<int> &x_mov, vector<int> &y_mov){
    int k, next_x, next_y;

    if(mov == N*N){ //si hemos visitado todas las posiciones del tablero entonces hemos encontrado una solución
    //mov es una variable que guarda el número de movimientos válidos que ha hecho el caballo
        return true;
    }

    for(k = 0; k < N; k++){ //probamos cada uno de los movimientos posibles
        next_x = x + x_mov[k];
        next_y = y + y_mov[k];
        if(es_valido(next_x, next_y, solucion)){
            solucion[next_x][next_y] = mov;

            if(resolver_salto_caballo(next_x, next_y, mov + 1, solucion, x_mov, y_mov)){
                return true;
            }else{
                solucion[next_x][next_y] = -1; //si no hemos llegado a una solución ponemos un -1 para indicar que la posición no ha sido visitada
            }
        }
    }
    return false;
}

int main(){

    vector<vector<int>> solucion(N, vector<int>(N, -1)); //creamos un tablero de 8x8 con -1 en cada posición
    vector<int> x_mov = {2, 1, -1, -2, -2, -1, 1, 2}; //movimientos en x a partir de la posición actual
    vector<int> y_mov = {1, 2, 2, 1, -1, -2, -2, -1}; //movimientos en y a partir de la posición actual
    //dada una posición inicial el caballo puede moverse a 8 posiciones diferentes
    solucion[0][0] = 0;

    if(resolver_salto_caballo(0, 0, 1, solucion, x_mov, y_mov)){
        imprimir(solucion);
    }else{
        cout << "No hay solución" << endl;
    }
    return 0;
}
//la complejidad de este algoritmo es O(8^(n^2)) en tiempo y O(n^2) en espacio
