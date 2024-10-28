#include "Empleado.hpp"

Empleado::Empleado(int id, const string& nombre, const string& puesto)
    : id(id), nombre(nombre), puesto(puesto) {}

int Empleado::getId() const {
    return id;
}

string Empleado::getNombre() const {
    return nombre;
}

string Empleado::getPuesto() const {
    return puesto;
}

void Empleado::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Empleado::setPuesto(const string& puesto) {
    this->puesto = puesto;
}
