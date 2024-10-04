#include "IncludeGL.h"
#include "Triangulo.h"
#include <iostream>
#include "BMPTextureLoader.h"

void Triangulo::dibujar() const {
    aplicarTextura();  // Aplica la textura antes de dibujar
    //glColor3f(1.0f, 0.0f, 0.0f);  // Color R
    glBegin(GL_TRIANGLES);
    glVertex2f(-base / 2.0f, -altura / 2.0f);
    glVertex2f(base / 2.0f, -altura / 2.0f);
    glVertex2f(0.0f, altura / 2.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D); // Deshabilita la textura después de dibujar

}

int Triangulo::calcularArea() const {
    return (base * altura) / 2;
}

int Triangulo::calcularPerimetro() const {
    return 3 * base;
}

void Triangulo::cambiarTamano(int nuevaBase, int nuevaAltura) {
    base = nuevaBase;
    altura = nuevaAltura;
}

