#include <iostream>
#include "Nodo.h"

using namespace std;

int main() {
    Nodo* cabeza = nullptr; 
    Nodo operaciones;       

    cout << "=== 1. INSERTANDO PERSONAS ===" << endl;
    operaciones.insertar(cabeza, "1711111111", "Ana", "Perez");
    operaciones.insertar(cabeza, "1722222222", "Luis", "Gomez");
    operaciones.insertar(cabeza, "1733333333", "Carla", "Ruiz");

    cout << "\n=== 2. IMPRIMIENDO LA LISTA CIRCULAR ===" << endl;
    operaciones.imprimir(cabeza);

    cout << "\n=== 3. BUSCANDO POR CEDULA ===" << endl;
    operaciones.buscarPorCedula(cabeza, "1722222222");

    cout << "\n=== 4. ELIMINANDO A ANA (LA CABEZA) ===" << endl;
    if (operaciones.eliminar(cabeza, "1711111111")) {
        cout << "¡Eliminado correctamente!" << endl;
    }

    cout << "\n=== 5. LISTA ACTUALIZADA TRAS EL BORRADO ===" << endl;
    operaciones.imprimir(cabeza);

    return 0;
}