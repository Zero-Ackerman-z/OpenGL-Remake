#pragma once
#include "Light.h"
class PointLight : public Light {
public:
    PointLight(GLenum id);

    void applyLight() override;
};

