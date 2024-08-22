/*
vamos a programar las torres de hanoi con recursividad
*/

#include <iostream>
using namespace std;

void hanoi(int n, char origen, char auxiliar, char destino){
    if(n==1){
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }
    hanoi(n-1, origen, destino, auxiliar);
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
    hanoi(n-1, auxiliar, origen, destino);
}

int main(){
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
