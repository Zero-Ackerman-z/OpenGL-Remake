#include "LightBase.h"
LightBase::LightBase(GLenum id) : lightID(id) {
    setAmbient(0.2f, 0.2f, 0.2f);
    setDiffuse(0.8f, 0.8f, 0.8f);
    setSpecular(1.0f, 1.0f, 1.0f);
}

void LightBase::setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    ambient[0] = r; ambient[1] = g; ambient[2] = b; ambient[3] = a;
}

void LightBase::setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = a;
}

void LightBase::setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    specular[0] = r; specular[1] = g; specular[2] = b; specular[3] = a;
}