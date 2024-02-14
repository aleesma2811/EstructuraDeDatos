#pragma once
#include <iostream>
using namespace std;

class Pila
{
public:
	Pila(int);
	~Pila();

	//Pop
	int extraer();
	//Push
	int insertar(int);
	int consultar();
	void mostrar();

private:
	//Arreglo pila
	int* pilaEnteros;
	//Tama�o del arreglo pila
	int n;
	//M�nimo, m�ximo y tope de la pila
	int min, max, tope;
};

