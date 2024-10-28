#include "Pedidos.hpp"

Pedido::Pedido(const int id, const Proveedor& proveedor, const Articulo& articulo, int cantidad)
    : id(id), proveedor(proveedor), articulo(articulo), cantidad(cantidad) {}

const Proveedor& Pedido::getProveedor() const {
    return proveedor;
}

const Articulo& Pedido::getArticulo() const {
    return articulo;
}

int Pedido::getCantidad() const {
    return cantidad;
}

void Pedido::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::getId() const{
    return id;
}

Pedido::~Pedido() {}