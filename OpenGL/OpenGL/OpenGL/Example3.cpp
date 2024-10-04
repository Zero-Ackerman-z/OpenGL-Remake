#include "Example3.h"
#include "IncludeGL.h"
#include "Camera.h"
Example3::Example3() :
	traslacion(0.0f, 0.0f, 0.0f),
	rotacion(0.0f, 0.0f, 0.0f),
	escala(1.0f, 1.0f, 1.0f),
	camera(Vector3(5.0f, 5.0f, 5.0f), Vector3(0.0f, 0.0f, 0.0f), 45.0f, 1.0f, 0.1f, 100.0f) // Inicialización de la cámara
{
}
void Example3::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	camera.UpdateCamera(); // Actualiza la cámara
	glClearDepth(1.0);
	glMatrixMode(GL_MODELVIEW);
}
void Example3::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera.UpdateCamera(); // Actualiza la cámara antes de dibujar
	DrawGrid();
	DrawCube();
	glFlush();
}
void Example3::DrawCube()
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
void Example3::DrawGrid()
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
void Example3::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key) {
	case 'w': // Mover hacia adelante
		camera.MoveForward(0.1f);
		break;
	case 's': // Mover hacia atrás
		camera.MoveForward(-0.1f);
		break;
	case 'a': // Mover a la izquierda
		camera.MoveRight(-0.1f);
		break;
	case 'd': // Mover a la derecha
		camera.MoveRight(0.1f);
		break;
	case 'q': // Rotar a la izquierda
		camera.Rotate(-5.0f);
		break;
	case 'e': // Rotar a la derecha
		camera.Rotate(5.0f);
		break;
	}
	glutPostRedisplay(); // Para actualizar la ventana

	//const float step = 0.1f;  // Tamaño de cada paso para traslación
	//const float angleStep = 5.0f;  // Ángulo de cada paso para rotación
	//const float scaleStep = 0.1f;  // Tamaño de cada paso para escalado
	//switch (key)
	//{

	//	// Traslación
	//case 'w':  // Mover hacia arriba
	//	traslacion.y += step;
	//	break;
	//case 's':  // Mover hacia abajo
	//	traslacion.y -= step;
	//	break;
	//case 'a':  // Mover hacia la izquierda
	//	traslacion.x -= step;
	//	break;
	//case 'd':  // Mover hacia la derecha
	//	traslacion.x += step;
	//	break;

	//	// Rotación
	//case 'q':  // Rotar sobre el eje Y hacia la izquierda
	//	rotacion.y -= angleStep;
	//	break;
	//case 'e':  // Rotar sobre el eje Y hacia la derecha
	//	rotacion.y += angleStep;
	//	break;
	//case 'r':  // Rotar sobre el eje X hacia arriba
	//	rotacion.x -= angleStep;
	//	break;
	//case 'f':  // Rotar sobre el eje X hacia abajo
	//	rotacion.x += angleStep;
	//	break;
	//case 'z':  // Rotar sobre el eje Z en sentido horario
	//	rotacion.z += angleStep;
	//	break;
	//case 'x':  // Rotar sobre el eje Z en sentido antihorario
	//	rotacion.z -= angleStep;
	//	break;

	//	// Escalado
	//case 'i':  // Escalar en el eje Y hacia arriba
	//	escala.y += scaleStep;
	//	break;
	//case 'b':  // Escalar en el eje Y hacia abajo
	//	escala.y -= scaleStep;
	//	break;
	//case 'm':  // Escalar en el eje X hacia la izquierda
	//	escala.x -= scaleStep;
	//	break;
	//case 'n':  // Escalar en el eje X hacia la derecha
	//	escala.x += scaleStep;
	//	break;
	//case 'o':  // Escalar en el eje Z hacia adelante
	//	escala.z += scaleStep;
	//	break;
	//case 'v':  // Escalar en el eje Z hacia atrás
	//	escala.z -= scaleStep;
	//	break;	
	/*default:
		break;
	}*/

}
void Example3::Idle()
{
	float deltaTime = 0.016f; // Suponiendo que es un valor fijo para 60fps, esto debería ser dinámico en una implementación real

}