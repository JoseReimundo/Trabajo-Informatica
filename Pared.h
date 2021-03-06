#pragma once
#include "Vector2D.h"

class Pared {
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;

public:
	Pared();				// Constructor 
	virtual ~ Pared();		// Destructor

	void setColor(unsigned char r, unsigned char v, unsigned char z);
	void setLimites(float x1, float y1, float x2, float y2);
	void dibuja();
	float distancia(Vector2D punto, Vector2D *direccion = 0);

	friend class Interaccion;	
};