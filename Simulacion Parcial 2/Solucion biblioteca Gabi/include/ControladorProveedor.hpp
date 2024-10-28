#pragma once

#include "Proveedor.hpp"
#include <vector>

class ControladorProveedor {
public:
    void agregarProveedor(const int id, const string& nombre, const string& direccion);
    Proveedor* buscarProveedor(const int id);
    bool modificarProveedor(const int id, const string& nuevoNombre, const string& nuevaDireccion);
    bool eliminarProveedor(const int id);
    void mostrarProveedores() const;
private:
    vector<Proveedor> Proveedores;
};