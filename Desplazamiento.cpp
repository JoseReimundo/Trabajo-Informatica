#include "Desplazamiento.h"

Desplazamiento::Desplazamiento()
{
}

Desplazamiento::~Desplazamiento()
{
}

void Desplazamiento::desplazamientoHorizontal(Esfera &e, Tablero t)
{
	if (Interaccion::movimiento_horizontal(e, t))
		e.setVel(-5.0f, 0.0f);
}
