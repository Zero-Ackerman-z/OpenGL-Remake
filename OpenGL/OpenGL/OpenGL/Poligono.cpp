#include "Poligono.h"
#include <GL/glut.h>

void Poligono::agregarVertice(const Punto3D& punto) {
    vertices.push_back(punto);  // Añadir punto a la lista de vértices
}

void Poligono::dibujar() const {
    glBegin(GL_POLYGON);  
    for (const auto& vertice : vertices) {
        glVertex3f(vertice.x, vertice.y, vertice.z);  
    }
    glEnd();
}
