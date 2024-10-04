#pragma once
#include "Example.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionLight.h"
class Example4 :

    public Example
{
private:
    DirectionLight* dirLight;    ;
    PointLight* pointLight;
    SpotLight* spotLight;

public:
    Example4();
    virtual void init()override;
    virtual void Render()override;

    virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
    virtual void Idle()override;
    void ConfigurarMaterial();
    void ConfigurarLuzDireccional();
    void ConfigurarLuzPuntual();
    void ConfigurarLuzSpotLight();
    void DrawPlane();
};