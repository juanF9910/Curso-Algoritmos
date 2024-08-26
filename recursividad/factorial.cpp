#include <iostream>
using namespace std;

long fact(int n){ //función recursiva
    if(n==0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}

int main(){
    int n = 5;
    cout << "El factorial de " << n << " es: " << fact(n) << endl;
    return 0;
} 

//la complejidad de este algoritmo es O(n) en tiempo y O(n) en espacio