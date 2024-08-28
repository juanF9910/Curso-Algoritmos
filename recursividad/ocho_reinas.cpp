/*
vamos a programar el problema de las ocho reinas con recursividad, 
consiste en poner 8 reinas en un tablero de ajedrez de 8x8 de tal forma que ninguna reina se ataque
*/
#include <iostream>
#include <vector>

using namespace std;

#define N 8 //8 cuadros en el tablero de ajedrez
//ubicamos una reina por columna y determinamos en qué fila se va a ubicar

//función para imprimir la solución
void imprimir(vector<vector<int>> &solucion){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << solucion[i][j] << " ";
        }
        cout << endl;
    }
}

//función para verificar si la posición es válida, esta es la TAREA BÁSICA
bool es_valido(int x, int y, vector<vector<int>> &solucion){ //x es la fila y es la columna (reinas colocadas hasta el momento)

    for(int i = 0; i < y; i++){ //verificamos si hay una reina en la misma fila
        if(solucion[x][i]){ //si solucion[x][i] es 1 entonces hay una reina en la misma fila y no es válida la posición
            return false;
        }
    } 

    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--){ //verificamos si hay una reina en la misma diagonal de arriba a la izquierda
        if(solucion[i][j]){
            return false;
        }
    }

    for(int i = x, j = y; i < N && j >= 0; i++, j--){ //verificamos si hay una reina en la misma diagonal de abajo a la izquierda
        if(solucion[i][j]){
            return false;
        }
    }

    return true;
}

//función para resolver el problema de las ocho reinas
bool resolver_ocho_reinas(vector<vector<int>> &solucion, int y){ //y es el número de reinas colocadas en el tablero
    if(y == N){ //si hemos colocado las 8 reinas entonces hemos encontrado una solución
        return true; //condición de parada
    }
    for(int i = 0; i < N; i++){ //probamos cada una de las posiciones de las filas

        if(es_valido(i, y, solucion)){ //si la posición es válida
            solucion[i][y] = 1; //colocamos la reina
            //tarea básica 
            if(resolver_ocho_reinas(solucion, y + 1)){ //evaluamos si a partir de la posición actual podemos encontrar una solución
                return true;
            }else //si no hemos encontrado una solución a partir de la posición actual ponemos un 0 y probamos con la siguiente posición
                solucion[i][y] = 0; 
            }
    
    }
    return false;
}

    


int main(){
    vector<vector<int>> solucion(N, vector<int>(N, 0)); //creamos un tablero de 8x8 con 0 en cada posición
    if(resolver_ocho_reinas(solucion, 0)){
        imprimir(solucion);
    }else{
        cout << "No hay solución" << endl;
    }
    return 0;
}

//la complejidad de este algoritmo es O(n!) en tiempo y O(n^2) en espacio
//resolver_ocho_reinas es un problema de decisión, es decir, nos interesa saber si hay una solución o no, no nos interesa saber cuál es la solución