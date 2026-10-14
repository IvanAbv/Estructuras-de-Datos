#pragma once

template <typename T>

class Comparador {

    private:
    T valor1, valor2;

    public:
    // Constructor
    Comparador(T v1, T v2);
    //Destructor
    ~Comparador();
    //Metodo
    T obtenerMayor(T v1, T v2);
    //Setters
    void setValor1(T v1);
    void setValor2(T v2);
    //Getters
    T getValor1();
    T getValor2();

};