#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string cedula;
    string nombre;
    string apellido;
    
    Persona(string ced, string nom, string ap) {
        cedula = ced;
        nombre = nom;
        apellido = ap;
    }
};

class Nodo {
public:
    Persona persona;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(Persona p) : persona(p), siguiente(nullptr), anterior(nullptr) {}

    // 1. MÉTODO INSERTAR
    static void insertar(Nodo*& cabeza, string cedula, string nombre, string apellido) {
        Persona nuevaPersona(cedula, nombre, apellido);
        Nodo* nuevo = new Nodo(nuevaPersona);

        if (cabeza == nullptr) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
            return;
        }

        Nodo* ultimo = cabeza->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }

    // 2. MÉTODO BUSCAR
    static void buscar(Nodo* cabeza, string cedulaBuscada) {
        if (cabeza == nullptr) {
            cout << "Lista vacia.\n";
            return;
        }

        Nodo* actual = cabeza;
        do {
            if (actual->persona.cedula == cedulaBuscada) {
                cout << "Encontrado: " << actual->persona.nombre << "\n";
                return;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);

        cout << "No encontrado.\n";
    }

    // 3. MÉTODO IMPRIMIR
    static void imprimir(Nodo* cabeza) {
        if (cabeza == nullptr) {
            cout << "Lista vacia.\n";
            return;
        }

        Nodo* actual = cabeza;
        cout << "Elementos en la lista:\n";
        do {
            cout << "- " << actual->persona.nombre << " (" << actual->persona.cedula << ")\n";
            actual = actual->siguiente;
        } while (actual != cabeza);
    }

    // 4. MÉTODO ELIMINAR
    static void eliminar(Nodo*& cabeza, string cedulaBuscada) {
        if (cabeza == nullptr) return;

        Nodo* actual = cabeza;
        bool encontrado = false;

        do {
            if (actual->persona.cedula == cedulaBuscada) {
                encontrado = true;
                break;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);

        if (!encontrado) return;

        // Caso: Único nodo
        if (actual->siguiente == cabeza && actual->anterior == cabeza) {
            delete actual;
            cabeza = nullptr;
            return;
        }

        // Caso general: Desconectar nodo del medio/extremos
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;

        // Si borramos la cabeza, mover el puntero cabeza al siguiente
        if (actual == cabeza) {
            cabeza = actual->siguiente;
        }

        delete actual;
    }
};

int main() {
    Nodo* cabeza = nullptr;

    // Pruebas para ir avanzando paso a paso en Python Tutor
    Nodo::insertar(cabeza, "1711", "Ana", "Perez");
    Nodo::insertar(cabeza, "1722", "Luis", "Gomez");
    Nodo::insertar(cabeza, "1733", "Carlos", "Ruiz");

    Nodo::imprimir(cabeza);

    Nodo::buscar(cabeza, "1722");

    Nodo::eliminar(cabeza, "1711");
    
    Nodo::imprimir(cabeza);

    return 0;
}