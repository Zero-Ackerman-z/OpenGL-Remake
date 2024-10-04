#include "Punto3D.h"
#include <GL/glut.h>

Punto3D::Punto3D(float x, float y, float z) : x(x), y(y), z(z) {}

void Punto3D::dibujar() const {
    glColor3f(1.0f, 0.0f, 0.0f);  // Color  (rojo)
    glPointSize(50.0f);  // Tamaño
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);  // Coordenadas 
    glEnd();
}