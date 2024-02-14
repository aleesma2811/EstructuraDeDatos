#pragma once
#include <iostream>
//Definir constante
#define TAM 6 
using namespace std;

class Arreglo
{
public:
	Arreglo();
	~Arreglo();

	int insertar(int);
	void mostrar();

private:
	//Declarar arreglo
	int enteros[TAM] {3, 6, 9, 12};
	int ocupados = 4;
};

