#pragma once
#include <iostream>

using namespace std;

class Pila
{
public:
	Pila(int capacidad);
	~Pila();
	void Insertar(int nuevo);
	int Extraer();
	void Mostrar();
private:
	int* arrPila;
	int min, max, tope;
};
