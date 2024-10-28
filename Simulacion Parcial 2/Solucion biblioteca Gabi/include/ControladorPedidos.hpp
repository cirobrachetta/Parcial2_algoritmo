#pragma once

#include "Pedidos.hpp"
#include <vector>

class ControladorPedidos {
public:
    void crearPedido(const int id, const Proveedor& proveedor, const Articulo& articulo, int cantidad);
    const vector<Pedido>& obtenerPedidos() const;
    bool eliminarPedido(const int id);
private:
    vector<Pedido> pedidos;
};