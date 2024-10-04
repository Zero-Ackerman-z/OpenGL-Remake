#include "Example1.h"
#include "IncludeGL.h"

Example1::Example1() : cubo("Cubo", 1, 1, 4),    
cuadrado("Cuadrado", 1, 1, 4), 
circulo("Círculo", 1, 1, 3),   
esfera("Esfera", 1, 1, 3),    
triangulo("Triángulo", 1, 1, 3, 4),  
piramide("Pirámide", 1, 1, Triangulo("Base Triángulo", 1, 1, 3, 4), 3),  
figuraSeleccionada(0) 
//punto(1.0f, 1.0f, 0.0f)
{  
}
void Example1::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

	// Añadir vértices al polígono
	poligono.agregarVertice(Punto3D(0.0f, 0.0f, 0.0f));
	poligono.agregarVertice(Punto3D(1.0f, 0.0f, 0.0f));
	poligono.agregarVertice(Punto3D(0.5f, 1.0f, 0.0f));

}
void Example1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		DrawPoint();
		DrawTriangle();
		DrawLine();
		DrawLineStrip();
		DrawAxes();
		DrawAxes3D();
		DrawGrid();
		//punto.dibujar();
		//poligono.dibujar();
		switch (figuraSeleccionada)
		{
		case 1:
			//cubo.dibujar();  // Dibujar el cubo
			break;
		case 2:
			cuadrado.dibujar();  // Dibujar el cuadrado
			break;
		case 3:
			circulo.dibujar();  // Dibujar el círculo
			break;
		case 4:
			esfera.dibujar();  // Dibujar la esfera
			break;
		case 5:
			//piramide.dibujar();  // Dibujar la pirámide
			break;
		case 6:
			triangulo.dibujar();  // Dibujar la pirámide
			break;
		default:
			// No se dibuja ninguna figura
			break;
		}
	glFlush();

}
void Example1::DrawGrid()
{
	
	glColor3f(0.5f, 0.5f, 0.5f); // Color (gris) 
	glLineWidth(1.0f); // Ancho 

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

	glEnd(); // Termina 
	
}
void Example1::DrawAxes3D()
{
	/*
	glLineWidth(1.0f);
	// Eje X
	glColor3f(1.0f, 0.0f, 0.0f); // Color (red)
	glBegin(GL_LINES);
	    glVertex3f(-2.0f, 0.0f, 0.0f); // Inicio del eje X
	    glVertex3f(2.0f, 0.0f, 0.0f);  // Fin del eje X
	glEnd();

	// Eje Y
	glColor3f(0.0f, 1.0f, 0.0f); // Color (verde)
	glBegin(GL_LINES);
	    glVertex3f(0.0f, -2.0f, 0.0f); // Inicio del eje Y
	    glVertex3f(0.0f, 2.0f, 0.0f);  // Fin del eje Y
	glEnd();
	// Eje Z
	glColor3f(0.0f, 0.0f, 1.0f); // Color (azul)
	glBegin(GL_LINES);
	    glVertex3f(0.0f, 0.0f, -2.0f); // Inicio del eje Z
	    glVertex3f(0.0f, 0.0f, 2.0f);  // Fin del eje Z
	glEnd();
	*/
}
void Example1::DrawAxes()
{
	/*
	glLineWidth(1.0f); // Ancho 
    // Dibuja el eje X
	glColor3f(1.0f, 0.0f, 0.0f); // Color (red)
	glBegin(GL_LINES);
	    glVertex3f(-2.0f, 0.0f, 0.0f); // Inicio del eje X
	    glVertex3f(2.0f, 0.0f, 0.0f);  // Fin del eje X
	glEnd();

	// Dibuja el eje Y
	glColor3f(0.0f, 1.0f, 0.0f); // Color (verde)
	glBegin(GL_LINES);
	    glVertex3f(0.0f, -2.0f, 0.0f); // Inicio del eje Y
	    glVertex3f(0.0f, 2.0f, 0.0f);  // Fin del eje Y
	glEnd();
	*/
}
void Example1::DrawLineStrip()
{
	/*
	glColor3f(1.0f, 0.5f, 0.0f);
	glLineWidth(1.5f);

	glBegin(GL_LINE_STRIP);
	    glVertex3f(-1.0f, -1.0f, 0.0f);
	    glVertex3f(0.0f, 1.0f, 0.0f);
	    glVertex3f(1.0f, -1.0f, 0.0f);
	    glVertex3f(2.0f, 0.5f, 0.0f);
	    glVertex3f(0.5f, 0.5f, 0.0f);
	glEnd();
	*/

}
void Example1::DrawTriangle()
{
	/*
	glColor3f(0.0f, 0.0f, 1.0f); // color  (azul)

	glBegin(GL_TRIANGLES); // Comienza a dibujar 
	    glVertex3f(-1.0f, -1.0f, 0.0f); // Primer vértice 
	    glVertex3f(1.0f, -1.0f, 0.0f); // Segundo vértice 
	    glVertex3f(0.0f, 1.0f, 0.0f); // Tercer vértice 
	glEnd(); // Termina 
	*/
}
void Example1::DrawPoint()
{
	/*
	glColor3f(1.0f, 0.0f, 0.0f); //color  (rojo)

	glPointSize(50.0f); // Tamaño 
	glBegin(GL_POINTS); // Comienza a dibujar 
	    glVertex3f(3.0f, 2.0f, 0.0f); // Coordenadas del punto
	glEnd(); // Termina 
	*/
}

void Example1::DrawLine()
{
	/*
	glColor3f(0.0f, 1.0f, 0.0f); // color (verde)

	glLineWidth(2.0f); // Ancho 

	glBegin(GL_LINES); // Comienza  dibujar 
	    glVertex3f(-3.0f, -2.0f, 0.0f); // Primer punto 
	    glVertex3f(3.0f, 2.0f, 0.0f);  // Segundo punto 
	glEnd(); // Termina 
	*/
}
void Example1::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{
	case '1':
		figuraSeleccionada = 1;  
		break;
	case '2':
		figuraSeleccionada = 2;  
		break;
	case '3':
		figuraSeleccionada = 3; 
		break;
	case '4':
		figuraSeleccionada = 4;  
		break;
	case '5':
		figuraSeleccionada = 5;  
		break;
	case '6':
		figuraSeleccionada = 6;  
		break;
	default:
		figuraSeleccionada = 0;  
		break;
	}
}
void Example1::Idle()
{

}