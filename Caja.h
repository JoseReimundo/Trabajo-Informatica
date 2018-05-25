#pragma once
#include "Pared.h"

class Caja{
private:
	Pared frontal;		// Pared frontal
	Pared trasera;		// Pared trasera
	Pared pared_izq;	// Pared izquierda
	Pared pared_dcha;	// Pared derecha
public:
	Caja();				// Constructor
	virtual ~Caja();	// Destructor

	void Dibuja();		// Funci�n dibuja Caja

	friend class Interaccion;	// Clase amiga de Interacci�n
								// Da acceso a su parte privada
};