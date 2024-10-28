#pragma once

#include <memory>
#include "ControladorCliente.hpp"
#include "ControladorPedidos.hpp"
#include "Articulos.hpp"

// Funciones del menú
void mostrarMenu();
void gestionarMenu(ControladorClientes& controladorClientes, ControladorPedidos& controladorPedidos);

// Función para validar que el cliente exista
shared_ptr<Cliente> obtenerClienteExistente(ControladorClientes& controladorClientes);
