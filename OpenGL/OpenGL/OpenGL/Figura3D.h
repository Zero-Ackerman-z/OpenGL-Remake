#pragma once
#include "Figura.h"

class Figura3D : public Figura {
public:
    Figura3D(const std::string& nombre, int grosorBords, int color)
        : Figura(nombre, grosorBords, color) {}
    virtual int calcularVolumen() const = 0;
};
