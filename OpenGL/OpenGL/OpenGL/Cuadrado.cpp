#include "IncludeGL.h"
#include "Cuadrado.h"

void Cuadrado::dibujar() const {
    aplicarTextura(); 

    //glColor3f(1.0f, 1.0f, 0.0f);  // Color (A)
    glBegin(GL_QUADS);
    glVertex2f(-lado / 2.0f, -lado / 2.0f);
    glVertex2f(lado / 2.0f, -lado / 2.0f);
    glVertex2f(lado / 2.0f, lado / 2.0f);
    glVertex2f(-lado / 2.0f, lado / 2.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D); // Deshabilita la textura después de dibujar

}

int Cuadrado::calcularArea() const {
    return lado * lado;
}

int Cuadrado::calcularPerimetro() const {
    return 4 * lado;
}

void Cuadrado::cambiarTamano(int nuevoLado) {
    lado = nuevoLado;
}

