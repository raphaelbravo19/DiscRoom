#pragma once
#include <string.h>
class Sprite
{
protected:
	int PosX;
	int PosY;

	int Ancho;
	int Alto;

	int DeltaX;
	int DeltaY;

	char* NombreArchivo;

	int IndiceSpriteX;
	int IndiceSpriteY;

	int DeltaSpriteX;
	
	
public:
	Sprite();
	~Sprite();
	virtual void CambiarSprite();
	virtual void Mostrar(System::Drawing::Graphics ^gr);
	virtual void Mover();
	int GetPosX();
	int GetPosY();
	int GetAncho();
	int GetAlto();
	int GetDeltaX();
	int GetDeltaY();

	void SetPosX(int value);
	void SetPosY(int value);
	void SetAncho(int value);
	void SetAlto(int value);
	void SetDeltaX(int value);
	void SetDeltaY(int value);
	void SetNombreArchivo(char* value);

	int GetIndiceSpriteX();
	int GetIndiceSpriteY(); 
	int GetDeltaSpriteX();

	void SetIndiceSpriteX(int value);
	void SetIndiceSpriteY(int value);
	void SetDeltaSpriteX(int value);

};
