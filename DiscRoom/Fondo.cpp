#include "Fondo.h"



Fondo::Fondo()
{
}
Fondo::Fondo(int pPosX, int pPosY, int pAncho, int pAlto, int pDeltaX, int pDeltaY, char* pNombreArchivo, int pIndiceSpriteX, int pIndiceSpriteY, int pDeltaSpriteX, bool ptransparente) {
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
	transparente = ptransparente;
}
void Fondo::Mostrar(System::Drawing::Graphics ^gr) {
	System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(Ancho*IndiceSpriteX, Alto*IndiceSpriteY, Ancho, Alto);
	System::Drawing::Rectangle destino = System::Drawing::Rectangle(PosX, PosY, Ancho * 2, Alto * 2);
	if (transparente)
	{
		bmp->MakeTransparent(bmp->GetPixel(33, 33));
	}


	gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
Fondo::~Fondo()
{
}
