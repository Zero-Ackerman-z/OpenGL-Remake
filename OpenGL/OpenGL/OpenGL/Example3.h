#pragma once
#include "Example.h"
#include "Vector3.h"
#include "Camera.h" 

class Example3 : public Example
{
private:
	Vector3 traslacion;
	Vector3 rotacion;
	Vector3 escala;
	    Camera camera; // Instancia de la cámara

public:
	Example3();

	virtual void init()override;
	virtual void Render()override;
	void DrawCube();
	void DrawGrid();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
};