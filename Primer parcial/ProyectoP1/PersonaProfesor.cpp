#include "PersonaProfesor.h"
#include "Utilidades.h"
#include <iostream>

using namespace std;

PersonaProfesor::PersonaProfesor(const string& c, const string& n, const string& a)
    : Persona(c, n, a) {}

void PersonaProfesor::mostrarDatos() const {
    cout << "Cedula: " << cedula << " | " << nombre << " " << apellido << endl;
}

string PersonaProfesor::getId() const { return cedula; }
void PersonaProfesor::mostrar() const { mostrarDatos(); }

void PersonaProfesor::setNombre(const string& n)   { nombre = n; }
void PersonaProfesor::setApellido(const string& a) { apellido = a; }

string PersonaProfesor::serializar() const { return cedula + "|" + nombre + "|" + apellido; }

bool PersonaProfesor::deserializar(const string& linea, PersonaProfesor& p) {
    vector<string> c = dividir(linea, '|');
    if (c.size() != 3) return false;
    if (!esCedulaValida(c[0]) || !esNombreValido(c[1]) || !esNombreValido(c[2])) return false;
    p = PersonaProfesor(c[0], c[1], c[2]);
    return true;
}
