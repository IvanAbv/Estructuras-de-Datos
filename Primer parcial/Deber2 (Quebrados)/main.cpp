#include "Fraccion.h"
#include <iostream>

using namespace std;

int main(){
    
    float n1,d1;
    float n2,d2;

    Fraccion fraccion1(n1,d1);
    Fraccion fraccion2(n2,d2);

    cout << "Ingrese el primer numerador";
    cin >> n1;
    cout << "Ingrese en primer denominador";
    cin >> d1;
    
    cout << "Ingrese el segundo numerador";
    cin >> n2;
    cout << "Ingrese el segundo denominador";
    cin >> d2;

    Fraccion resultadof = fraccion1.procesos(fraccion1, fraccion2);

    cout << resultadof.getNumerador()
    << "/"
    << resultadof.getDenominador(); 
    
}