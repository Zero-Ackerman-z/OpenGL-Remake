#include "IncludeGL.h"
#include "Cubo.h"
void Cubo::dibujar() const {
    aplicarTextura();  
    //glColor3f(0.0f, 1.0f, 0.0f);  // Color (V)
    float lado = cuad.calcularPerimetro() / 4.0f;  

    // Dibuja las 6 caras del cubo
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // Mueve la posición del cubo
    //for (int i = 0; i < 6; ++i) {
    //    // Cambiar las caras del cubo en diferentes orientaciones 
    //    glPushMatrix();
    //    // ajustar la posición y orientación para cada cara del cubo
    //    glutWireCube(lado);  // Dibuja un cubo usando el lado del cuadrado
    //    glPopMatrix();
    //}glBegin(GL_QUADS);
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, -lado / 2, lado / 2);  
    glVertex3f(lado / 2, -lado / 2, lado / 2);   
    glVertex3f(lado / 2, lado / 2, lado / 2);    
    glVertex3f(-lado / 2, lado / 2, lado / 2);   
    glEnd();

    // Cara trasera
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, -lado / 2, -lado / 2);  
    glVertex3f(lado / 2, -lado / 2, -lado / 2);  
    glVertex3f(lado / 2, lado / 2, -lado / 2);    
    glVertex3f(-lado / 2, lado / 2, -lado / 2);   
    glEnd();

    // Cara izquierda
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, -lado / 2, -lado / 2);  
    glVertex3f(-lado / 2, -lado / 2, lado / 2);   
    glVertex3f(-lado / 2, lado / 2, lado / 2);    
    glVertex3f(-lado / 2, lado / 2, -lado / 2);   
    glEnd();

    // Cara derecha
    glBegin(GL_QUADS);
    glVertex3f(lado / 2, -lado / 2, -lado / 2);  
    glVertex3f(lado / 2, -lado / 2, lado / 2);   
    glVertex3f(lado / 2, lado / 2, lado / 2);    
    glVertex3f(lado / 2, lado / 2, -lado / 2);   
    glEnd();

    // Cara superior
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, lado / 2, -lado / 2);  
    glVertex3f(lado / 2, lado / 2, -lado / 2);   
    glVertex3f(lado / 2, lado / 2, lado / 2);    
    glVertex3f(-lado / 2, lado / 2, lado / 2);   
    glEnd();

    // Cara inferior
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, -lado / 2, -lado / 2);  
    glVertex3f(lado / 2, -lado / 2, -lado / 2);   
    glVertex3f(lado / 2, -lado / 2, lado / 2);    
    glVertex3f(-lado / 2, -lado / 2, lado / 2);   
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

int Cubo::calcularVolumen() const {
       return pow(cuad.calcularArea() / 4.0f, 3); // Volumen del cubo

    // return cuad.calcularArea() * cuad.calcularArea(); // Volumen del cubo
}


