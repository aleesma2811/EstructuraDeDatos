#pragma once
#include <iostream>
#define TAM 6

using namespace std;

class CCircular
{
public:
	CCircular(int);
	~CCircular();

	int insertar(string);
	int extraer();
	string consultar();
	void mostrar();

private:
	string* palabras;
	int min, max, principio, final;
};

