#pragma once

#include <string>
#include <iostream>
using namespace std;

class Empleado {
private:
    int id;
    string nombre;
    string puesto;

public:
    Empleado(int id, const string& nombre, const string& puesto);
    int getId() const;
    string getNombre() const;
    string getPuesto() const;

    void setNombre(const string& nombre);
    void setPuesto(const string& puesto);
};