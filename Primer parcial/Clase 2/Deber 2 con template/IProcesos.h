#if !defined(IProcesos_h)
#define IProcesos_h

#include "Fraccion.h"

class IProcesos
{
public:
   virtual Fraccion proceso(Fraccion f1, Fraccion f2)=0;
   
};

#endif