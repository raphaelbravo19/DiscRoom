#include "Disco.h"

Disco::Disco(){
}

Disco::Disco(int pPosX, int pPosY, int pAncho, int pAlto, int pDeltaX, int pDeltaY, char* pNombreArchivo, int pIndiceSpriteX, int pIndiceSpriteY, int pDeltaSpriteX, int pTipo) {
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
	tipo = pTipo;
}
void Disco::CambiarSprite() {

	DeltaSpriteX = 1;
	IndiceSpriteX = IndiceSpriteX <= 1 ? IndiceSpriteX + DeltaSpriteX : 0;

}
void Disco::Mostrar(System::Drawing::Graphics ^gr) {
	System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(NombreArchivo));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(Ancho*IndiceSpriteX, Alto*IndiceSpriteY, Ancho, Alto);
	System::Drawing::Rectangle destino = System::Drawing::Rectangle(PosX, PosY, Ancho * 2, Alto * 2);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));


	gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
void Disco::Mover() {
	int tempX;
	int tempY; 
	if(tipo==1 || tipo==3){
		tempX = PosX + DeltaX * 2;
		tempY = PosY + DeltaY * 2;
		if (tempX < 64 || tempX+(Ancho*2)>576) {
			ReboteX();
			tempX = PosX + DeltaX * 2;
		}
		if (tempY < 64 || tempY+(Alto*2)>576) {
			ReboteY();
			tempY = PosY + DeltaY * 2;
		}
	}
	else if (tipo == 2) {
		tempX = PosX + DeltaX * 4;
		tempY = PosY + DeltaY * 4;
		if (tempX == 64 - Ancho && tempY == 64 - Alto) { DeltaX = 1; DeltaY = 0;}
		if (tempX == 64 - Ancho && tempY == 576 - Alto) { DeltaX = 0; DeltaY = -1; }
		if (tempX == 576 - Ancho && tempY == 64 - Alto) { DeltaX = 0; DeltaY = 1; }
		if (tempX == 576 - Ancho && tempY == 576 - Alto) { DeltaX = -1; DeltaY = 0; }
	}
	PosX = tempX;
	PosY = tempY;
	if (retraso == 2) {
		CambiarSprite();
		retraso = 0;
	}
	retraso++;
}
void Disco::Distancia(Personaje* temp) {
	
	if (tipo == 3) {
		int tposx = PosX + Ancho;
		int tposy = PosY + Alto;

		int pposx = temp->GetPosX() + temp->GetAncho();
		int pposy = temp->GetPosY() + temp->GetAlto();

		double distance = sqrt(pow(tposx - pposx, 2) + pow(tposy - pposy, 2));

		if (distance < 100) {
			if (tposx > pposx) DeltaX = -1;
			if (tposx < pposx) DeltaX = 1;
			if (tposy > pposy) DeltaY = -1;
			if (tposy < pposy) DeltaY = 1;
		}
	}
}
void Disco::ReboteX() {
	DeltaX *= -1;
}
void Disco::ReboteY() {
	DeltaY *= -1;
}
Disco::~Disco()
{
}
