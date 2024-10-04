#pragma once
#include "Figura3D.h"
class Esfera :
    public Figura3D
{
private:
    int radio;

public:
    Esfera(const std::string& nombre, int grosorBords, int color, int radio)
        : Figura3D(nombre, grosorBords, color), radio(radio) {}
    void dibujar() const override;
    int calcularVolumen() const override;

};

