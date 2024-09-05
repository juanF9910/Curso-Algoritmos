#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SimpleList {

    private:
        vector<string> seenStrings; //vector de cadenas en donde se van a almacenar las cadenas que ya se han visto

        bool secuencial(const string& str); //método de búsqueda secuencial o lineal
        
    public:

        SimpleList(); // Constructor

        void add(const string& str);  // pasamos un string por referencia para añadir

        bool check(const string& str); //cerificamos si la cadena ya se encuentra en el vector o no
};

SimpleList::SimpleList() {
    seenStrings = vector<string>(); //inicializamos el vector de cadenas
}

bool SimpleList::secuencial(const string& str) { //método de búsqueda secuencial o lineal

    for (const auto& s : seenStrings) {
        if (s == str) {
            return true;
        }
    }
    return false;
}

void SimpleList::add(const string& str) {  //agregamos una cadena al vector en la posición final
    seenStrings.push_back(str);
}

bool SimpleList::check(const string& str) {  //verificamos si la cadena ya se encuentra en el vector con búsqueda secuencial o lineal
    return secuencial(str);
}

int main() {
    SimpleList sl;

    sl.add("hola");
    sl.add("mundo");
    sl.add("hola");

    cout << sl.check("hola") << endl;  // 1
    cout << sl.check("mundo") << endl; // 1
    cout << sl.check("adios") << endl; // 0

    return 0;
}

/*
COMPLEJIDAD ESPACIAL: el vector seenstrings guarda n cadenas de tamaño promedio m, por lo que la complejidad espacial es O(n*m)

COMPLEJIDAD TEMPORAL: el método add tiene una complejidad temporal de O(1) ya que se añade al final del vector, por otro lado, 
el método check tiene una complejidad temporal de O(n) ya que recorre el vector de cadenas para verificar si la cadena ya se encuentra en el vector

*/