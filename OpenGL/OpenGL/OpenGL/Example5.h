#pragma once
#include "Example.h"
#include "Figura.h"
#include "Vector3.h"
#include "TextureLoader.h"
#include "TextureManager.h"
#include "BMPTextureLoader.h"

class Example5 :
    public Example
{
private:
    Vector3 rota;
    Vector3 Scal;
    Figura* shape;
    Vector3 pos;
    //TextureLoader* _TextureLoader;
    TextureManager textureManager;

    GLuint texture;
public:
    Example5();
    virtual void init()override;
    virtual void Render()override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
    virtual void Idle()override;
    void DrawShape();
};