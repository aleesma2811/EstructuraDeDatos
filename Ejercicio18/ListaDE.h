#pragma once
#include <iostream>

using namespace std;

struct Palabra {
	string dato;
	Palabra* prev, * sig;
};

class ListaDE
{
public:
	ListaDE();
	~ListaDE();

	void insertarInicio(string);
	bool insertarInter(string, string); //Palabra de la lista, Nueva palabra
	string insertarFinal(string);

	string extraerInicio();
	string extraerInter(string);
	string extraerFinal();

	void mostrarInicioFin();
	void mostrarFinInicio();

private:
	Palabra* principio, * final, * nodo;
};

