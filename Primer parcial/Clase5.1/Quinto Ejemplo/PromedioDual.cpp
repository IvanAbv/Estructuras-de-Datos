#include "PromedioDual.h"

template <typename T>
PromedioDual<T>::PromedioDual(T c1, T c2) {
    calificacion1 = c1;
    calificacion2 = c2;
}

template <typename T>
void PromedioDual<T>::setCalificacion1(T c1) {
    calificacion1 = c1;
}

template <typename T>
void PromedioDual<T>::setCalificacion2(T c2) {
    calificacion2 = c2;
}

template <typename T>
T PromedioDual<T>::getCalificacion1() {
    return calificacion1;
}

template <typename T>
T PromedioDual<T>::getCalificacion2() {
    return calificacion2;
}

template <typename T>
double PromedioDual<T>::calcularPromedioPonderado() {
    return (calificacion1 * 0.40) + (calificacion2 * 0.60);
}

template class PromedioDual<int>;
template class PromedioDual<double>;