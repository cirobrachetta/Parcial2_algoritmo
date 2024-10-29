#include "Articulos.hpp"

Articulo::Articulo(const string& nombre, double precio)
    : nombre(nombre), precio(precio) {}

string Articulo::getNombre() const {
    return nombre;
}

int Articulo::getPrecio() const {
    return precio;
}

Articulo::~Articulo() {}