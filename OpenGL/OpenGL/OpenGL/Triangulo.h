#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
public:
    int base;
    int altura;

public:
    Triangulo(const std::string& nombre, int grosorBords, int color, int base, int altura)
        : Figura2D(nombre, grosorBords, color), base(base), altura(altura) {}

    void dibujar() const override;
    int calcularArea() const override;
    int calcularPerimetro() const override;
    void cambiarTamano(int nuevaBase, int nuevaAltura);

};

