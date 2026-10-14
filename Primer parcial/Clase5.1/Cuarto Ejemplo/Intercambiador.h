#pragma once

template <typename T>
class Intercambiador {
private:
    T datoA;
    T datoB;

public:
    Intercambiador(T dataA, T dataB);
    ~Intercambiador() {}

    void setDatoA(T dataA);
    void setDatoB(T dataB);

    T getDatoA();
    T getDatoB();

    void intercambiar();
};