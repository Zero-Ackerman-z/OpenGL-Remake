#include "Vector3.h"
#include <cmath> // Para sqrt()

void Vector3::Normalize() {
    float length = sqrt(x * x + y * y + z * z);
    if (length > 0) { // Para evitar la división por cero
        x /= length;
        y /= length;
        z /= length;
    }
}
