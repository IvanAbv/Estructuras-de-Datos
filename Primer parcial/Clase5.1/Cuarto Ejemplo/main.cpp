#include <iostream>
#include "Intercambiador.h"

using namespace std;

int main() {
    Intercambiador<int> obj(10, 20);

    cout << "Antes: A = " << obj.getDatoA() << ", B = " << obj.getDatoB() << endl;

    obj.intercambiar();

    cout << "Despues: A = " << obj.getDatoA() << ", B = " << obj.getDatoB() << endl;

    return 0;
}