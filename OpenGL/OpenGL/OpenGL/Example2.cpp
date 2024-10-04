#include "Example2.h"
#include "IncludeGL.h"
Example2::Example2() :
punto(1.0f, 1.0f, 1.0f),
punto2(2.0f, 2.0f, 0.0f),
traslacion(0.0f, 0.0f, 0.0f),
rotacion(0.0f, 0.0f, 0.0f), 
escala(1.0f, 1.0f, 1.0f),
figuraSeleccionada(0)
{
}
void Example2::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void Example2::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawGrid();
	DrawPoint3D();
	DrawLine();
	DrawAxes();
	DrawCube();
	switch (figuraSeleccionada)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	glFlush();

}

void Example2::DrawCube()
{
	
	glPushMatrix();

	// Aplicar traslación
	glTranslatef(traslacion.x, traslacion.y, traslacion.z);

	// Aplicar rotación
	glRotatef(rotacion.x, 1.0f, 0.0f, 0.0f);  // Rotar sobre el eje X
	glRotatef(rotacion.y, 0.0f, 1.0f, 0.0f);  // Rotar sobre el eje Y
	glRotatef(rotacion.z, 0.0f, 0.0f, 1.0f);  // Rotar sobre el eje Z

	// Aplicar escalado
	glScalef(escala.x, escala.y, escala.z);

	Vector3 vertices[8] = {
		Vector3(-0.5f, -0.5f, -0.5f),
		Vector3(0.5f, -0.5f, -0.5f),
		Vector3(0.5f, 0.5f, -0.5f),
		Vector3(-0.5f, 0.5f, -0.5f),
		Vector3(-0.5f, -0.5f, 0.5f),
		Vector3(0.5f, -0.5f, 0.5f),
		Vector3(0.5f, 0.5f, 0.5f),
		Vector3(-0.5f, 0.5f, 0.5f)
	};

	GLubyte edges[12][2] = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0},  // Frente
		{4, 5}, {5, 6}, {6, 7}, {7, 4},  // Atrás
		{0, 4}, {1, 5}, {2, 6}, {3, 7}   // Lados
	};

	glColor3f(1.0f, 1.0f, 1.0f);  // Color blanco
	glLineWidth(2.0f);  // Ancho de línea

	glBegin(GL_LINES);
	for (int i = 0; i < 12; ++i) {
		int start = edges[i][0];
		int end = edges[i][1];
		glVertex3f(vertices[start].x, vertices[start].y, vertices[start].z);
		glVertex3f(vertices[end].x, vertices[end].y, vertices[end].z);
	}
	glEnd();

	glPopMatrix();
	
}
void Example2::DrawAxes()
{
	/*

	glPushMatrix();  

	// Dibujar eje X
	glColor3f(1.0f, 0.0f, 0.0f);  // Color rojo
	glLineWidth(2.0f);  // Ancho de línea

	glBegin(GL_LINES);
	glVertex3f(-10.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glEnd();

	// Dibujar eje Y
	glColor3f(0.0f, 1.0f, 0.0f);  // Color verde
	glBegin(GL_LINES);
	glVertex3f(0.0f, -10.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glEnd();

	// Dibujar eje Z
	glColor3f(0.0f, 0.0f, 1.0f);  
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, 0.0f, 10.0f);
	glEnd();

	glPopMatrix(); 
	*/
}
void Example2::DrawLine()
{
	/*
	
	glColor3f(0.0f, 1.0f, 0.0f);  
	glLineWidth(3.0f);  

	glPushMatrix();  
	Vector3 scale(1.5f, 1.5f, 1.5f);  // Escalado
	Vector3 translation(1.0f, 1.0f, 0.0f);  // Traslación
	Vector3 rotationAxis(0.0f, 0.0f, 1.0f);  //  rotación

	scale.applyScaling(scale);  
	translation.applyTranslation(translation);  
	rotationAxis.applyRotation(45.0f, rotationAxis);  

	glBegin(GL_LINES);
	glVertex3f(punto.x, punto.y, punto.z);   
	glVertex3f(punto2.x, punto2.y, punto2.z);  
	glEnd();
	glPopMatrix();
	*/

}
void Example2::DrawGrid()
{
	glColor3f(0.5f, 0.5f, 0.5f); 
	glLineWidth(1.0f); 

	// Configuración del rango y el espaciado 
	const float gridSize = 10.0f; // Tamaño 
	const float step = 1.0f; // Espaciado 

	glBegin(GL_LINES); // dibuja las líneas 
	// líneas paralelas al eje Z
	for (float x = -gridSize; x <= gridSize; x += step)
	{
		glVertex3f(x, 0.0f, -gridSize); // Inicio 
		glVertex3f(x, 0.0f, gridSize);  // Fin 
	}

	// líneas paralelas al eje X
	for (float z = -gridSize; z <= gridSize; z += step)
	{
		glVertex3f(-gridSize, 0.0f, z); // Inicio 
		glVertex3f(gridSize, 0.0f, z);  // Fin 
	}

	glEnd();  

}

void Example2::DrawPoint3D()
{
	/*
	glColor3f(1.0f, 0.0f, 0.0f);  
	glPointSize(10.0f);  

	glPushMatrix();  

	Vector3 scale(1.5f, 1.5f, 1.5f);  // Escalado
	Vector3 translation(1.0f, 1.0f, 0.0f);  // Traslación
	Vector3 rotationAxis(0.0f, 0.0f, 1.0f);  // Eje de rotación

	scale.applyScaling(scale);  // Aplicar escalado
	translation.applyTranslation(translation);  // Aplicar traslación
	rotationAxis.applyRotation(45.0f, rotationAxis);  // Aplicar rotación de 45 grados en Z

	glBegin(GL_POINTS);
	glVertex3f(punto.x, punto.y, punto.z); 
	glEnd();

	glPopMatrix();  
	*/
}
void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{
	const float step = 0.1f;  // Tamaño de cada paso para traslación
	const float angleStep = 5.0f;  // Ángulo de cada paso para rotación
	const float scaleStep = 0.1f;  // Tamaño de cada paso para escalado

	switch (key)
	{
		// Traslación
	case 'w':  // Mover hacia arriba
		traslacion.y += step;
		break;
	case 's':  // Mover hacia abajo
		traslacion.y -= step;
		break;
	case 'a':  // Mover hacia la izquierda
		traslacion.x -= step;
		break;
	case 'd':  // Mover hacia la derecha
		traslacion.x += step;
		break;

		// Rotación
	case 'q':  // Rotar sobre el eje Y hacia la izquierda
		rotacion.y -= angleStep;
		break;
	case 'e':  // Rotar sobre el eje Y hacia la derecha
		rotacion.y += angleStep;
		break;
	case 'r':  // Rotar sobre el eje X hacia arriba
		rotacion.x -= angleStep;
		break;
	case 'f':  // Rotar sobre el eje X hacia abajo
		rotacion.x += angleStep;
		break;
	case 'z':  // Rotar sobre el eje Z en sentido horario
		rotacion.z += angleStep;
		break;
	case 'x':  // Rotar sobre el eje Z en sentido antihorario
		rotacion.z -= angleStep;
		break;

		// Escalado
	case 'i':  // Escalar en el eje Y hacia arriba
		escala.y += scaleStep;
		break;
	case 'k':  // Escalar en el eje Y hacia abajo
		escala.y -= scaleStep;
		break;
	case 'j':  // Escalar en el eje X hacia la izquierda
		escala.x -= scaleStep;
		break;
	case 'l':  // Escalar en el eje X hacia la derecha
		escala.x += scaleStep;
		break;
	case 'o':  // Escalar en el eje Z hacia adelante
		escala.z += scaleStep;
		break;
	case 'p':  // Escalar en el eje Z hacia atrás
		escala.z -= scaleStep;
		break;
	default:
		break;
	}
}
void Example2::Idle()
{

}