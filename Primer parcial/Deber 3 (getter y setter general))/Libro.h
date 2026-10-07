#if !defined(LIBRO_H)
#define LIBRO_H

#pragma once

#include <string>
#include "IEntidad.h"
#include "Autor.h"
#include "Editorial.h"
#include "Pais.h"

class Libro {
private:
    // Todas las variables son estrictamente PRIVADAS
    Autor autor;
    Editorial editorial;
    Pais pais;

    std::string isbn;
    std::string titulo;
    int ano;
    std::string edicion;
    int numPaginas;
    std::string version;

public:
    Libro() = default;

    Libro(Autor a, Editorial ed, Pais p, 
          std::string isbn, std::string titulo, int ano, 
          std::string edicion, int numPaginas, std::string version)
        : autor(a), editorial(ed), pais(p), isbn(isbn), 
          titulo(titulo), ano(ano), edicion(edicion), 
          numPaginas(numPaginas), version(version) {}

    // ------------------------------------------
    // MÉTODOS PLANTILLA (GETTER Y SETTER UNIVERSAL)
    // ------------------------------------------

    // Setter universal para asignar cualquier tipo de dato a un miembro por referencia
    template <typename T>
    void setAtributo(T& atributoPrivado, const T& nuevoValor) {
        atributoPrivado = nuevoValor;
    }

    // Getter universal
    template <typename T>
    const T& getAtributo(const T& atributoPrivado) const {
        return atributoPrivado;
    }

    // Getters de referencia para acceder internamente desde el main
    Autor& getAutor() { return autor; }
    Editorial& getEditorial() { return editorial; }
    Pais& getPais() { return pais; }
    int& getAno() { return ano; }
    std::string& getTitulo() { return titulo; }

    void mostrarInformacion() const {
        std::cout << "========================================\n";
        std::cout << "Titulo: " << titulo << "\n";
        std::cout << "ISBN: " << isbn << " | Ano: " << ano << "\n";
        std::cout << "Edicion: " << edicion << " | Pag: " << numPaginas << " | Version: " << version << "\n";
        std::cout << "Autor: " << autor.getNombre() << " " << autor.getApellido() << " (ID: " << autor.getId() << ")\n";
        std::cout << "Editorial: " << editorial.getNombre() << " (ID: " << editorial.getIdEditorial() << ")\n";
        std::cout << "Pais: " << pais.getNombre() << " (ID: " << pais.getIdPais() << ")\n";
        std::cout << "========================================\n";
    }
};

#endif