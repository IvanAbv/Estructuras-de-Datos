#include <iostream>
#include <stdlib.h>
#include <string.h>

template <typename T>
T ingresar() {
    T value;
    char c;
    printf("%s", "Ingrese: ");
    std::cin >> value;
    c = static_cast<char>(value);
    return c;
}


int main(void){
    char probando;
    probando = ingresar<char>();

    printf("\nImprimiendo lo ingresado: %c", probando);
    return 0; 
};