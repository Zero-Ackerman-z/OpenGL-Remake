#pragma once
#include <cmath>
#include "Vector3.h"

class Camera {
private:
    Vector3 position; // Posici�n de la c�mara
    Vector3 target;   // Punto al que la c�mara est� mirando
    float fov;       // Campo de visi�n
    float aspect;    // Relaci�n de aspecto
    float nearPlane; // Plano cercano
    float farPlane;  // Plano lejano

public:
    // Constructor que inicializa la c�mara con par�metros
    Camera(const Vector3& pos, const Vector3& tar, float fov, float aspect, float nearPlane, float farPlane)
        : position(pos), target(tar), fov(fov), aspect(aspect), nearPlane(nearPlane), farPlane(farPlane) {}

    void UpdateCamera();
    void MoveForward(float distance);
    void MoveRight(float distance);
    void Rotate(float angle);

};
