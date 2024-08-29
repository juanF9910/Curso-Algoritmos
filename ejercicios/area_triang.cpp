/*
definamos una funci´on para calcular el ´area de un tri´angulo tomando su base y altura como par´ametros
*/

#include <iostream>
#include <cstdlib> // Para usar atof()

using namespace std;

float area_triangulo(float base, float altura){
    return (base * altura) / 2;
}

int main(int argc, char* argv[]) { //argc es el número de argumentos y argv es un arreglo de punteros a los argumentos
    if (argc != 3) { //el nombre del ejecutable cuenta como argumento
    //argv guarda los argumentos como cadenas de caractere!!! por eso hay que convertirlas al tipo de dato que necesitamos
        cout << "Uso: " << argv[0] << " <base> <altura>" << endl;
        return 1;
    }

    // Convertir argumentos de la línea de comandos a float
    float base = atof(argv[1]); //convertimos de char a float
    float altura = atof(argv[2]); //convertimos de char a float

    cout << "El área del triángulo es: " << area_triangulo(base, altura) << endl;

    return 0;
}