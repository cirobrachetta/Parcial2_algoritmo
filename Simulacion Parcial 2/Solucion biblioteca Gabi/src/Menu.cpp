#include "Menu.hpp"
#include <iostream>
#include <exception>
#include <limits>
#include <memory>

void mostrarMenu() {
    cout << "\n----- Sistema de Gestion -----\n";
    cout << "1. Agregar Cliente\n";
    cout << "2. Crear Pedido\n";
    cout << "3. Ver Pedidos\n";
    cout << "4. Eliminar un pedido\n";
    cout << "5. Salir \n";
    cout << "Seleccione una opcion: ";
}

void gestionarMenu(ControladorClientes& controladorClientes, ControladorPedidos& controladorPedidos) {

    int opcion;
    bool continuar = true;

    while (continuar) {
        mostrarMenu();
        cin >> opcion;
        
        // Evita problemas de entrada invalida al limpiar `cin`
        if (cin.fail()) {
            cin.clear(); // Limpia el error de `cin`
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada restante
            cout << "Opcion invalida. Intente nuevamente.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                string nombre, direccion;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese direccion del cliente: ";
                cin.ignore();  // Ignora el salto de línea anterior
                getline(cin, direccion);  // Lee la direccion completa
                controladorClientes.agregarCliente(nombre, direccion);
                cout << "Cliente agregado correctamente.\n";
                break;
            }
            case 2: {
                string nombreCliente, nombreArticulo;
                int precio, cantidad, id;

                cout << "Ingrese nombre del cliente: ";
                cin >> nombreCliente;
                Cliente* cliente = controladorClientes.buscarCliente(nombreCliente);
                
                if (cliente) {
                    id = 0;

                    cout << "Ingrese tipo de articulo/s: ";
                    cin >> nombreArticulo;

                    cout << "Ingrese precio del articulo/s: ";
                    cin >> precio;

                    Articulo articulo(nombreArticulo, precio);
                    cout << "Ingrese cantidad: ";
                    cin >> cantidad;

                    controladorPedidos.crearPedido(id, *cliente, articulo, cantidad);

                    id++;
                    cout << "Pedido creado correctamente.\n";
                } else {
                    cout << "Cliente no encontrado.\n";
                }
                break;
            }
            case 3: {
                const auto& pedidos = controladorPedidos.obtenerPedidos();
                if (pedidos.empty()) {
                    cout << "No hay pedidos para mostrar.\n";
                } else {
                    cout << "\nListado de Pedidos:\n";
                    for (const auto& pedido : pedidos) {
                        cout << "ID: " << pedido.getId()
                                  << ", Cliente: " << pedido.getCliente().getNombre()
                                  << ", Articulo: " << pedido.getArticulo().getNombre()
                                  << ", Cantidad: " << pedido.getCantidad()
                                  << ", Precio: " << pedido.getArticulo().getPrecio() << endl;
                    }
                }
                break;
            }

            case 4:
                int id;
                cout << "ingrese id del pedido a eliminar: ";
                cin >> id; 
                if(controladorPedidos.eliminarPedido(id)){
                    cout << "pedido eliminado correctamente" << endl;
                }
                else{
                    cout << "error al eliminar el pedido" << endl;
                }
                break;

            case 5:
                continuar = false;
                cout << "Saliendo del sistema.\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    }
}