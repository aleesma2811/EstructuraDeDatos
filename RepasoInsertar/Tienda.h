#pragma once
#include <iostream>
#include <string>
#define TAM 100

using namespace std;

struct Sucursal {
	int numSucursal;
	string nombreGerente;
	int ventas[2];
};

class Tienda
{
public:
	Tienda();
	~Tienda();
	void mostrar();
	void ordenar();
	void poblar();

private:
	Sucursal sucs[TAM];
	int ocupados;
};