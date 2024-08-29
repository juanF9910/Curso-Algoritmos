#include <iostream>

using namespace std;

double circunferencia(double radio){
    return 2 * PI * radio;
}

double area(double radio){
    return PI * radio * radio;
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <radio>" << endl;
        return 1;
    }

    double radio = atof(argv[1]);

    cout << "La circunferencia es: " << circunferencia(radio) << endl;
    cout << "El área es: " << area(radio) << endl;

    return 0;
}