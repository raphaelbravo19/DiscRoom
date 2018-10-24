#pragma once
#include "Nivel.h"
class Juego
{
private:
	Nivel * Nivel1;
public:
	Juego();
	void ProcesarTick(System::Drawing::Graphics ^gr);
	void ProcesarKeyDown(System::Windows::Forms::Keys e);
	void ProcesarKeyUp(System::Windows::Forms::Keys e);
	~Juego();
};

