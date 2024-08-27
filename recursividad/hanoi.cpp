/*
vamos a programar las torres de hanoi con recursividad
*/

#include <iostream>
using namespace std;

void hanoi(int n, char inicial, char central, char final){
    //los parámetros son: n es el número de discos, origen es la torre de origen, 
    //auxiliar es la torre auxiliar y destino es la torre de destino

    if(n==1){ //caso base si solo hay un disco
        cout << "Mover disco 1 de " << inicial << " a " << final << endl;
        return;
    }

    hanoi(n-1, inicial, final, central); //muevo n-1 discos desde la torre inicial a la central usando la torre final como auxiliar
    cout << "Mover disco " << n << " de " << inicial << " a " << final << endl; //muevo el disco n de la torre inicial a la final
    hanoi(n-1, central, inicial, final); //muevo n-1 discos desde la torre central a la final usando la torre inicial como auxiliar
}

int main(){
    int n = 3; //n es el número de discos
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

/*
la complejidad de este algoritmo es O(2^n) en tiempo y O(n) en espacio
en el tiempo es esa porque en cada llamada recursiva se hacen dos llamadas recursivas y en el espacio es O(n) porque en cada llamada recursiva se guarda el estado de la función
*/
