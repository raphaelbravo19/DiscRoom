#include "ArregloDisco.h"


ArregloDisco::ArregloDisco()
{
	Cantidad = 0;
	Incremento = 5;
	Capacidad = Incremento;
	Arreglo = new Disco*[Capacidad];
}

void ArregloDisco::IncrementaCapacidad()
{
	Disco** Temp;
	Temp = Arreglo;
	Capacidad = Capacidad + Incremento;
	Arreglo = new Disco*[Capacidad];
	for (int i = 0; i < Cantidad; i++) {
		Arreglo[i] = Temp[i];
	}
}

void ArregloDisco::AgregaDisco(Disco* pDisco)
{
	if (Cantidad == Capacidad)
		IncrementaCapacidad();
	Arreglo[Cantidad] = pDisco;
	Cantidad++;
}

void ArregloDisco::EliminarDisco(int pPos)
{
	if (pPos < Cantidad) {
		delete Arreglo[pPos];
		Cantidad--;
		for (int i = pPos; i < Cantidad; i++) {
			Arreglo[i] = Arreglo[i + 1];
		}
		for (int i = Cantidad; i < Capacidad; i++) {
			Arreglo[i] = 0;
		}

	}
}
void ArregloDisco::AgregarDiscoEnPosicion(Disco* pDisco, int pPos)
{
	if (pDisco != 0)
	{
		Arreglo[pPos] = pDisco;
	}
}
Disco* ArregloDisco::DameDisco(int pPos)
{
	return Arreglo[pPos];
}

int ArregloDisco::GetCantidad()
{
	return Cantidad;
}
void ArregloDisco::MostrarTodos(System::Drawing::Graphics ^gr) {
	for (int i = 0; i < Cantidad; i++) {
		Arreglo[i]->Mostrar(gr);
	}
}
void ArregloDisco::MoverTodos() {
	for (int i = 0; i < Cantidad; i++) {
		Arreglo[i]->Mover();
	}
}
ArregloDisco::~ArregloDisco()
{
	for (int i = 0; i < Cantidad; i++) {
		if (Arreglo[i] != 0)
			delete Arreglo[i];
	}
	delete[]Arreglo;
}
