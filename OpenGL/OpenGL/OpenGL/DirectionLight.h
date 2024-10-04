#pragma once
#include "Light.h"
class DirectionLight : public Light {
public:
    DirectionLight(GLenum id);

    void applyLight() override;
};


