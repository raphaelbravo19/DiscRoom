#pragma once
#include "Sprite.h"
class Personaje :
	public Sprite
{
private:
	int retraso = 0;
public:
	Personaje();
	Personaje(int pPosX, int pPosY, int pAncho, int pAlto, int pDeltaX, int pDeltaY, char* pNombreArchivo, int pIndiceSpriteX, int pIndiceSpriteY, int pDeltaSpriteX);
	void CambiarSprite();
	void Mostrar(System::Drawing::Graphics ^gr);
	void Mover();
	~Personaje();
};

