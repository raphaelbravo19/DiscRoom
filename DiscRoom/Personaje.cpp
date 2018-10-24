#include "Personaje.h"



Personaje::Personaje()
{
}

Personaje::Personaje(int pPosX, int pPosY, int pAncho, int pAlto, int pDeltaX, int pDeltaY, char* pNombreArchivo, int pIndiceSpriteX, int pIndiceSpriteY, int pDeltaSpriteX) {
	PosX = pPosX;
	PosY = pPosY;
	Ancho = pAncho;
	Alto = pAlto;
	DeltaX = pDeltaX;
	DeltaY = pDeltaY;
	NombreArchivo = new char[100];
	strcpy(NombreArchivo, pNombreArchivo);
	IndiceSpriteX = pIndiceSpriteX;
	IndiceSpriteY = pIndiceSpriteY;
	DeltaSpriteX = pDeltaSpriteX;
}
void Personaje::CambiarSprite() {

	DeltaSpriteX = 0;
	if (DeltaX == 0 && DeltaY == 0)
		IndiceSpriteY = 0;
	else {
		if (DeltaX == 1 && DeltaY == 0)
			IndiceSpriteY = 1; DeltaSpriteX = 1;
		if (DeltaX == 0 && DeltaY == 1)
			IndiceSpriteY = 0; DeltaSpriteX = 1;
		if (DeltaX == -1 && DeltaY == 0)
			IndiceSpriteY = 3; DeltaSpriteX = 1;
		if (DeltaX == 0 && DeltaY == -1)
			IndiceSpriteY = 2; DeltaSpriteX = 1;

		if (DeltaX == 1 && DeltaY == 1)
			IndiceSpriteY = 4; DeltaSpriteX = 1;
		if (DeltaX == -1 && DeltaY == 1)
			IndiceSpriteY = 5; DeltaSpriteX = 1;
		if (DeltaX == 1 && DeltaY == -1)
			IndiceSpriteY = 6; DeltaSpriteX = 1;
		if (DeltaX == -1 && DeltaY == -1)
			IndiceSpriteY = 7; DeltaSpriteX = 1;
	}
	IndiceSpriteX = IndiceSpriteX == 0 ? IndiceSpriteX + DeltaSpriteX : 0;

}
void Personaje::Mostrar(System::Drawing::Graphics ^gr) {
	System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(Ancho*IndiceSpriteX, Alto*IndiceSpriteY, Ancho, Alto);
	System::Drawing::Rectangle destino = System::Drawing::Rectangle(PosX, PosY, Ancho*2, Alto*2);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));


	gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
void Personaje::Mover() {
	
	int tempX = PosX + DeltaX * 4;
	int tempY = PosY + DeltaY * 4;
	if (!(tempX < 64 || tempX + (Ancho * 2)>576)){
		PosX = tempX;
	}
	if (!(tempY < 64 || tempY + (Alto * 2)>576)) {
		PosY = tempY;
	}
	if (retraso == 8) {
		CambiarSprite();
		retraso = 0;
	}
	retraso++;
}
Personaje::~Personaje()
{
	
}
