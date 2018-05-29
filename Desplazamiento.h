#pragma once
#include "Tablero.h"
#include "Esfera.h"
#include "Cubo.h"
#include "Interaccion.h"
#include "Mundo.h"

class Desplazamiento {

public:
	Desplazamiento();
	virtual ~Desplazamiento();

	static void desplazamientoHorizontal(Esfera &e, Tablero t);
	//static void desplazDcha(Esfera &e, Tablero t);
};
