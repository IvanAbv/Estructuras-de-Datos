#if !defined(Fraccion_h)
#define Fraccion_h

class Fraccion
{
private:
   float numerador;
   float denominador;

public:
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   Fraccion();
   ~Fraccion();
   Fraccion(float newNumerador, float newDenominador);

};

#endif