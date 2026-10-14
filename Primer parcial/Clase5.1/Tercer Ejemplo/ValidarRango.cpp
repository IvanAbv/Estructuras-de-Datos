#include "ValidarRango.h"

template <typename T>
ValidarRango<T>::ValidarRango(T valA, T limMin, T limMax){
    valorActual = valA;
    limiteMinimo = limMin;
    limiteMaximo = limMax;
}

template <typename T>
void ValidarRango<T>::setValA(T valA){
    valorActual = valA;
}

template <typename T>
void ValidarRango<T>::setLimMin(T limMin){
    limiteMinimo = limMin;
}

template <typename T>
void ValidarRango<T>::setLimMax(T limMax){
    limiteMaximo = limMax;
}

template <typename T>
T ValidarRango<T>::getValA(){
    return valorActual;
}

template <typename T>
T ValidarRango<T>::getLimMin(){
    return limiteMinimo;
}

template <typename T>
T ValidarRango<T>::getLimMax(){
    return limiteMaximo;
}

template <typename T>
bool ValidarRango<T>::validar(T valA, T limMin, T limMax){
    if(valA > limMin && valA < limMax){
        return true;
    }else{
        return false;
    }
    
}