#pragma once
#include <iostream>
#define TAM 7

using namespace std; 

struct Pantallas {
	string modelo;
};

class Pilas
{
public:
	Pilas();
	~Pilas();

	//Pop
	int extraer();
	//Push
	int insertar(Pantallas);
	void mostrar();

private:
	Pantallas pantallas[TAM];
	int min, max, tope;
};

