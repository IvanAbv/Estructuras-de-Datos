
#include <iostream>
#include "Libro.h"
#include "Autor.h"
#include "Editorial.h"
#include "Pais.h"

int main() {
    Autor autor1("A-101", "Gabriel", "Garcia Marquez");
    Editorial ed1("ED-50", "Editorial Sudamericana");
    Pais pais1("P-057", "Colombia");

    Libro libro1(autor1, ed1, pais1, "978-958-04-0123-4", "Cien anos de soledad", 1967, "1ra Edicion", 471, "v1.0");

    libro1.mostrarInformacion();

    // Modificando mediante la Interfaz / Setter genérico
    Autor nuevoAutor("A-102", "Mario", "Vargas Llosa");
    libro1.getAutor().set(nuevoAutor); // Usa la interfaz universal IEntidad

    // Modificando mediante la Plantilla (Template) de la clase Libro
    libro1.setAtributo(libro1.getAno(), 1970);

    std::cout << "\n--- DATOS ACTUALIZADOS CON ENCAPSULAMIENTO CORRECTO ---\n";
    libro1.mostrarInformacion();

    return 0;
}