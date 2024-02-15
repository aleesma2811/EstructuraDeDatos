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
	void insertarInicio(int); //Número pequeño
	int insertarIntermedio(int);
	int insertarFinal(int); //Número grandeSS
	int extraerInicio();
	int extraerIntermedio(int);
	int extraerFinal();
	void mostrar();

private:
	Numeros* principio, * final, * nodo;
};

