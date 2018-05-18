#pragma once
#include"Vector2D.h"

class ObjetoMovil {		//Esta ser� una clase base

protected:
	Vector2D posicion;		// Atributo: posici�n
	Vector2D velocidad;		// Atributo: velocidad
	Vector2D aceleracion;	// Atributo: Aceleraci�n

public:
	ObjetoMovil();					// Constructor
	virtual ~ObjetoMovil();			// Destrcutor
	Vector2D getPos();				// Acceso parte protected
	void setPos(float x, float y);	// Establecer posicion por el paso de dos par�metros float
	void setPos(Vector2D pos);		// Establecer posicion por el paso de un vector
	void setVel(float vx, float vy);// EStablecer velocidad por el paso de dos par�metros float
	void setVel(Vector2D vel);		// Establecer velocidad por el paso de  un vector
	void mueve(float t);			// Gesti�n del movimiento
};