#include "ControladorCliente.hpp"
#include "ControladorPedidos.hpp"
#include "Menu.hpp"

int main() {
    ControladorClientes controladorClientes;
    ControladorPedidos controladorPedidos;

    gestionarMenu(controladorClientes, controladorPedidos);

    return 0;
}