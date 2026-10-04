#if !defined(_IProcesos_h)
#define _IProcesos_h

class Fraccion;

class IProcesos
{
    public:
    virtual Fraccion procesos(Fraccion f1, Fraccion f2) = 0;
};

#endif