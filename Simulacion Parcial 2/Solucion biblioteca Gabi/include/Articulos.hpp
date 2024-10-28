#pragma once
#include <iostream>
using namespace std;
#include <string>

class Articulo {
public:
    Articulo(const string& nombre, double precio);
    string getNombre() const;
    int getPrecio() const;
private:
    string nombre;
    int precio;
};