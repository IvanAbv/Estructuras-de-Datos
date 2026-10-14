#pragma once

template <typename T>
class ValidarRango{
    
    private:
    T valorActual, limiteMinimo, limiteMaximo;

    public:

    ValidarRango(T valA, T limMin, T limMax);
    ~ValidarRango(){}

    void setValA(T valA);
    void setLimMin(T limMin);
    void setLimMax(T limMax);

    T getValA();
    T getLimMin();
    T getLimMax();

    bool validar(T valA, T limMin, T limMax);

};