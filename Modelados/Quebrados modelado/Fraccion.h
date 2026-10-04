/***********************************************************************
 * Module:  Fraccion.h
 * Author:  User
 * Modified: domingo, 4 de octubre de 2026 14:29:40
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__Fraccion2_Fraccion_h)
#define __Fraccion2_Fraccion_h

class Fraccion
{
public:
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