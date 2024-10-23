#include "../include/Pedidos.hpp"

// Constructor de Cliente
Cliente::Cliente(const string& nombre, const string& direccion)
    : nombre(nombre), direccion(direccion) {}

// Método para obtener el nombre
string Cliente::getNombre() const {
    return nombre;
}

// Método para obtener la dirección
string Cliente::getDireccion() const {
    return direccion;
}

// Implementación de la clase Articulo

// Constructor de Articulo
Articulo::Articulo(const string& nombre, int precio)
    : nombre(nombre), precio(precio) {}

// Método para obtener el nombre
string Articulo::getNombre() const {
    return nombre;
}

// Método para obtener el precio
int Articulo::getPrecio() const {
    return precio;
}

// Implementación de la clase Pedido

// Constructor de Pedido
Pedido::Pedido()
    : cliente("Nombre por defecto", "Direccion por defecto"), // Inicializa con valores predeterminados
      articulo("Articulo por defecto", 0),   // Inicializa con un artículo por defecto
      cantidad(0) {}                          // Inicializa cantidad a 0

// Constructor que acepta parámetros
Pedido::Pedido(const Cliente& cliente, const Articulo& articulo, int cantidad)
    : cliente(cliente), articulo(articulo), cantidad(cantidad) {}

// Método para obtener el cliente
const Cliente& Pedido::getCliente() const {
    return cliente;
}

const Articulo& Pedido::getArticulo() const {
    return articulo;
}

// Método para obtener la cantidad
int Pedido::getCantidad() const {
    return cantidad;
}

// Implementación del método procesar
void Pedido::procesar() const {
    cout << "Procesando el pedido de " << cliente.getNombre() << " por " 
              << cantidad << " de " << articulo.getNombre() << endl;
}