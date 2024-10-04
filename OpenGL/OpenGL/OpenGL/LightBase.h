#pragma once
#include "IncludeGL.h"

class LightBase {
protected:
    GLenum lightID; 
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];

public:
    LightBase(GLenum id);

    void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);
    void setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);
    void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

    virtual void applyLight() = 0; 
};