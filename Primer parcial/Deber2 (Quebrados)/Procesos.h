#if !defined(Procesos_h)
#define Procesos_h

#include "Fraccion.h"
#include "IProcesos.h"

class Procesos : public IProcesos
{
public:
   Fraccion proceso(Fraccion f1, Fraccion f2);

};

#endif