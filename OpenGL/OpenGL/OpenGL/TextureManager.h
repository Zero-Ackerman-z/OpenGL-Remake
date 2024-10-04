#pragma once
#include <map>
#include <string>
#include "BMPTextureLoader.h"

class TextureManager {
public:
    GLuint LoadTexture(const char* fileName);
};

