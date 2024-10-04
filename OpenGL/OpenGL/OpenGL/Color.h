#pragma once

class Color {
private:
    float r, g, b, a; 

public:
    Color();
    Color(float red, float green, float blue, float alpha = 1.0f); 

    void setColor(float red, float green, float blue, float alpha = 1.0f);

    // Getters
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    float getAlpha() const;

    void printColor() const; 
};

