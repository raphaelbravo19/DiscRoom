#pragma once
#include "Sprite.h"
#include "Personaje.h"
#include <math.h>
class Disco :
	public Sprite
{
private:
	int retraso = 0;
	int tipo;
public:
	Disco();
	Disco(int pPosX, int pPosY, int pAncho, int pAlto, int pDeltaX, int pDeltaY, char* pNombreArchivo, int pIndiceSpriteX, int pIndiceSpriteY, int pDeltaSpriteX,int pTipo);
	void CambiarSprite();
	void Distancia(Personaje* temp);
	void Mostrar(System::Drawing::Graphics ^gr);
	void Mover();
	void ReboteX();
	void ReboteY();
	~Disco();
};

