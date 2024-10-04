#pragma once
#include <vector>
#include "Punto3D.h"

class Poligono {
public:
    std::vector<Punto3D> vertices;  // Lista de v�rtices 

    // Agrega un v�rtice al pol�gono
    void agregarVertice(const Punto3D& punto);

    void dibujar() const;
};
