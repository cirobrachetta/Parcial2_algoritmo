#pragma once

#include <memory>
#include "ControladorProveedor.hpp"
#include "ControladorPedidos.hpp"
#include "ControladorEmpleados.hpp"
#include "Articulos.hpp"

// Funciones del menú
void mostrarMenu();
void gestionarMenu(ControladorProveedor& controladorProveedor, ControladorPedidos& controladorPedidos, ControladorEmpleados& controladorEmpleados);

// Función para validar que el Proveedor exista
shared_ptr<Proveedor> obtenerProveedorExistente(ControladorProveedor& controladorProveedor);
