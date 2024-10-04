#pragma once
#include "Figura.h"

class Figura2D : public Figura {
public:
    Figura2D(const std::string& nombre, int grosorBords, int color )
        : Figura(nombre, grosorBords, color ) {}

    virtual int calcularArea() const = 0;
    virtual int calcularPerimetro() const = 0;

};
