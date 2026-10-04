#include "Fraccion.h"
#include <cmath>

void Fraccion::setNumerador (float newNumerador){

    numerador = newNumerador;
}

void Fraccion::setDenominador (float newDenominador){

    if(newDenominador != 0){
        denominador = newDenominador;
    } else {
        denominador = 1.0f;
    }
}

float Fraccion::getNumerador (void){
    
    return numerador;
}

float Fraccion::getDenominador (void){

    return denominador;
}

Fraccion::Fraccion(){

    numerador = 0.0f;
    denominador = 1.0f;
}

Fraccion::~Fraccion(){

}

Fraccion::Fraccion(float num, float den){

    numerador = num;
    denominador= den;
}

Fraccion procesos(Fraccion f1, Fraccion f2){
    
    float resN;
    float resD;

    resD = f1.getDenominador() * f2.getDenominador();
    
    resN = (f1.getNumerador() * f2.getDenominador() + (f2.getNumerador() * f1.getNumerador()));

    Fraccion resultado(resN,resD);

    return resultado;
}