#pragma once
#include "LightBase.h"
class Light : public LightBase {
protected:
    GLfloat position[4]; 
    GLfloat direction[4]; 

public:
    Light(GLenum id);

    void setPosition(GLfloat x, GLfloat y, GLfloat z, GLfloat w = 1.0f);
    void setDirection(GLfloat x, GLfloat y, GLfloat z, GLfloat w = 0.0f); 

    virtual void applyLight() override; 
};