#pragma once
#include <iostream>

using namespace std;

struct Numeros {
	int num;
	Numeros* sig;
};

class Lista
{
public:
	Lista();
	~Lista();
	void insertarInicio(int); //N�mero peque�o
	int insertarIntermedio(int);
	int insertarFinal(int); //N�mero grandeSS
	int extraerInicio();
	int extraerIntermedio(int);
	int extraerFinal();
	void mostrar();

private:
	Numeros* principio, * final, * nodo;
};

