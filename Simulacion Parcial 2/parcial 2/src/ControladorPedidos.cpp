#include "ControladorPedidos.hpp"

void ControladorPedidos::crearPedido(const int id, const Proveedor& proveedor, const Articulo& articulo, int cantidad) {
    pedidos.emplace_back(id, proveedor, articulo, cantidad);
}

const vector<Pedido>& ControladorPedidos::obtenerPedidos() const {
    return pedidos;
}

bool ControladorPedidos::eliminarPedido(const int id) {
    if (id >= 0 && id < pedidos.size()) {
            pedidos.erase(pedidos.begin() + id);
            return true;  // Eliminación exitosa
        }
        return false;  // No se eliminó nada
    }