#pragma once
#include <iostream>
#include <string>

using namespace std;

class Arreglo
{
public:
	Arreglo();
	~Arreglo();

	void leerNombre();
	void mostrar();
	void ordenar();
	void insertar();

private:
	int** val;
	int renglon;
	int columna;
	string nombre;
};

