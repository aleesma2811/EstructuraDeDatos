#pragma once
#include <iostream>
using namespace std;

struct Numero
{
	Numero* Izq;
	int num;
	Numero* Der;
};

class Binario
{
public:
	Binario();
	Numero* ConsultarRaiz();
	Numero* Buscar(Numero*, int);
	void CrearNodo(int);
	void Insertar(Numero*);
	void Mostrar(Numero*, int);
	void Recorrer_INorden(Numero*);
	void Recorrer_PREorden(Numero*);
	void Recorrer_POSorden(Numero*);
private:
	Numero* raiz, * nodo;
};

