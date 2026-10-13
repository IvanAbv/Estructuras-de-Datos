#include <iostream>
#include "sumatemplate.h" // Incluimos la cabecera de la clase

using namespace std;

int main() {
   cout << "Enteros" << endl;
    sumatemplate<int> s1(5, 10);
    
    cout << "Numero 1 inicial: " << s1.getNum1() << endl;
    cout << "Numero 2 inicial: " << s1.getNum2() << endl;
    s1.sumar();

    // Usando setters para cambiar los valores
    s1.setNum1(20);
    s1.setNum2(30);
    
    cout << "\nDespues de usar los setters:" << endl;
    cout << "Nuevo Numero 1: " << s1.getNum1() << endl;
    cout << "Nuevo Numero 2: " << s1.getNum2() << endl;
    s1.sumar();

    return 0;
}