#include <iostream>
#include <stdlib.h>
#include <string.h>

template <typename T>
char ingresar() {
    T value;
    char c[10];
    printf("%s", "Ingrese: ");
    std::cin >> value;
    c[10] = static_cast<char>(value);
    return c[10];
}


int main(void){
    char probando[10];
    probando[0] = ingresar<char>();

    printf("\nImprimiendo lo ingresado: %c", probando[0]);
    return 0; 
};