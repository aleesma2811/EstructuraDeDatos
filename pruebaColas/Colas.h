#pragma once
#include <iostream>
#define TAM 7

using namespace std;

class Colas
{
public:
	Colas();
	~Colas();

	int insertar(string);
	int extraer();
	void mostrar();

private:
	int max, min, principio, final;
	string palabras[TAM];
};

