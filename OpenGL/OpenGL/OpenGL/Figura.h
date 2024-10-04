#pragma once
#include <string>
#include "IncludeGL.h"
#include <iostream>

class Figura {
protected:
    std::string nombre;
    int grosorBords;
    int color;
    GLuint textureID;
public:
    Figura(const std::string& nombre, int grosorBords, int color)
        : nombre(nombre), grosorBords(grosorBords), color(color), textureID(0) {}
    
    virtual void dibujar() const = 0;
    virtual ~Figura() {
        if (textureID != 0) {
            glDeleteTextures(1, &textureID); 
        }
    }
    bool cargarTextura(const std::string& rutaTextura);
    void aplicarTextura() const;
    GLuint getTextureID() const { return textureID; } 


};
