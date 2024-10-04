#pragma once
#include "Figura3D.h"
#include "Triangulo.h"  

class Piramide :
    public Figura3D
{
public:
    Triangulo trib;  // La base de la pirámide
    int altura;
public:
    Piramide(const std::string& nombre, int grosorBords, int color, const Triangulo& trib, int altura)
        : Figura3D(nombre, grosorBords, color), trib(trib), altura(altura) {}

    void dibujar() const override;
    int calcularVolumen() const override;

};

