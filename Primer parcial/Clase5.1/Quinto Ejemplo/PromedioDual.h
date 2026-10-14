#pragma once

template <typename T>
class PromedioDual {
private:
    T calificacion1;
    T calificacion2;

public:
    PromedioDual(T c1, T c2);
    ~PromedioDual() {}

    void setCalificacion1(T c1);
    void setCalificacion2(T c2);

    T getCalificacion1();
    T getCalificacion2();

    double calcularPromedioPonderado();
};