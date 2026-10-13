template <typename T>

#pragma once

class IEntidad {
public:
    virtual ~IEntidad() = default;

    // Métodos universales pasando/devolviendo por referencia
    virtual void set(const T& nuevoValor) = 0;
    virtual const T& get() const = 0;
};