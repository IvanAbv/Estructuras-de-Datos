#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

float ingresar();
float ingresar() {
    int i= 0;
    char c;
    char datos[10];
    bool puntoIngresado = false;

    printf("%s", "Ingrese un numero: ");
    while((c=getch()) != 13) {
        if(c >= '0' && c <= '9') {
          printf("%c",c);
          datos[i++]=c;
        }
        if(c == '.' && i > 0 && datos[i-1] != '.' && !puntoIngresado) {
          printf("%c",c);
          datos[i++]=c;
          puntoIngresado = true;
        }
        if(c == 127 || c == 8 && i > 0) {
          printf("\b \b");
          i--;
          if(datos[i] == '.') {
              puntoIngresado = false;
          }
        }
    }
    datos[i]='\0';
    return atof(datos);

}


int main(void){

    float numero;
    numero = ingresar();
    printf("\nEl numero ingresado es: %f", numero);

    return 0;
}