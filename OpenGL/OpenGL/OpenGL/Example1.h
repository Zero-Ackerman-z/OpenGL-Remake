#pragma once
#include "Example.h"
#include "Punto3D.h"
#include "Poligono.h"
#include "Cubo.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Esfera.h"
#include "Piramide.h"
#include "Triangulo.h"

class Example1: public Example
{
private:
	Cubo cubo;            
	Cuadrado cuadrado;     
	Circulo circulo;       
	Esfera esfera;         
	Piramide piramide;     
	Punto3D punto;
	Poligono poligono;
	Triangulo triangulo;   

	int figuraSeleccionada;  
public:
	Example1();
	
	virtual void init()override;
	virtual void Render()override;
	void DrawGrid();
	void DrawAxes3D();
	void DrawAxes();
	void DrawLineStrip();
	void DrawTriangle();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	
	void agregarFigura(Figura* figura);

	void DrawPoint();
	void DrawLine();
   
};

