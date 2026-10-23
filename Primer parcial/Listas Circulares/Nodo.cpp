#include "Nodo.h"


Nodo::Nodo() {
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Nodo::Nodo(const Persona& persona, Nodo* siguiente, Nodo* anterior) {
    this->persona = persona;
    this->siguiente = siguiente;
    this->anterior = anterior;
}


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
        cabeza->setSiguiente(cabeza);
        cabeza->setAnterior(cabeza);
        cout << "Persona insertada con exito." << endl;
        return;
    }

    Nodo* ultimo = cabeza->getAnterior();

    ultimo->setSiguiente(nuevo);
    nuevo->setAnterior(ultimo);
    
    nuevo->setSiguiente(cabeza);
    cabeza->setAnterior(nuevo);

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

void Nodo::eliminar(Nodo*& cabeza, Nodo*& cola, const string& cedula) {

    if (cabeza == nullptr) {
        cout << "La lista esta vacia. No hay elementos para eliminar." << endl; 
        return;
    }
    
    Nodo* actual = cabeza;    
    bool encontrado = false;
    bool continuar = true;    
    
    while (continuar && !encontrado) {
        if (actual->getPersona().getCedula() == cedula) {
            encontrado = true;
        } else {
            actual = actual->getSiguiente();
            if (actual == cabeza) {
                continuar = false;
            }
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro ningun registro con la cedula: " << cedula << endl;
        return;
    }
    
    if (cabeza == cola && cabeza == actual) { 
        delete cabeza;                        
        cabeza = nullptr;
        cola = nullptr;
    }

    else if (actual == cabeza) {
        cabeza = cabeza->getSiguiente();           
        cola->setSiguiente(cabeza);                
        cabeza->setAnterior(cola);                 
        delete actual;                             
    }
    
    else if (actual == cola) {
        cola = cola->getAnterior();                
        cola->setSiguiente(cabeza);               
        cabeza->setAnterior(cola);                 
        delete actual;                             
    }
    
    else {
        actual->getAnterior()->setSiguiente(actual->getSiguiente()); 
        actual->getSiguiente()->setAnterior(actual->getAnterior());  
        delete actual;                                               
    }
    
    cout << "Registro con cedula " << cedula << " eliminado exitosamente." << endl;
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