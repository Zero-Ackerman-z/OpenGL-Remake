#include "PointLight.h"
PointLight::PointLight(GLenum id) : Light(id) {
    setPosition(0.0f, 1.0f, 0.0f);
}

void PointLight::applyLight() {
    Light::applyLight(); 
    position[3] = 1.0f;
    glLightfv(lightID, GL_POSITION, position);
}