#if !defined PAIS_H
#define PAIS_H

#include <string>
#include "IEntidad.h"

#pragma once

class Pais : public IEntidad<Pais> {
private:
    std::string idPais;
    std::string nombre;

public:
    Pais() = default;
    Pais(std::string idPais, std::string nombre)
        : idPais(idPais), nombre(nombre) {}

    std::string getIdPais() const { return idPais; }
    std::string getNombre() const { return nombre; }

    void setIdPais(const std::string& nuevoId) { idPais = nuevoId; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }

    // Implementación de la Interfaz Universal
    void set(const Pais& nuevoValor) override {
        *this = nuevoValor;
    }

    const Pais& get() const override {
        return *this;
    }
};

#endif