/* Primer Ejemplo */
#include <iostream>
#include "Comparador.h"
#include "Comparador.cpp"

using namespace std;

int main(){
    float n1,n2,res;
    cout << "Escribe el primer numero" << endl;
    cin >> n1;
    cout << "Escriba el segundo numero: " << endl;
    cin >> n2;
    Comparador<float> comparador(n1,n2);
    res = comparador.obtenerMayor(n1,n2);

    cout << "El mayor numero es: " << res << endl;

    return 0;
};