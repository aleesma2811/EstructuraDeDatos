#pragma once
#include <iostream>

using namespace std;

struct Vuelo {
	string destino;
	bool nacional;
	Vuelo* sig;
};

class Aeropuerto
{
public:
	Aeropuerto();
	~Aeropuerto();
	void insertarPrincipio(Vuelo); //Recibe elemento a insertar 
	int insertarFinal(Vuelo); //Elemento a insertar al final
	Vuelo extraerPrincipio();
	void mostrar();
private:
	Vuelo* principio, * final, * nodo;
};

