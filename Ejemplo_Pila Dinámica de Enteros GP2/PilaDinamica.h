#pragma once
#include <iostream>
using namespace std;

struct Nodo
{
	int dato;
	Nodo* anterior;
};

class PilaDinamica
{
public:
	PilaDinamica();
	int Consultar();
	int Extraer();
	void Insertar(int);
	void Mostrar();
private:
	Nodo* tope, *nodo, *extraido;
};

