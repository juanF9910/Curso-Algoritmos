#include <iostream>

using namespace std; 

bool primo( int n){

    if(n<=1){
        return false;
    }
    for(int i=2; i*i<n; i++){ //desde i=2 hasta i tal que i<sqrt(n)
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Ingrese un número: ";
    cin>>n;
    if(primo(n)){
        cout<<"El número es primo"<<endl;
    }else{
        cout<<"El número no es primo"<<endl;
    }
    return 0;
}