#pragma once

#include "Persona.h"

#include "Persona.h"
#include <iostream>

using namespace std;

class Nodo {
private:
    Persona persona;
    Nodo* siguiente;

public:
    // Constructores
    Nodo();
    Nodo(const Persona& persona, Nodo* siguiente = nullptr);

    // Getters y Setters básicos
    Persona getPersona() const;
    Nodo* getSiguiente() const;
    void setPersona(const Persona& persona);
    void setSiguiente(Nodo* siguiente);

    // Métodos de la lista circular manejados desde el Nodo raíz/cabeza
    void insertar(Nodo*& cabeza, const string& cedula, const string& nombre, const string& apellido);
    void buscarPorCedula(Nodo* inicio, const string& cedulaBuscada);
    bool eliminar(Nodo*& cabeza, const string& cedula);
    void imprimir(Nodo* cabeza) const;
};