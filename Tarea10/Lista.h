#pragma once
#include <iostream>

using namespace std;

struct Nombre {
	string nombre;
	int posNombre;
	Nombre* sig;
};

class Lista
{
public:
	Lista();
	~Lista();

	void insertarInicio(Nombre);
	int insertarFinal(Nombre);
	void mostrar();
	int extraerIntermedio();
	int contarNodos();

private:
	Nombre* principio, * final, * nodo, * rev, * anterior;
};

