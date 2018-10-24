#include "Sprite.h"

Sprite::Sprite(){
}


Sprite::~Sprite()
{
}
void Sprite::CambiarSprite() {
}
void Sprite::Mostrar(System::Drawing::Graphics ^gr) {
}
void Sprite::Mover() {
}
int Sprite::GetPosX() {
	return PosX;
}
int Sprite::GetPosY() {
	return PosY;
}
int Sprite::GetAncho() {
	return Ancho;
}
int Sprite::GetAlto() {
	return Alto;
}
int Sprite::GetDeltaX() {
	return DeltaX;
}
int Sprite::GetDeltaY() {
	return DeltaY;
}
void Sprite::SetPosX(int value) {
	PosX = value;
}
void Sprite::SetPosY(int value) {
	PosY = value;
}
void Sprite::SetAncho(int value) {
	Ancho = value;
}
void Sprite::SetAlto(int value) {
	Alto = value;
}
void Sprite::SetDeltaX(int value) {
	DeltaX = value;
}
void Sprite::SetDeltaY(int value) {
	DeltaY = value;
}
void Sprite::SetNombreArchivo(char* value) {
	NombreArchivo = value;
}
int Sprite::GetIndiceSpriteX() {
	return IndiceSpriteX;
}
int Sprite::GetIndiceSpriteY() {
	return IndiceSpriteY;
}
int Sprite::GetDeltaSpriteX() {
	return DeltaSpriteX;
}

void Sprite::SetIndiceSpriteX(int value) {
	IndiceSpriteX = value;
}
void Sprite::SetIndiceSpriteY(int value) {
	IndiceSpriteY = value;
}

void Sprite::SetDeltaSpriteX(int value) {
	DeltaSpriteX = value;
}