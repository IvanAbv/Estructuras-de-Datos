#include "Persona.h"

Persona::Persona() {
    this->cedula = "";
    this->nombre = "";
    this->apellido = "";
}

Persona::Persona(const string& cedula, const string& nombre, const string& apellido) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
}

string Persona::getCedula() const {
    return this->cedula;
}

string Persona::getNombre() const {
    return this->nombre;
}

string Persona::getApellido() const {
    return this->apellido;
}

void Persona::setCedula(const string& cedula) {
    this->cedula = cedula;
}

void Persona::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Persona::setApellido(const string& apellido) {
    this->apellido = apellido;
}