#pragma once
#include <cmath>
#include "Vector3.h"

class Camera {
private:
    Vector3 position; // Posición de la cámara
    Vector3 target;   // Punto al que la cámara está mirando
    float fov;       // Campo de visión
    float aspect;    // Relación de aspecto
    float nearPlane; // Plano cercano
    float farPlane;  // Plano lejano

public:
    // Constructor que inicializa la cámara con parámetros
    Camera(const Vector3& pos, const Vector3& tar, float fov, float aspect, float nearPlane, float farPlane)
        : position(pos), target(tar), fov(fov), aspect(aspect), nearPlane(nearPlane), farPlane(farPlane) {}

    void UpdateCamera();
    void MoveForward(float distance);
    void MoveRight(float distance);
    void Rotate(float angle);

};
