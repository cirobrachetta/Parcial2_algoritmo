#pragma once

#include "Cliente.hpp"
#include "Articulos.hpp"

class Pedido {
public:
    Pedido(const int id, const Cliente& cliente, const Articulo& articulo, int cantidad);
    const Cliente& getCliente() const;
    const Articulo& getArticulo() const;
    int getCantidad() const;
    void setCantidad(int cantidad);
    int getId() const;
private:
    Cliente cliente;
    Articulo articulo;
    int cantidad, id;
};