#pragma once

class Punto3D {
public:
    float x, y, z;

    // Constructor para inicializar el punto en las coordenadas x, y, z
    Punto3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    void dibujar() const;
};
