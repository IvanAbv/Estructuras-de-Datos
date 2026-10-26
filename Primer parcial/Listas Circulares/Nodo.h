#pragma once

#include "Persona.h"

#include <iostream>

using namespace std;

class Nodo {
private:
    Persona persona;
    Nodo* siguiente;
    Nodo* anterior; 

public:
    Nodo();
    Nodo(const Persona& persona, Nodo* siguiente = nullptr, Nodo* anterior = nullptr);

    Persona getPersona() const;
    Nodo* getSiguiente() const;
    Nodo* getAnterior() const;
    
    void setPersona(const Persona& persona);
    void setSiguiente(Nodo* siguiente);
    void setAnterior(Nodo* anterior);


    void insertar(Nodo*& cabeza, const string& cedula, const string& nombre, const string& apellido);
    void buscarPorCedula(Nodo* inicio, const string& cedulaBuscada);
    void eliminar(Nodo*& cabeza, Nodo*& cola, const string& cedula);
    void Imprimir(Nodo* cabeza) const;
    void ImprimirReverso(Nodo* cabeza) const; 
    void modificar(Nodo* inicio, const string& cedulaBuscada);
    int Nodo::contarNodos(Nodo* cabeza);
};