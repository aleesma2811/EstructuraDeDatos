#pragma once
#include <iostream>

using namespace std;

struct Cliente {
	string turno ;
	Cliente* sig;
	//ostream& operator<<(ostream& os, Cliente& palabra);
};

class Supermercado
{
public:
	Supermercado();
	~Supermercado();

	//Insertar
	void formar(string);
	//Extraer
	string pagar();
	void mostrar();
	int escogerCaja();


private:
	Cliente* principio, * final, * nodo;
};

