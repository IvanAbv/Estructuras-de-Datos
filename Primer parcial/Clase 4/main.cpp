#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int ingresar();
int ingresar() {
    int i= 0;
    char c;
    char datos[10];

    printf("%s", "Ingrese un numero: ");
    while((c=getch()) != 13) {
        if(c >= '0' && c <= '9') {
          printf("%c",c);
          datos[i++]=c;
        }
    }
    datos[i]='\0';
    return atoi(datos);

}


int main(void) {

    int numero;
    numero = ingresar();
    printf("\nEl numero ingresado es: %d", numero);

    return 0;
}
//debugger
//Crear una sola funcion para que ingrese cualquier tipo de dato
//retorno el char y luego lo transformo vía casting
