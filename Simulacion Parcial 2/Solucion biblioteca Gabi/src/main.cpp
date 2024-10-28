#include "ControladorProveedor.hpp"
#include "ControladorPedidos.hpp"
#include "ControladorEmpleados.hpp"
#include "Menu.hpp"

int main() {
    ControladorProveedor controladorProveedores;
    ControladorPedidos controladorPedidos;
    ControladorEmpleados controladorEmpleados;

    gestionarMenu(controladorProveedores, controladorPedidos, controladorEmpleados);

    return 0;
}