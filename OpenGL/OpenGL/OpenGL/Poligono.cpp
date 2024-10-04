#include "Poligono.h"
#include <GL/glut.h>

void Poligono::agregarVertice(const Punto3D& punto) {
    vertices.push_back(punto);  // A�adir punto a la lista de v�rtices
}

void Poligono::dibujar() const {
    glBegin(GL_POLYGON);  
    for (const auto& vertice : vertices) {
        glVertex3f(vertice.x, vertice.y, vertice.z);  
    }
    glEnd();
}
