#pragma once
#include "Figura2D.h"
class Circulo :
    public Figura2D
{
private:
    int radio;

public:
    Circulo(const std::string& nombre, int grosorBords, int color, int radio)
        : Figura2D(nombre, grosorBords, color), radio(radio) {}

    void dibujar() const override;
    int calcularArea() const override;
    int calcularPerimetro() const override;
    void cambiarTamano(int nuevoRadio);

};

