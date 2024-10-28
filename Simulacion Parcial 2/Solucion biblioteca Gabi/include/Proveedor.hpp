#pragma once
#include <iostream>
using namespace std;
#include <string>

class Proveedor {
public:
    Proveedor(const int id, const string& nombre, const string& direccion);
    string getNombre() const;
    void setNombre(const string& nombre);
    string getDireccion() const;
    void setDireccion(const string& direccion);
    int getId() const;
    ~Proveedor();
private:
    int id;
    string nombre;
    string direccion;
};