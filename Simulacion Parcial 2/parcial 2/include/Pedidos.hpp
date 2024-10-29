#pragma once

#include "Proveedor.hpp"
#include "Articulos.hpp"

class Pedido {
public:
    Pedido(const int id, const Proveedor& proveedor, const Articulo& articulo, int cantidad);
    const Proveedor& getProveedor() const;
    const Articulo& getArticulo() const;
    int getCantidad() const;
    void setCantidad(int cantidad);
    int getId() const;
    ~Pedido();
private:
    Proveedor proveedor;
    Articulo articulo;
    int cantidad, id;
};