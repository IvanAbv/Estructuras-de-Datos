#ifndef PERSONAPROFESOR_H
#define PERSONAPROFESOR_H

#include "Persona.h"

class PersonaProfesor : public Persona {
public:
    PersonaProfesor(const std::string& c = "", const std::string& n = "",
                    const std::string& a = "");

    void mostrarDatos() const;

    std::string getId() const;
    void mostrar() const;

    void setNombre(const std::string& n);
    void setApellido(const std::string& a);

    std::string serializar() const;
    static bool deserializar(const std::string& linea, PersonaProfesor& p);
};

#endif
