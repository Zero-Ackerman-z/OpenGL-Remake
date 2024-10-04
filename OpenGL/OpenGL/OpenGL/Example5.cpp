#include "Example5.h"
#include "Color.h"
#include "Cubo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Esfera.h"
#include <stdio.h>
#include <iostream>  // Para std::cerr
#include "BMPTextureLoader.h"
Example5::Example5() : shape(nullptr), texture(0) {
	pos = { 0, 0, 0 };
	rota = { 0,0,0 };
	Scal = { 1,1,1 };
	// Posición inicial
}
void Example5::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	//shape = new Cubo("Cubo", 1, 0xFFFFFF, 2);  
	//_TextureLoader = new BMPTextureLoader();
	//texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./textures/wallBMP.bmp");
	/*texture = textureManager.LoadTexture("./textures/wallBMP.bmp");
	if (texture == 0) {
		std::cerr << "Error al cargar la textura." << std::endl;
	}*/
}
void Example5::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Example::DrawGrids();
	DrawShape();
	glFlush();
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{
    //traslacion
	case 'A':
		pos.x += 0.5;
		break;
	case 'D':
		pos.x -= 0.5;
		break;
	case 'W':
		pos.z += 0.5;
		break;
	case 'S':
		pos.z -= 0.5;
		break;
	case 'Q':
		pos.y += 0.5;
		break;
	case 'E':
		pos.y -= 0.5;
		break;
    // Rotar en los ejes

	case 'I':  
		rota.x += 5.0;
		break;
	case 'K':  
		rota.x -= 5.0;
		break;
	case 'J':  
		rota.y += 5.0;
		break;
	case 'L':  
		rota.y -= 5.0;
		break;
	case 'U':  
		rota.z += 5.0;
		break;
	case 'O':  
		rota.z -= 5.0;
		break;
		// Escalar en los ejes
	case 'X':  
		Scal.x += 0.1;
		break;
	case 'Z':  
		Scal.x -= 0.1;
		break;
	case 'Y':  
		Scal.y += 0.1;
		break;
	case 'H':  
		Scal.y -= 0.1;
		break;
	case 'N': 
		Scal.z += 0.1;
		break;
	case 'M':  
		Scal.z -= 0.1;
		break;
	case '1':  // Cubo 3D
		delete shape;  
		shape = new Cubo("Cubo", 1, 0xFFFFFF, 2);
		shape->cargarTextura("./textures/Terrain.bmp"); 
		break;
	case '2':  // Cuadrado 2D
		delete shape;
		shape = new Cuadrado("Cuadrado", 1, 0xFFFFFF, 4);  
		shape->cargarTextura("./textures/ink-8435869_640.bmp"); // Carga la textura

		break;
	case '3':  // Triángulo 2D
		delete shape;
		shape = new Triangulo("Triángulo", 1, 0xFF0000, 3, 4);  
		shape->cargarTextura("./textures/wallBMP.bmp"); // Carga la textura

		break;
	case '4':  // Esfera 3D
		delete shape;
		shape = new Esfera("Esfera", 1, 0x0000FF, 2);  
		shape->cargarTextura("./textures/wallBMP.bmp"); // Carga la textura

		break;
	default:
		break;
	}
}
void Example5::Idle()
{
}
void Example5::DrawShape()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	//glTranslatef(pos.x, pos.y, pos.z);
	glTranslatef(pos.x, pos.y, pos.z);
	glRotatef(rota.x, 1.0, 0.0, 0.0);  
	glRotatef(rota.y, 0.0, 1.0, 0.0);  
	glRotatef(rota.z, 0.0, 0.0, 1.0);  
	glScalef(Scal.x, Scal.y, Scal.z);

	if (shape) {

		shape->aplicarTextura(); 
		shape->dibujar(); 
	}
	glPopMatrix();

	//((Cubo*)shape)->dibujar();
	//glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers(); //Se hace el cambio de buffer
}