//Intercambiar numerador y denominador

#include <iostream>
using namespace std;

template <typename T>
class Fraccion{
    private:
    T numerador;
    T denominador;

    public:

    Fraccion(){
        numerador = 0;
        denominador = 1;
    }

    Fraccion (T num, T den){
        numerador = num;
        denominador = den;
    }
    ~Fraccion(){}

    void setNum(T num){
        numerador = num;
    }
    void setDen(T den){
        denominador = den;
    }

    T getNum() const {
        return numerador;
    }
    T getDen() const {
        return denominador;
    }

    void intercambiar(){
       T temp = numerador;
        numerador = denominador;
        denominador = temp;
    }

    Fraccion sumar(const Fraccion& F1, const Fraccion& F2){
        T num, den;
        num = (F1.getNum() * F2.getDen()) + (F1.getDen() * F2.getNum());
        den = F1.getDen() * F2.getDen();
        return Fraccion(num,den);
    } 

    void imprimir(){
        cout << "La Fraccion normal es: " << numerador << "/" << denominador << endl;

        intercambiar();

        cout << "La Fraccion dada vuelta es: " << numerador << "/" << denominador << endl;
    }
};


int main(){

Fraccion<float> fraccion(4.0f, 7.0f);
    Fraccion<float> fraccion2(3.0f, 5.0f);
    
    // 3. Declaración correcta del objeto resultado (sin paréntesis)
    Fraccion<float> resultado; 
    
    // Guardamos el retorno de la suma
    Fraccion<float> suma = resultado.sumar(fraccion, fraccion2);

    cout << "--- Resultado de la suma ---" << endl;
    suma.imprimir();

    cout << "\n--- Fraccion original ---" << endl;
    fraccion.imprimir();

    return 0;
}