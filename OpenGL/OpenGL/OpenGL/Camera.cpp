#include "Camera.h"
#include "IncludeGL.h" 
#define _USE_MATH_DEFINES // Necesario para M_PI
#define M_PI 3.14159265358979323846

void Camera::UpdateCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, aspect, nearPlane, farPlane);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(position.x, position.y, position.z,
        target.x, target.y, target.z,
        0.0f, 1.0f, 0.0f);
}
void Camera::MoveForward(float distance) {
    Vector3 direction = target - position;
    direction.Normalize(); // Aseg�rate de que el vector est� normalizado
    position += direction * distance; // Mover la c�mara hacia adelante
}
void Camera::MoveRight(float distance) {
    Vector3 direction = target - position;
    direction.Normalize();

    // Crear un vector ortogonal (90 grados) para la derecha
    Vector3 right(-direction.z, 0.0f, direction.x); // Suponiendo Y es arriba
    right.Normalize();

    position += right * distance; // Mover la c�mara a la derecha
}
void Camera::Rotate(float angle) {
    // Rotar la c�mara alrededor del eje Y
    float radian = angle * (M_PI / 180.0f); // Convertir a radianes
    float cosAngle = cos(radian);
    float sinAngle = sin(radian);

    Vector3 direction = target - position;
    target.x = position.x + direction.x * cosAngle - direction.z * sinAngle;
    target.z = position.z + direction.x * sinAngle + direction.z * cosAngle;
}