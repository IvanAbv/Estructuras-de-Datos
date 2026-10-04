/***********************************************************************
 * Module:  IProcesos.h
 * Author:  User
 * Modified: sábado, 3 de octubre de 2026 14:40:46
 * Purpose: Declaration of the class IProcesos
 ***********************************************************************/

#if !defined(__Fraccion2_IProcesos_h)
#define __Fraccion2_IProcesos_h

#include <Fraccion.h>

class IProcesos
{
public:
   virtual Fraccion proceso(Fraccion f1, Fraccion f2)=0;

protected:
private:

};

#endif