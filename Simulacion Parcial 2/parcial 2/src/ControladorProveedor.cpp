#include "ControladorProveedor.hpp"

void ControladorProveedor::agregarProveedor(const int id, const string& nombre, const string& direccion) {
    Proveedores.emplace_back(id, nombre, direccion);
}

Proveedor* ControladorProveedor::buscarProveedor(const int id) {
    for (auto& Proveedor : Proveedores) {
        if (Proveedor.getId() == id) {
            return &Proveedor;
        }
    }
    return nullptr;
}

bool ControladorProveedor::modificarProveedor(const int id, const string& nuevoNombre, const string& nuevaDireccion) {
    for (auto& proveedor : Proveedores) {
        if (proveedor.getId() == id) {
            proveedor.setDireccion(nuevaDireccion);
            return true; // Modificación exitosa
        }
    }
    return false; // Si no se encuentra, retorna falso
}

bool ControladorProveedor::eliminarProveedor(const int id) {
    for (auto it = Proveedores.begin(); it != Proveedores.end(); ++it) {
        if (it->getId() == id) {
            Proveedores.erase(it);
            return true; // Eliminación exitosa
        }
    }
    return false; // Si no se encuentra, retorna falso
}

void ControladorProveedor::mostrarProveedores() const {
    for (const auto& proveedor : Proveedores) {
        cout << "ID: " << proveedor.getId() 
                  << ", Nombre: " << proveedor.getNombre() 
                  << ", Dirección: " << proveedor.getDireccion() 
                  << endl;
    }
}