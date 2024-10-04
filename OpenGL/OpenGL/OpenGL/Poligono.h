#pragma once
#include <vector>
#include "Punto3D.h"

class Poligono {
public:
    std::vector<Punto3D> vertices;  // Lista de vértices 

    // Agrega un vértice al polígono
    void agregarVertice(const Punto3D& punto);

    void dibujar() const;
};
