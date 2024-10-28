#pragma once
#include <iostream>
using namespace std;
#include <string>

class Cliente {
public:
    Cliente(const string& nombre, const string& direccion);
    string getNombre() const;
    string getDireccion() const;
    void setDireccion(const string& direccion);
private:
    string nombre;
    string direccion;
};