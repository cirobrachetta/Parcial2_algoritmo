#include "Cliente.hpp"

Cliente::Cliente(const string& nombre, const string& direccion)
    : nombre(nombre), direccion(direccion) {}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setDireccion(const string& direccion) {
    this->direccion = direccion;
}