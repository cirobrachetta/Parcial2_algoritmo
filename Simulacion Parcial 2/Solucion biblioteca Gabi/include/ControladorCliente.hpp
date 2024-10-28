#pragma once

#include "Cliente.hpp"
#include <vector>

class ControladorClientes {
public:
    void agregarCliente(const string& nombre, const string& direccion);
    Cliente* buscarCliente(const string& nombre);
    bool eliminarCiente();
private:
    vector<Cliente> clientes;
};