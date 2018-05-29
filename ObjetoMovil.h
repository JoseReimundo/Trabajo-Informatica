#pragma once
#include"Vector2D.h"
#include "ColorRGB.h"
#include "Tablero.h"

class ObjetoMovil {		//Esta ser� una clase base
						// Atributos
protected:
	ColorRGB color;	// Atributos de color
	Vector2D posicion;					// Atributo: posici�n
	Vector2D velocidad;					// Atributo: velocidad
	Vector2D aceleracion;				// Atributo: Aceleraci�n
										// M�todos
public:
	ObjetoMovil();					// Constructor
	virtual ~ObjetoMovil();			// Destructor
	Vector2D getPos();				// Acceso parte protected
	void setPos(float x, float y);	// Establecer posicion por el paso de dos par�metros float
	void setPos(int i, int j);
	void setPos(Vector2D pos);		// Establecer posicion por el paso de un vector
	void setVel(float vx, float vy);// EStablecer velocidad por el paso de dos par�metros float
	void setVel(Vector2D vel);		// Establecer velocidad por el paso de  un vector
	void setColor(Byte cr, Byte cv, Byte ca);
	void mueve(float t);			// Gesti�n del movimiento

	bool comprobarPos(Tablero t);
	int columna(Tablero t);
	int fila(Tablero t);
};