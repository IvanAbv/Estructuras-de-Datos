#include "Intercambiador.h"

template <typename T>
Intercambiador<T>::Intercambiador(T dataA, T dataB) {
    datoA = dataA;
    datoB = dataB;
}

template <typename T>
void Intercambiador<T>::setDatoA(T dataA) {
    datoA = dataA;
}

template <typename T>
void Intercambiador<T>::setDatoB(T dataB) {
    datoB = dataB;
}

template <typename T>
T Intercambiador<T>::getDatoA() {
    return datoA;
}

template <typename T>
T Intercambiador<T>::getDatoB() {
    return datoB;
}

template <typename T>
void Intercambiador<T>::intercambiar() {
    T temporal = datoA;
    datoA = datoB;
    datoB = temporal;
}