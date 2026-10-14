#include <iostream>
#include "PromedioDual.h"

using namespace std;

int main() {
    PromedioDual<double> alumno(85.5, 92.0);

    cout << "Calificacion 1: " << alumno.getCalificacion1() << endl;
    cout << "Calificacion 2: " << alumno.getCalificacion2() << endl;
    cout << "Promedio Ponderado: " << alumno.calcularPromedioPonderado() << endl;

    return 0;
}