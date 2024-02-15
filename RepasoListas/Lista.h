#pragma once
#include <iostream>

using namespace std;

struct Empleado {
	string nombre;
	Empleado* sig;
};

class Lista
{
public:
	Lista();
	~Lista();

	void insertarInicio(string);
	int insertarInter(string, string);
	string insertarFinal(string);

	string extraerInicio();
	string extraerInter(string);
	string extraerFinal();

	void mostrar();

private:
	Empleado* nodo, * principio, * final;
};

