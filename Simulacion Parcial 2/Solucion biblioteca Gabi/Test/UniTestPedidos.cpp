#include <iostream>
#include "TestEvaluator.hpp"
#include "Pedidos.hpp"
#include "ControladorPedidos.hpp"
#include "Cliente.hpp"
#include "ControladorCliente.hpp"

int main() {
    TestEvaluator te;
    te.title("Pruebas de ControladorPedidos");

    // Instanciación de ControladorPedidos
    ControladorPedidos controladorPedidos;

    // Prueba de agregar pedido
    Cliente cliente("Cliente de prueba", "Calle Falsa 123");
    Articulo articulo("Articulo de prueba", 100);
    controladorPedidos.crearPedido(0, cliente, articulo, 5); // Agrega un pedido con cliente y artículo
    const auto& pedidos = controladorPedidos.obtenerPedidos();
    te.evaluate("Agregar pedido", !pedidos.empty());

    // Prueba de buscar pedido existente
    bool pedidoEncontrado = !pedidos.empty() && pedidos[0].getCliente().getNombre() == "Cliente de prueba";
    te.evaluate("Buscar pedido existente", pedidoEncontrado);

    // Prueba de eliminar pedido
    te.evaluate("Eliminar pedido", controladorPedidos.eliminarPedido(0));

    te.title("Pruebas de ControladorClientes");

    // Instanciación de ControladorClientes
    ControladorClientes controladorClientes;

    // Prueba de agregar cliente
    controladorClientes.agregarCliente("Cliente de prueba", "Calle Falsa 354");
    Cliente* clienteEncontrado = controladorClientes.buscarCliente("Cliente de prueba");
    te.evaluate("Agregar cliente", clienteEncontrado != nullptr);

    // Prueba de buscar cliente existente
    te.evaluate("Buscar cliente existente", clienteEncontrado != nullptr && clienteEncontrado->getNombre() == "Cliente de prueba");

    // Resumen final de pruebas
    te.summary();

    cout << "Pruebas unitarias completadas. Presione cualquier tecla para continuar..." << endl;
    cin.get();
    
    return 0;
}