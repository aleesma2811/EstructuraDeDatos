#pragma once
#include <iostream>
using namespace std;

struct Palabra
{
	string dato;
	Palabra* sig;
};

class ListaEnlazada
{
public:
	ListaEnlazada();
	void InsertarInicio(string);
	int InsertarInter(string, string);
	int InsertarFinal(string);
	string ExtraerInicio();
	string ExtraerFinal();
	string ExtraerIntermedio(string);
	void Mostrar();
private:
	Palabra* cabecera, * final, * nodo;
};

