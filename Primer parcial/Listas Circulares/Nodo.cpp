#include "Nodo.h"

// Constructores
Nodo::Nodo() {
    this->siguiente = nullptr;
}

Nodo::Nodo(const Persona& persona, Nodo* siguiente) {
    this->persona = persona;
    this->siguiente = siguiente;
}

// Getters y Setters
Persona Nodo::getPersona() const {
    return this->persona;
}

Nodo* Nodo::getSiguiente() const {
    return this->siguiente;
}

void Nodo::setPersona(const Persona& persona) {
    this->persona = persona;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

void Nodo::insertar(Nodo*& cabeza, const string& cedula, const string& nombre, const string& apellido) {
    Persona nuevaPersona(cedula, nombre, apellido);
    Nodo* nuevo = new Nodo(nuevaPersona);

    if (cabeza == nullptr) {
        cabeza = nuevo;
        nuevo->setSiguiente(cabeza); 
        cout << "Persona insertada con exito." << endl;
        return;
    }

    Nodo* aux = cabeza;
    while (aux->getSiguiente() != cabeza) {
        aux = aux->getSiguiente();
    }

    aux->setSiguiente(nuevo);
    nuevo->setSiguiente(cabeza);
    cout << "Persona insertada con exito." << endl;
}

void Nodo::buscarPorCedula(Nodo* inicio, const string& cedulaBuscada) {
    if (inicio == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Nodo* actual = inicio;

    do {
        if (actual->getPersona().getCedula() == cedulaBuscada) {
            cout << "Cedula: " << actual->getPersona().getCedula() << endl;
            cout << "Nombre: " << actual->getPersona().getNombre() << endl;
            cout << "Apellido: " << actual->getPersona().getApellido() << endl;
            return;
        }

        actual = actual->getSiguiente();
    } while (actual != inicio);

    cout << "No se encontro esa cedula." << endl;
}

bool Nodo::eliminar(Nodo*& cabeza, const string& cedula) {
    if (cabeza == nullptr) return false;

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    if (cabeza->getPersona().getCedula() == cedula) {
        if (cabeza->getSiguiente() == cabeza) {
            delete cabeza;
            cabeza = nullptr;
            return true;
        }

        Nodo* ultimo = cabeza;
        while (ultimo->getSiguiente() != cabeza) {
            ultimo = ultimo->getSiguiente();
        }

        Nodo* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        ultimo->setSiguiente(cabeza);
        delete temp;
        return true;
    }

    anterior = cabeza;
    actual = cabeza->getSiguiente();

    while (actual != cabeza) {
        if (actual->getPersona().getCedula() == cedula) {
            anterior->setSiguiente(actual->getSiguiente());
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }

    return false; 
}

void Imprimir(Nodo* cabeza){
    if (cabeza == nullptr){
        cout << "La lista esta vacia" << endl;
        return;
    }
    Nodo* aux = cabeza;
    do{
        cout << "Cedula: " << aux->getPersona().getCedula() << endl;
        cout << "Nombre: " << aux->getPersona().getNombre() << endl;
        cout << "Apellido: " << aux->getPersona().getApellido() << endl;
        aux = aux->getSiguiente();
    } while(aux != cabeza);
}