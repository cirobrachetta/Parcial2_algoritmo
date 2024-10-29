#include <iostream>
#include "ControladorEmpleados.hpp"

void ControladorEmpleados::cargarEmpleado(int id, const string& nombre, const string& puesto) {
    auto empleado = make_shared<Empleado>(id, nombre, puesto);
    empleados.push_back(empleado);
}

void ControladorEmpleados::mostrarEmpleados() const {
    for (const auto& empleado : empleados) {
        cout << "ID: " << empleado->getId() 
             << ", Nombre: " << empleado->getNombre() 
             << ", Puesto: " << empleado->getPuesto() << endl;
    }
}

const vector<shared_ptr<Empleado>>& ControladorEmpleados::obtenerEmpleados() const {
    return empleados;
}