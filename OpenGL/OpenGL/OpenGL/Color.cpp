#include "Color.h"
#include <iostream>

Color::Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}

Color::Color(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}

// Setters
void Color::setColor(float red, float green, float blue, float alpha) {
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

float Color::getRed() const { return r; }
float Color::getGreen() const { return g; }
float Color::getBlue() const { return b; }
float Color::getAlpha() const { return a; }

void Color::printColor() const {
    std::cout << "Color (R,G,B,A): (" << r << ", " << g << ", " << b << ", " << a << ")" << std::endl;
}
