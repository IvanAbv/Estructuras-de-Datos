
#include "Fraccion.h"
#include "Procesos.h"

#include <iostream>
using namespace std;

int main()
{
    float numerador1,numerador2,denominador1,denominador2;
    cout << "Ingrese el numerador de la primera fraccion: ";
    cin >> numerador1;
    cout << "Ingrese el denominador de la primera fraccion: ";
    cin >> denominador1;
    cout << "Ingrese el numerador de la segunda fraccion: ";
    cin >> numerador2;
    cout << "Ingrese el denominador de la segunda fraccion: ";
    cin >> denominador2;

    Fraccion f1(numerador1, denominador1);
    Fraccion f2(numerador2, denominador2);

    Fraccion resultado;
    Procesos procesos; 

    resultado = procesos.proceso(f1, f2);

    cout << "El resultado de la suma es: " << resultado.getNumerador() << "/" << resultado.getDenominador() << endl;
    return 0;
}