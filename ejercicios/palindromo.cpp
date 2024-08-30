/*
vamos a crear un algoritmo de decisión que va a determinar si una palabra es palíndroma o no
*/

#include <iostream>
#include <string>

using namespace std;

bool palindromo(string palabra){
    int inicio = 0;
    int fin = palabra.length() - 1;
    while(inicio < fin){
        if(palabra[inicio] != palabra[fin]){
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}

int main(){
    string palabra;
    cout<<"Ingrese una palabra: ";
    cin>>palabra;
    if(palindromo(palabra)){
        cout<<"La palabra es palíndroma"<<endl;
    }else{
        cout<<"La palabra no es palíndroma"<<endl;
    }
    return 0;
}
