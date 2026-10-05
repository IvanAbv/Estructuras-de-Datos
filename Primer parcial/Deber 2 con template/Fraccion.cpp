#include "Fraccion.h"

float Fraccion::getNumerador(void)
{
   return numerador;
}

float Fraccion::getDenominador(void)
{
   return denominador;
}

void Fraccion::setNumerador(float newNumerador)
{
   numerador = newNumerador;
}

void Fraccion::setDenominador(float newDenominador)
{
   denominador = newDenominador;
}

Fraccion::Fraccion()
{
   numerador = 0;
   denominador = 1;
}

Fraccion::~Fraccion()
{
   // Destructor
}

Fraccion::Fraccion(float newNumerador, float newDenominador)
{
   numerador = newNumerador;
   denominador = newDenominador;
}
