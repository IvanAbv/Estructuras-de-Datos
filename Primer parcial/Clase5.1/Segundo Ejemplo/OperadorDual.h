#pragma once

template <typename T>
class OperadorDual{
    private:
    T operador1, operador2;

    public:
    OperadorDual(T op1,T op2);
    ~OperadorDual(){};

    void setT1(T op1);
    void setT2(T op2);

    T getT1();
    T getT2();

    T calcularMultiplicacion(T op1, T op2);
    T calcularResta(T op1, T op2);

};