#include <iostream>
#include <string>

#include "IEntidad.h"

#pragma once

class Autor : public IEntidad<Autor> {
private:
    std::string id;
    std::string nombre;
    std::string apellido;

public:
    Autor() = default;

    Autor(std::string id, std::string nombre, std::string apellido)
        : id(id), nombre(nombre), apellido(apellido) {}

    // Getters específicos
    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }

    // Setters específicos
    void setId(const std::string& nuevoId) { id = nuevoId; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setApellido(const std::string& nuevoApellido) { apellido = nuevoApellido; }

    // Implementación de la Interfaz Universal
    void set(const Autor& nuevoValor) override {
        this->id = nuevoValor.id;
        this->nombre = nuevoValor.nombre;
        this->apellido = nuevoValor.apellido;
    }

    // Devuelve una referencia constante al propio objeto (*this)
    const Autor& get() const override {
        return *this;
    }
};