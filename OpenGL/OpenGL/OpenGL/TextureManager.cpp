#include "TextureManager.h"
#include <iostream>

GLuint TextureManager::LoadTexture(const char* fileName) {
    BMPTextureLoader bmpLoader;
    return bmpLoader.LoadBMP(fileName);
}
