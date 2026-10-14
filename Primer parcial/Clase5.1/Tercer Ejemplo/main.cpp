#include <iostream>
#include "ValidarRango.h"
#include "ValidarRango.cpp"

using namespace std;

int main(){
    float valor, 
    limMin = 50.60, 
    limMax = 100;
    cout << "Ingrese el valor a comprobar" << endl;
    cin >> valor;
    ValidarRango<float> validarRango(valor, limMin, limMax);
    if(validarRango.validar(valor, limMin, limMax)){
        cout << "El valor: " << valor << " se encuentra dentro del rango" << endl;

    }else{
         cout << "El valor: " << valor << " se encuentra fuera del rango" << endl;
    }
    return 0;
}