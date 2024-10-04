#include "Light.h"
Light::Light(GLenum id) : LightBase(id) {
    setPosition(0.0f, 1.0f, 0.0f); 
    setDirection(0.0f, -1.0f, 0.0f);
}

void Light::setPosition(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    position[0] = x; position[1] = y; position[2] = z; position[3] = w;
}

void Light::setDirection(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    direction[0] = x; direction[1] = y; direction[2] = z; direction[3] = w;
}

void Light::applyLight() {
    glLightfv(lightID, GL_AMBIENT, ambient);
    glLightfv(lightID, GL_DIFFUSE, diffuse);
    glLightfv(lightID, GL_SPECULAR, specular);
    glLightfv(lightID, GL_POSITION, position);
}