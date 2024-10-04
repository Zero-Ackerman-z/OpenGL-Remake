#pragma once
#include <cmath>
#include "IncludeGL.h"
class Vector3 {
public:
    float x, y, z;

    // Constructor por defecto
    Vector3() : x(0), y(0), z(0) {}

    // Constructor con valores
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    void Normalize();

    // Sobrecarga del operador suma
    Vector3 operator+(const Vector3& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    // Sobrecarga del operador resta
    Vector3 operator-(const Vector3& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    // Multiplicación por un escalar
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    // Magnitud del vector
    float magnitud() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Normalización del vector
    Vector3 normalizar() const {
        float mag = magnitud();
        if (mag > 0)
            return Vector3(x / mag, y / mag, z / mag);
        return Vector3();  // Devuelve un vector nulo si la magnitud es cero
    }
    // Producto cruzado entre dos vectores
    Vector3 cruz(const Vector3& v) const {
        return Vector3(
            y * v.z - z * v.y, // Componente X
            z * v.x - x * v.z, // Componente Y
            x * v.y - y * v.x  // Componente Z
        );
    }
    Vector3& operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this; // Retornar la referencia al objeto actual
    }
    // Transformaciones geométricas
    void applyTranslation(const Vector3& translation) const {
        glTranslatef(translation.x, translation.y, translation.z);
    }
    void applyScaling(const Vector3& scale) const {
        glScalef(scale.x, scale.y, scale.z);
    }

    void applyRotation(float angle, const Vector3& axis) const {
        glRotatef(angle, axis.x, axis.y, axis.z);
    }
};

