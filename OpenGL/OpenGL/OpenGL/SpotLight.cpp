#include "SpotLight.h"
SpotLight::SpotLight(GLenum id) : Light(id) {
    setSpotDirection(0.0f, -1.0f, 0.0f);
}

void SpotLight::setSpotDirection(GLfloat x, GLfloat y, GLfloat z) {
    spotDirection[0] = x; spotDirection[1] = y; spotDirection[2] = z;
}

void SpotLight::setCutoffAngle(GLfloat angle) {
    cutoffAngle = angle;
}

void SpotLight::applyLight() {
    Light::applyLight(); 
    glLightfv(lightID, GL_SPOT_DIRECTION, spotDirection);
    glLightf(lightID, GL_SPOT_CUTOFF, cutoffAngle);
}