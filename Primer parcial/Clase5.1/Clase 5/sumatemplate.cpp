#include "sumatemplate.h"
#include <iostream>
using namespace std;

template <typename T>
    sumatemplate<T>::sumatemplate(T n1, T n2){
        num1 = n1;
        num2 = n2;
    };

//Setters
template <typename T>
void sumatemplate<T>::setNum1(T n1) {
    num1 = n1;
}

template <typename T>
void sumatemplate<T>::setNum2(T n2) {
    num2 = n2;
}

// Getters
template <typename T>
T sumatemplate<T>::getNum1() {
    return num1;
}

template <typename T>
T sumatemplate<T>::getNum2() {
    return num2;
}

template <typename T>
    void sumatemplate<T>::sumar(T n1, T n2){
        cout << "Suma: " << n1 + n2 << endl; 
    }

    
template <typename T>
sumatemplate<T>::~sumatemplate() {
}