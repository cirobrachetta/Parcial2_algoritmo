#pragma once

#include <vector>
#include <memory>
#include "Empleado.hpp"

class ControladorEmpleados {
private:
    vector<shared_ptr<Empleado>> empleados;

public:
    void cargarEmpleado(int id, const string& nombre, const string& puesto);
    void mostrarEmpleados() const;
    const std::vector<std::shared_ptr<Empleado>>& obtenerEmpleados() const; // Nuevo método
};