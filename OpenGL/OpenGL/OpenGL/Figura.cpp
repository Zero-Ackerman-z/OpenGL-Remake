#include "Figura.h"
#include "BMPTextureLoader.h" 

bool Figura::cargarTextura(const std::string& rutaTextura) {
    BMPTextureLoader loader; 
    textureID = loader.LoadBMP(rutaTextura.c_str());  // Cargar la textura

    if (textureID == (GLuint)-1) { 
        std::cerr << "Error al cargar la textura: " << rutaTextura << std::endl;
        return false;  // Carga fallida
    }
    return true;  // Carga exitosa
}

void Figura::aplicarTextura() const {
    if (textureID != 0) {
        glBindTexture(GL_TEXTURE_2D, textureID);  // Aplicar la textura
    }
}
