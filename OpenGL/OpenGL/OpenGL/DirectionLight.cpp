#include "DirectionLight.h"
DirectionLight::DirectionLight(GLenum id) : Light(id) {
    
    setDirection(0.0f, -1.0f, 0.0f);
}

void DirectionLight::applyLight() {
    Light::applyLight(); 
    position[3] = 0.0f;
    glLightfv(lightID, GL_POSITION, position);
}