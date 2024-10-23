#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

#include "Pedidos.hpp"

TEST_CASE("Test Cliente", "[Cliente]") {
    Cliente cliente("Juan Pérez", "123 Calle Falsa");
    
    REQUIRE(cliente.getNombre() == "Juan Pérez");
    REQUIRE(cliente.getDireccion() == "123 Calle Falsa");
}

TEST_CASE("Test Articulo", "[Articulo]") {
    Articulo articulo("Laptop", 1500);
    
    REQUIRE(articulo.getNombre() == "Laptop");
    REQUIRE(articulo.getPrecio() == 1500);
}

TEST_CASE("Test Pedido", "[Pedido]") {
    Cliente cliente("Ana García", "456 Calle Verdadera");
    Articulo articulo("Teléfono", 800);
    Pedido pedido(cliente, articulo, 3);
    
    REQUIRE(pedido.getCliente().getNombre() == "Ana García");
    REQUIRE(pedido.getArticulo().getNombre() == "Teléfono");
    REQUIRE(pedido.getCantidad() == 3);
}

TEST_CASE("Test Pedido por defecto", "[Pedido]") {
    Pedido pedido;
    
    REQUIRE(pedido.getCliente().getNombre() == "Nombre por defecto");
    REQUIRE(pedido.getArticulo().getNombre() == "Articulo por defecto");
    REQUIRE(pedido.getCantidad() == 0);
}
