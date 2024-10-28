#include "Proveedor.hpp"

Proveedor::Proveedor(const int id, const string& nombre, const string& direccion)
    : id(id), nombre(nombre), direccion(direccion) {}

string Proveedor::getNombre() const {
    return nombre;
}

void Proveedor::setNombre(const string& nombre) {
    this -> nombre = nombre;
}

string Proveedor::getDireccion() const {
    return direccion;
}

void Proveedor::setDireccion(const string& direccion) {
    this->direccion = direccion;
}

int Proveedor::getId() const{
    return id;
}

Proveedor::~Proveedor() {}