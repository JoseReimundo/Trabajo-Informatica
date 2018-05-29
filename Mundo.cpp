#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"
#include <cmath>

Mundo::~Mundo()			// Destructor
{

}

void Mundo::RotarOjo()
{
	float dist = sqrt(x_ojo*x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::setVista(float x, float y, float z)
{
	x_ojo = x;
	y_ojo = y;
	z_ojo = z;
}

void Mundo::Inicializa()
{
	// Opciones de puntos de vista
	//setVista(0, 7.5, 180);		perpendicular
	//setVista(0, -75.0, 180);		alejado
	//setVista(-10, -170, 100);
	setVista(-10, -90, 95);

	casilla1.setPos(-45, -45);		// Casilla de espera
	casilla1.setTipo(1);
	casilla2.setPos(5, -45);		// Casilla de validacion
	casilla2.setTipo(2);
	casilla3.setPos(5, 15);			// Casilla de eliminaci�n
	casilla3.setTipo(3);

	tablero.setTamanio(10, 10);		// Creamos un tablero 10x10

	/*bonus.setPos(5.0, -45.0f);		// Creamos un bonus
	cubo.setPos(15.0, -45.0);		// Creamos un cubo
	cubo.setColor(0, 0, 255);
	cubo.setLado(10.0f);*/

	esfera.setRadio(5.0f);
	esfera.setPos(-45, -45);
	esfera.setColor(0, 255, 0);

	esfera2.setRadio(5.0f);
	esfera2.setPos(3,4);
	esfera2.setColor(255, 0, 0);
}

void Mundo::Dibuja()
{
	// Determinamos la vista
	gluLookAt(x_ojo, y_ojo, z_ojo,
		0.0, -15.0, 0.0,
		0.0, 0.0f, 1.0f);


	caja.Dibuja();

	casilla1.dibuja();	// Esfera de 
	casilla2.dibuja();
	casilla3.dibuja();

	tablero.dibuja();	// Dibujamos el tablero

						//bonus.dibuja();

	//cubo.dibuja();

	esfera.Dibuja();
	esfera2.Dibuja();
}

void Mundo::Mueve()
{
	//bonus.mueve(0.5);
	//cubo.mueve(0.25);
	esfera.mueve(0.25);
	esfera2.mueve(0.25);

	Interaccion::choque(esfera2, esfera);
	Interaccion::choque(esfera, esfera2);
	

	Interaccion::choque(esfera, caja);
	Interaccion::choque(esfera2, caja);

	//Interaccion::movimiento_vertical(esfera, tablero);
	//Interaccion::movimiento_vertical(esfera2, tablero);

	

	//Interaccion::choque(cubo, caja);
	//Interaccion::choque(esfera, cubo);	
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
	{
		break;
	}
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		
		Desplazamiento::desplazamientoHorizontal(esfera, tablero);
		Desplazamiento::desplazamientoHorizontal(esfera2, tablero);
		break;
	case GLUT_KEY_RIGHT:
		
		//Interaccion::desplazamiento(cubo, tablero, 5.0f, 0.0f);
		if (Interaccion::movimiento_horizontal(esfera, tablero))
			esfera.setVel(5.0f, 0.0f); 
		if (Interaccion::movimiento_horizontal(esfera2, tablero))
			esfera2.setVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		//Interaccion::desplazamiento(cubo, tablero, 0.0f, 5.0f);
		if (Interaccion::movimiento_vertical(esfera, tablero))
			esfera.setVel(0.0f, 5.0f);
		if (Interaccion::movimiento_vertical(esfera2, tablero))
			esfera2.setVel(0.0f, 5.0f);
		break;
	case GLUT_KEY_DOWN:
		//Interaccion::desplazamiento(cubo, tablero, 0.0, -5.0f);
		if (Interaccion::movimiento_vertical(esfera, tablero))
			esfera.setVel(0.0f, -5.0f);
		if (Interaccion::movimiento_vertical(esfera2, tablero))
			esfera2.setVel(0.0f, -5.0f);
		break;
	}
}

