#pragma once
#include "Figura2D.h"
#include "BMPTextureLoader.h"

class Cuadrado :
    public Figura2D
{
private:
    int lado;

public:
    Cuadrado(const std::string& nombre, int grosorBords, int color, int lado)
        : Figura2D(nombre, grosorBords, color), lado(lado) {}

    void dibujar() const override;
    int calcularArea() const override;
    int calcularPerimetro() const override;
    void cambiarTamano(int nuevoLado);


  
};

