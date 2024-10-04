#pragma once
#include "Figura3D.h"
#include "Cuadrado.h"  

class Cubo :
    public Figura3D
{
private:

    Cuadrado cuad;  

public:

    Cubo(const std::string& nombre, int grosorBords, int color, int lado)
        : Figura3D(nombre, grosorBords, color), cuad(nombre, grosorBords, color, lado) {}

    void dibujar() const override;
    int calcularVolumen() const override;  


};

