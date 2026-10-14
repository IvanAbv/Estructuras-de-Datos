#include <iostream>
#include <stdlib.h>
#include "OperadorDual.h"
#include "OperadorDual.cpp"
using namespace std;

int main(){ 
    float op1, op2, resM, resR;
    cout << "Escriba el primer numero" << endl;
    cin >> op1;
    cout << "Escriba el segundo numero" << endl;
    cin >> op2;

    OperadorDual<float> operadorDual(op1, op2);
    resM = operadorDual.calcularMultiplicacion(op1,op2);
    cout << "Resultado de la multiplicacion: " << resM << endl;
    resR = operadorDual.calcularResta(op1, op2);
    cout << "Resultado de la resta: " << resR << endl; 
    return 0;
}
