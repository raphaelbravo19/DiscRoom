#include "Juego.h"



Juego::Juego()
{
	Nivel1 = new Nivel();
}
void Juego::ProcesarTick(System::Drawing::Graphics ^gr) {
	Nivel1->ProcesarTick(gr);
}
void Juego::ProcesarKeyDown(System::Windows::Forms::Keys e) {
	Nivel1->ProcesarKeyDown(e);
}
void Juego::ProcesarKeyUp(System::Windows::Forms::Keys e) {
	Nivel1->ProcesarKeyUp(e);
}

Juego::~Juego()
{
}
