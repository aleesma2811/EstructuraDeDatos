#pragma once
#include <iostream>

using namespace std;

struct Palabra
{
	string palabrita;
	Palabra* sig;
};

class Lista
{
public:
	Lista();
	~Lista();

	void insertarPrincipio(string); //Recibe elemento a insertar
	int insertarMedio(string, string); //Recibe elemento a insertar y el que se va a mover
	int insertarFinal(string); //Elemento a insertar al final
	string extraerPrincipio(); 
	string extraerMedio(string);//Recibe palabra a extraer 
	string extraerFinal();
	void mostrar();

private:
	Palabra* principio, * final, * nodo;
};

