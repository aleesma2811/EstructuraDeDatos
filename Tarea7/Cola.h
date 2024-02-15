#pragma once
#include <iostream>	
#define TAM 12

using namespace std;

struct Comprador {
	string nombre;
	int nBoleto, posBoleto;
};

class Cola
{
public:
	Cola();
	~Cola();

	int registrar(Comprador);
	int extraer();
	void mostrar();

private:
	Comprador boletos[TAM];
	int min, max, principio, final;
};

