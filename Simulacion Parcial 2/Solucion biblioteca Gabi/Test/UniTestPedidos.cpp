#include <iostream>
#include "TestEvaluator.hpp"
#include "Pedidos.hpp"
#include "ControladorPedidos.hpp"
#include "Proveedor.hpp"
#include "ControladorProveedor.hpp"
#include "ControladorEmpleados.hpp"

int main() {
    TestEvaluator te;
    te.title("Pruebas de ControladorPedidos");

    // Instanciación de ControladorPedidos
    ControladorPedidos controladorPedidos;

    // Prueba de agregar pedido
    Proveedor proveedor(0, "Proveedor de prueba", "Calle Falsa 123");
    Articulo articulo("Articulo de prueba", 100);
    controladorPedidos.crearPedido(0, proveedor, articulo, 5); // Agrega un pedido con proveedor y artículo
    const auto& pedidos = controladorPedidos.obtenerPedidos();
    te.evaluate("Agregar pedido", !pedidos.empty());

    // Prueba de buscar pedido existente
    bool pedidoEncontrado = !pedidos.empty() && pedidos[0].getProveedor().getNombre() == "Proveedor de prueba";
    te.evaluate("Buscar pedido existente", pedidoEncontrado);

    // Prueba de eliminar pedido
    te.evaluate("Eliminar pedido", controladorPedidos.eliminarPedido(0));

    te.title("Pruebas de ControladorProveedors");

    // Instanciación de ControladorProveedors
    ControladorProveedor controladorProveedor;

    // Prueba de agregar proveedor
    controladorProveedor.agregarProveedor(1, "Proveedor de prueba", "Calle Falsa 354");
    Proveedor* proveedorEncontrado = controladorProveedor.buscarProveedor(1);
    te.evaluate("Agregar proveedor", proveedorEncontrado != nullptr);

    // Prueba de buscar proveedor existente
    te.evaluate("Buscar proveedor existente", proveedorEncontrado != nullptr && proveedorEncontrado->getNombre() == "Proveedor de prueba");

    te.title("Pruebas de ControladorEmpleados");

    // Instanciación de ControladorEmpleados
    ControladorEmpleados controladorEmpleados;

    // Prueba de agregar empleado
    controladorEmpleados.cargarEmpleado(0, "Empleado de prueba", "plomero");
    const auto& empleados = controladorEmpleados.obtenerEmpleados();
    te.evaluate("Agregar empleado", !empleados.empty());

    // Prueba de mostrar empleado existente
    bool empleadoEncontrado = !empleados.empty() && empleados[0]->getNombre() == "Empleado de prueba";
    te.evaluate("Mostrar empleado existente", empleadoEncontrado);

    // Resumen final de pruebas
    te.summary();

    cout << "Pruebas unitarias completadas. Presione cualquier tecla para continuar..." << endl;
    cin.get();
    
    return 0;
}