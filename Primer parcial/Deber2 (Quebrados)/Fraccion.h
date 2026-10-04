#if !defined(_Fraccion_h)
#define _Fraccion_h

#include "IProcesos.h"

class Fraccion : public IProcesos
{
    private:
    float  numerador,
    denominador;

    public:
    void setNumerador (float newNumerador);
    void setDenominador (float newDenominador);
    float getNumerador (void);
    float getDenominador (void);
    Fraccion(); 
    ~Fraccion();
    Fraccion (float num, float den); 

    Fraccion procesos(Fraccion f1, Fraccion f2) override;
};

#endif