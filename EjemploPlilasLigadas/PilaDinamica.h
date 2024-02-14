#pragma once
#include <iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo* anterior;
};

class PilaDinamica
{
public:
	PilaDinamica();
	~PilaDinamica();

	int consultar();
	int extraer();
	void insertar(int);
	void mostrar();

private:
	Nodo* tope, * nodo, * extraido;
};

