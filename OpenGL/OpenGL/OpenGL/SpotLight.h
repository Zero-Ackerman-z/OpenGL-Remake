#pragma once
#include "Light.h"
class SpotLight : public Light {
private:
    GLfloat spotDirection[3]; 
    GLfloat cutoffAngle;

public:
    SpotLight(GLenum id);

    void setSpotDirection(GLfloat x, GLfloat y, GLfloat z);
    void setCutoffAngle(GLfloat angle);

    void applyLight() override;
};
