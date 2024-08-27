/*
vamos a programar una función recursiva que calcule la suma de los primeros n números naturales
*/

#include <iostream>
using namespace std;

int suma(int n){
    if(n==0){ //componente base o condución de salida
        return 0;
    }else{
        return n + suma(n-1); //componente recursiva
    }
}

int main(){
    int n = 5;
    cout << "La suma de los primeros " << n << " números naturales es: " << suma(n) << endl;
    return 0;
}