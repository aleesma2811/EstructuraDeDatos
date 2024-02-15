#pragma once
#include <iostream>
#define TAM 8

using namespace std;

class Tarea
{
private:
	int arrayI[TAM]{ 93, 34, 55, 12, 20, 7, 16 };
	string arrayS[TAM]{ "Juan", "Alex", "Pedro", "Lina", "Gerardo", "Perla"};

public:
	Tarea();
	~Tarea();

	void mostrarI();
	void mostrarS();
	int ordenarA();
	int ordernarD();
	void ordenarString();
};

