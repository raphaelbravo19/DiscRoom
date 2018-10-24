#pragma once
#include "Sprite.h"
class Fondo :
	public Sprite
{
private:
	bool transparente;
public:
	Fondo();
	Fondo(int pPosX, int pPosY, int pAncho, int pAlto, int pDeltaX, int pDeltaY, char* pNombreArchivo, int pIndiceSpriteX, int pIndiceSpriteY, int pDeltaSpriteX, bool ptransparente);
	void Mostrar(System::Drawing::Graphics ^gr);
	~Fondo();
};

