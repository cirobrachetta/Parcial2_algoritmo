#include "Pedidos.hpp"
#include "TestEvaluator.hpp"

int main() {
    // Crear una instancia de TestEvaluator
    TestEvaluator te;

    // Título general de las pruebas
    te.title("Pruebas de la clase Cliente");

    // Test para la clase Cliente
    Cliente cliente("Juan Pérez", "123 Calle Falsa");
    te.evaluate("Cliente getNombre", cliente.getNombre() == "Juan Pérez");
    te.evaluate("Cliente getDireccion", cliente.getDireccion() == "123 Calle Falsa");

    // Título para la clase Articulo
    te.title("Pruebas de la clase Articulo");

    // Test para la clase Articulo
    Articulo articulo("Laptop", 1500);
    te.evaluate("Articulo getNombre", articulo.getNombre() == "Laptop");
    te.evaluate("Articulo getPrecio", articulo.getPrecio() == 1500);

    // Título para la clase Pedido
    te.title("Pruebas de la clase Pedido");

    // Test para la clase Pedido
    Pedido pedido(cliente, articulo, 3);
    te.evaluate("Pedido getCliente", pedido.getCliente().getNombre() == "Juan Pérez");
    te.evaluate("Pedido getArticulo", pedido.getArticulo().getNombre() == "Laptop");
    te.evaluate("Pedido getCantidad", pedido.getCantidad() == 3);

    // Test para Pedido por defecto
    Pedido pedidoPorDefecto;
    te.evaluate("Pedido por defecto - Cliente", pedidoPorDefecto.getCliente().getNombre() == "Nombre por defecto");
    te.evaluate("Pedido por defecto - Articulo", pedidoPorDefecto.getArticulo().getNombre() == "Articulo por defecto");
    te.evaluate("Pedido por defecto - Cantidad", pedidoPorDefecto.getCantidad() == 0);

    // Mostrar el resumen de los tests
    te.summary();

    return 0;
}
