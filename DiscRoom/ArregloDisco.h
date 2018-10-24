#pragma once
#include "Disco.h"
class ArregloDisco
{
private:
	Disco * * Arreglo;
	int Cantidad;
	int Capacidad;
	int Incremento;
public:
	ArregloDisco();
	void IncrementaCapacidad();
	void AgregaDisco(Disco* pDisco);
	void EliminarDisco(int pPos);
	Disco* DameDisco(int pPos);
	void AgregarDiscoEnPosicion(Disco* pDisco, int pPos);
	int GetCantidad();
	void MostrarTodos(System::Drawing::Graphics ^gr);
	void MoverTodos();
	~ArregloDisco();
};

