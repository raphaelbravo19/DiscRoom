#pragma once
#include "Personaje.h"
#include "Fondo.h"
#include "Disco.h"
#include "ArregloDisco.h"
#include <stdlib.h> 
class Nivel
{
private:
	Personaje * personaje;
	Fondo * marco;
	Fondo * mapa;
	ArregloDisco * arregloDiscos;
	Disco * Disco1;
	Disco * Disco2;
	Disco * Disco3;
	Disco * Disco4;
	Disco * Discotemp;
	int generate = 0;
	bool gotcha = false;
	Fondo * sangre;
public:
	Nivel();
	~Nivel();
	Disco* GenerarDisco();
	bool SeIntersectan(Disco* temp);
	void ProcesarTick(System::Drawing::Graphics ^gr);
	void ProcesarKeyDown(System::Windows::Forms::Keys e);
	void ProcesarKeyUp(System::Windows::Forms::Keys e);
};

