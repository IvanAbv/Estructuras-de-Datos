#if !defined EDITORIAL_H
#define EDITORIAL_H

#include <string>
#include "IEntidad.h"

#pragma once

class Editorial : public IEntidad<Editorial> {
private:
    std::string idEditorial;
    std::string nombre;

public:
    Editorial() = default;
    Editorial(std::string idEditorial, std::string nombre)
        : idEditorial(idEditorial), nombre(nombre) {}

    std::string getIdEditorial() const { return idEditorial; }
    std::string getNombre() const { return nombre; }

    void setIdEditorial(const std::string& nuevoId) { idEditorial = nuevoId; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }

    // Implementación de la Interfaz Universal
    void set(const Editorial& nuevoValor) override {
        *this = nuevoValor;
    }

    const Editorial& get() const override {
        return *this;
    }
};

#endif