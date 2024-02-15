#pragma once
#include <iostream>
#define MAX 8

using namespace std;

class Pilas
{
public:
	Pilas();
	~Pilas();

	void mostrar();
	int insertarOriginal(int);
	int extraerOriginal();

private:
	int min, max, tope;
	int* pilaEnteros;
};

