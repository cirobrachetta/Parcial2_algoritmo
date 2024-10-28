#include "ControladorPedidos.hpp"

void ControladorPedidos::crearPedido(const int id, const Cliente& cliente, const Articulo& articulo, int cantidad) {
    pedidos.emplace_back(id, cliente, articulo, cantidad);
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