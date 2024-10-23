#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Cliente {
public:
    Cliente(const string& nombre, const string& direccion);
    string getNombre() const;
    string getDireccion() const;
private:
    string nombre;
    string direccion;
};

class Articulo {
public:
    Articulo(const string& nombre, int precio);
    string getNombre() const;
    int getPrecio() const;
private:
    string nombre;
    int precio;
};

class Pedido {
public:
    Pedido();
    Pedido(const Cliente& cliente, const Articulo& articulo, int cantidad);
    const Cliente& getCliente() const;
    const Articulo& getArticulo() const;
    int getCantidad() const;
    void procesar() const;
private:
    Cliente cliente;
    Articulo articulo;
    int cantidad;
};
