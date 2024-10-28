#include "Pedidos.hpp"

Pedido::Pedido(const int id, const Cliente& cliente, const Articulo& articulo, int cantidad)
    : id(id), cliente(cliente), articulo(articulo), cantidad(cantidad) {}

const Cliente& Pedido::getCliente() const {
    return cliente;
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