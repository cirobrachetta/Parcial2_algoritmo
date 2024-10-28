#include "Menu.hpp"
#include <iostream>
#include <exception>
#include <limits>
#include <memory>

void mostrarMenu() {
    cout << "\n----- Sistema de Gestion -----\n";
    cout << "1. Agregar Proveedor\n";
    cout << "2. Mostrar Proveedores\n";
    cout << "3. Modificar Proveedor\n";
    cout << "4. Eliminar Proveedor\n";
    cout << "5. Crear Pedido\n";
    cout << "6. Ver Pedidos\n";
    cout << "7. Eliminar un Pedido\n";
    cout << "8. Agregar Empleado\n";
    cout << "9. Mostrar Empleados\n";
    cout << "10. Salir\n";
    cout << "Seleccione una opcion: ";
}

void gestionarMenu(ControladorProveedor& controladorProveedor, ControladorPedidos& controladorPedidos, ControladorEmpleados& controladorEmpleados) {
    int opcion;
    bool continuar = true;

    while (continuar) {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Intente nuevamente.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                int id = 0;
                string nombre, direccion;
                cout << "Ingrese nombre del proveedor: ";
                cin >> nombre;
                cout << "Ingrese direccion del proveedor: ";
                cin.ignore();
                getline(cin, direccion);
                controladorProveedor.agregarProveedor(id, nombre, direccion);
                id++;
                cout << "Proveedor agregado correctamente.\n";
                break;
            }
            case 2:
                controladorProveedor.mostrarProveedores();
                break;
            case 3: {
                int id;
                string nuevoNombre, nuevaDireccion;
                cout << "Ingrese ID del proveedor a modificar: ";
                cin >> id;
                cout << "Ingrese el nuevo nombre: ";
                cin >> nuevoNombre;
                cout << "Ingrese la nueva direccion: ";
                cin.ignore();
                getline(cin, nuevaDireccion);

                if (controladorProveedor.modificarProveedor(id, nuevoNombre, nuevaDireccion)) {
                    cout << "Proveedor modificado correctamente.\n";
                } else {
                    cout << "Proveedor no encontrado.\n";
                }
                break;
            }
            case 4: {
                int id;
                cout << "Ingrese ID del proveedor a eliminar: ";
                cin >> id;

                if (controladorProveedor.eliminarProveedor(id)) {
                    cout << "Proveedor eliminado correctamente.\n";
                } else {
                    cout << "Proveedor no encontrado.\n";
                }
                break;
            }
            case 5: {
                string nombreArticulo;
                int precio, cantidad, id, idprov;

                cout << "Ingrese id del proveedor: ";
                cin >> idprov;
                auto proveedor = controladorProveedor.buscarProveedor(idprov);

                if (proveedor) {
                    id = 0;
                    cout << "Ingrese tipo de articulo/s: ";
                    cin >> nombreArticulo;
                    cout << "Ingrese precio del articulo/s: ";
                    cin >> precio;

                    Articulo articulo(nombreArticulo, precio);
                    cout << "Ingrese cantidad: ";
                    cin >> cantidad;

                    controladorPedidos.crearPedido(id, *proveedor, articulo, cantidad);

                    id++;
                    cout << "Pedido creado correctamente.\n";
                } else {
                    cout << "Proveedor no encontrado.\n";
                }
                break;
            }
            case 6: {
                const auto& pedidos = controladorPedidos.obtenerPedidos();
                if (pedidos.empty()) {
                    cout << "No hay pedidos para mostrar.\n";
                } else {
                    cout << "\nListado de Pedidos:\n";
                    for (const auto& pedido : pedidos) {
                        cout << "ID: " << pedido.getId()
                             << ", Proveedor: " << pedido.getProveedor().getNombre()
                             << ", ID Proveedor: " << pedido.getProveedor().getId()
                             << ", Articulo: " << pedido.getArticulo().getNombre()
                             << ", Cantidad: " << pedido.getCantidad()
                             << ", Precio: " << pedido.getArticulo().getPrecio() << endl;
                    }
                }
                break;
            }
            case 7: {
                int id;
                cout << "Ingrese ID del pedido a eliminar: ";
                cin >> id;
                if (controladorPedidos.eliminarPedido(id)) {
                    cout << "Pedido eliminado correctamente.\n";
                } else {
                    cout << "Error al eliminar el pedido.\n";
                }
                break;
            }
            case 8: {
                int id = 0;
                string nombre, puesto;
                cout << "Ingrese nombre del empleado: ";
                cin >> nombre;
                cout << "ingrese puesto del empleado: ";
                cin >> puesto;
                controladorEmpleados.cargarEmpleado(id, nombre, puesto);
                id++;
                cout << "Empleado agregado correctamente.\n";
                break;
            }
            case 9:
                controladorEmpleados.mostrarEmpleados();
                break;
            case 10:
                continuar = false;
                cout << "Saliendo del sistema.\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    }
}