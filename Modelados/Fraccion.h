/***********************************************************************
 * Module:  Fraccion.h
 * Author:  User
 * Modified: sábado, 3 de octubre de 2026 14:42:32
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__Fraccion2_Fraccion_h)
#define __Fraccion2_Fraccion_h

class Fraccion
{
public:
   bool comprobarNumerador(void);
   bool comprobarDenominador(void);
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   Fraccion();
   ~Fraccion();
   Fraccion(float newNumerador, float newDenominador);

protected:
private:
   float numerador;
   float denominador;


};

#endif