// Define M_PI if it is not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "IncludeGL.h"
#include "Circulo.h"
#include <cmath>

void Circulo::dibujar() const {
    aplicarTextura();  

   // glColor3f(1.0f, 0.0f, 0.0f);  // Color (R)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);  // Centro del círculo
    const int num_segments = 100;
    for (int i = 0; i <= num_segments; ++i) {
        float theta = 2.0f * M_PI * i / num_segments;
        float x = radio * cos(theta);
        float y = radio * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D); // Deshabilita la textura después de dibujar

}

int Circulo::calcularArea() const {
    return static_cast<int>(M_PI * radio * radio);
}

int Circulo::calcularPerimetro() const {
    return static_cast<int>(2 * M_PI * radio);
}

void Circulo::cambiarTamano(int nuevoRadio) {
    radio = nuevoRadio;
}
