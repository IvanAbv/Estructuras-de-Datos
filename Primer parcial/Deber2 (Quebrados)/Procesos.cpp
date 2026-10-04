#include "Procesos.h"

Fraccion Procesos::proceso(Fraccion f1, Fraccion f2)
{
    float numerador = f1.getNumerador() * f2.getDenominador() + f2.getNumerador() * f1.getDenominador();
    float denominador = f1.getDenominador() * f2.getDenominador();
    Fraccion resultado(numerador, denominador);
    return resultado;
}