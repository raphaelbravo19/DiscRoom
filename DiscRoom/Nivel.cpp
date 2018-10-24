#include "Nivel.h"
#include <math.h>

Nivel::Nivel()
{
	personaje = new Personaje(315,314,10,12,0,0,"Sprite1.png",0,0,0);
	marco = new Fondo(0, 0, 320, 320, 0, 0, "Marco.png", 0, 0, 0,true);
	mapa = new Fondo(64, 64, 256, 256, 0, 0, "Fondo.png", 0, 0, 0,false);
	arregloDiscos = new ArregloDisco();
	Disco* Disco1 = new Disco(286, 30, 34, 34, 1, 0, "LateralDisc.png", 0, 0, 1,2);
	Disco* Disco2 = new Disco(286, 542, 34, 34,-1, 0, "LateralDisc.png", 0, 0, 1,2);
	arregloDiscos->AgregaDisco(Disco1);
	arregloDiscos->AgregaDisco(Disco2);
	Discotemp = new Disco();
	//Disco1 = new Disco(rand() % 460 + 64, rand() % 408 + 64, 52, 52, rand() % 4 + 1, rand() % 4 + 1, "BigDisc.png", 0, 0, 1);
	//Disco2 = new Disco(rand() % 460 + 64, rand() % 460 + 64, 26, 26, rand() % 4 + 1, rand() % 4 + 1, "SmallDisc.png", 0, 0, 1);
	//Disco3 = new Disco(rand() % 460 + 64, rand() % 460 + 64, 26, 26, rand() % 4 + 1, rand() % 4 + 1, "SmallDisc.png", 0, 0, 1);
	//Disco4 = new Disco(rand() % 460 + 64, rand() % 460 + 64, 26, 26, rand() % 4 + 1, rand() % 4 + 1, "SmallDisc.png", 0, 0, 1);
}

Disco* Nivel::GenerarDisco() {
	int tempDeltaX, tempDeltaY;
	do { tempDeltaX = rand() % 7 - 3; } while (tempDeltaX == 0);
	do { tempDeltaY = rand() % 7 - 3; } while (tempDeltaY == 0);
	Disco* temp = new Disco(294, 294, 26, 26,tempDeltaX, tempDeltaY, "FollowDisc.png", 0, 0, 1,3);
	return temp;
	
}
void Nivel::ProcesarTick(System::Drawing::Graphics ^gr) {
	generate++;
	mapa->Mostrar(gr);
	if (gotcha) sangre->Mostrar(gr);
	personaje->Mostrar(gr);
	if (!gotcha)personaje->Mover();
	if (arregloDiscos->GetCantidad()<7 && !gotcha){
		if (generate == 20) { Discotemp = GenerarDisco(); }
		if (generate > 20 && generate < 40) { Discotemp->Mostrar(gr); }
		if (generate == 40) { arregloDiscos->AgregaDisco(Discotemp); generate = 0; }
	}
	arregloDiscos->MostrarTodos(gr);
	if (!gotcha)
		for (int i = 0; i < arregloDiscos->GetCantidad(); i++){
			arregloDiscos->DameDisco(i)->Distancia(personaje);
			if (SeIntersectan(arregloDiscos->DameDisco(i))) {
				sangre = new Fondo(personaje->GetPosX() - 50, personaje->GetPosY() - 50, 54, 54, 0, 0, "blood.png", 0, 0, 0, true);
				gotcha = true;
			}
		}
	if (!gotcha) arregloDiscos->MoverTodos();
	marco->Mostrar(gr);

	
}
bool Nivel::SeIntersectan(Disco* temp) {
	int tposx = temp->GetPosX() + temp->GetAncho();
	int tposy = temp->GetPosY() + temp->GetAlto();

	int pposx =	personaje->GetPosX() + personaje->GetAncho();
	int pposy = personaje->GetPosY() + personaje->GetAlto();

	double distance = sqrt(pow(tposx - pposx, 2) + pow(tposy - pposy, 2));

	double comp = temp->GetAncho() + personaje->GetAncho()-10;

	if (distance < comp) return true;
	else return false;
	
}
void Nivel::ProcesarKeyDown(System::Windows::Forms::Keys e) {
	switch (e){
	case System::Windows::Forms::Keys::Left:
		personaje->SetDeltaX(-1);
		break;
	case System::Windows::Forms::Keys::Up:
		personaje->SetDeltaY(-1);
		break;
	case System::Windows::Forms::Keys::Right:
		personaje->SetDeltaX(1);
		break;
	case System::Windows::Forms::Keys::Down:
		personaje->SetDeltaY(1);
		break;
	default:
		break;
	}
	
}
void Nivel::ProcesarKeyUp(System::Windows::Forms::Keys e) {
	switch (e) {
	case System::Windows::Forms::Keys::Left:
		personaje->SetDeltaX(0);
		break;
	case System::Windows::Forms::Keys::Up:
		personaje->SetDeltaY(0);
		break;
	case System::Windows::Forms::Keys::Right:
		personaje->SetDeltaX(0);
		break;
	case System::Windows::Forms::Keys::Down:
		personaje->SetDeltaY(0);
		break;
	default:
		break;
	}
}

Nivel::~Nivel()
{
}
