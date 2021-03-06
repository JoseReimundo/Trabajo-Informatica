#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
#include "Tablero.h"
#include "Cubo.h"

class Interaccion {

public:
	Interaccion();
	virtual ~Interaccion();

	// �Qu� se hace cuando se choca con los l�mites del tablero?
	static void choque(Esfera &e, Caja c);
	static void choque(Cubo & b, Caja c);
	static void choque(Esfera &e1, Esfera &e2);

	// �Qu� pasa cuando hay choque entre objetos moviles ?
	static void choque(Esfera &e, Cubo c);

	// Limitar el movimiento a las posiciones de las casillas del tablero
	static bool movimiento_vertical(Esfera &e, Tablero t);
	static bool movimiento_horizontal(Esfera & e, Tablero t);
	static Vector2D ultimaCasilla(Esfera e, Tablero t);

	// Desplazamiento
	static void desplazamiento(Cubo & c, Tablero t, float vx, float vy);
	static void desplazamiento_dcha(Cubo &c, Tablero t);


	// Paso por referencia para poder modificar las variables
	static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	static void rebote(Hombre &h, Caja c);
	static bool rebote(Esfera &e1, Esfera &e2);

	static bool rebote(Bonus &b, Caja c);

	//Funciones para saber si hay colisi�n
	static bool colision(Esfera e, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
};