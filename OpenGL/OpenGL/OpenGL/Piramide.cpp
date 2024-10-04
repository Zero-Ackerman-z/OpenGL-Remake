#include "IncludeGL.h"
#include "Piramide.h"
void Piramide::dibujar() const {
    aplicarTextura();  // Aplica la textura antes de dibujar
    //glColor3f(0.0f, 0.0f, 1.0f);  // Color (A)
    // Dibuja la base de la pirámide
    glBegin(GL_LINE_LOOP);
    glVertex3f(-trib.base / 2.0f, -trib.base / 2.0f, 0.0f); // Primer vértice
    glVertex3f(trib.base / 2.0f, -trib.base / 2.0f, 0.0f);  // Segundo vértice
    glVertex3f(trib.base / 2.0f, trib.base / 2.0f, 0.0f);   // Tercer vértice
    glVertex3f(-trib.base / 2.0f, trib.base / 2.0f, 0.0f);  // Cuarto vértice
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);  // Color V para las aristas laterales
    // Dibuja las aristas laterales
    glBegin(GL_LINES);
    // Arista 1
    glVertex3f(-trib.base / 2.0f, -trib.base / 2.0f, 0.0f); // Vértice 1 de la base
    glVertex3f(0.0f, 0.0f, altura);                          // Vértice superior
    // Arista 2
    glVertex3f(trib.base / 2.0f, -trib.base / 2.0f, 0.0f);  // Vértice 2 de la base
    glVertex3f(0.0f, 0.0f, altura);                          // Vértice superior
    // Arista 3
    glVertex3f(trib.base / 2.0f, trib.base / 2.0f, 0.0f);   // Vértice 3 de la base
    glVertex3f(0.0f, 0.0f, altura);                          // Vértice superior
    // Arista 4
    glVertex3f(-trib.base / 2.0f, trib.base / 2.0f, 0.0f);  // Vértice 4 de la base
    glVertex3f(0.0f, 0.0f, altura);                          // Vértice superior
    glEnd();
    glDisable(GL_TEXTURE_2D); 
}
int Piramide::calcularVolumen() const {
    return static_cast<int>((1.0 / 3.0) * trib.calcularArea() * altura);
}