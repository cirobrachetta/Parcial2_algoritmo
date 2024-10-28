#include "ControladorCliente.hpp"

void ControladorClientes::agregarCliente(const string& nombre, const string& direccion) {
    clientes.emplace_back(nombre, direccion);
}

Cliente* ControladorClientes::buscarCliente(const string& nombre) {
    for (auto& cliente : clientes) {
        if (cliente.getNombre() == nombre) {
            return &cliente;
        }
    }
    return nullptr;
}