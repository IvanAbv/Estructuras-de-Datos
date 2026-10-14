#include "OperadorDual.h"

template <typename T>
OperadorDual<T>::OperadorDual(T op1, T op2){
    operador1 = op1;
    operador2 = op2;
}

template <typename T>
void OperadorDual<T>::setT1(T op1){
    operador1 = op1;
}

template <typename T>
void OperadorDual<T>::setT2(T op2){
    operador2 = op2;
}

template <typename T>
T OperadorDual<T>::getT1(){
    return operador1;
}

template <typename T>
T OperadorDual<T>::getT2(){
    return operador2;
}

template <typename T>
T OperadorDual<T>::calcularMultiplicacion(T op1, T op2){
    return op1 * op2;
}

template <typename T>
T OperadorDual<T>::calcularResta(T op1, T op2){
    return op1 - op2;
}