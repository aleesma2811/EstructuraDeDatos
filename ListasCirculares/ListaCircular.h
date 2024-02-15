#pragma once
#include <iostream>

using namespace std;

struct Entero
{
	int dato;
	Entero* sig;
};

class ListaCircular
{
public:
	ListaCircular();
	~ListaCircular();

	int insertarInicio(int);
	int insertarFinal(int);
	bool busqueda(int);

	void mostrarInicio();
	void mostrarRevisado();

private:
	Entero* principio, * final, * revisado, * nodo;
};

