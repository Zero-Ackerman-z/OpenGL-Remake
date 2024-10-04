#pragma once
#include "Example.h"
#include "Vector3.h"

class Example2 : public Example
{
private:
	Vector3 punto;
	Vector3 punto2;
	Vector3 traslacion;
	Vector3 rotacion;
	Vector3 escala;
	int figuraSeleccionada;
public:
	Example2();

	virtual void init()override;
	virtual void Render()override;
	void DrawCube();
	void DrawAxes();
	void DrawLine();
	void DrawGrid();
	void DrawPoint3D();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
};
