#include "Comparador.h"

template <typename T>
Comparador<T>::Comparador(T v1, T v2) {
    valor1 = v1;
    valor2 = v2;
}

template <typename T>
Comparador<T>::~Comparador() {
};

template <typename T>
T Comparador<T>::obtenerMayor(T v1, T v2){
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

template <typename T>
void Comparador<T>::setValor1(T v1) {
    valor1 = v1;
}

template <typename T>
void Comparador<T>::setValor2(T v2) {
    valor2 = v2;
}

template <typename T>
T Comparador<T>::getValor1() {
    return valor1;
}

template <typename T>
T Comparador<T>::getValor2(){
    return valor2;
}
