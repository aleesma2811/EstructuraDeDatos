#pragma once
#include <iostream> 

using namespace std;

struct Frase {
	string dato;
	Frase* sig;
};

class ColaDinamica
{
public:
	ColaDinamica();
	~ColaDinamica();

	//Prototipos
	string consultar();
	string extraer();
	void insertar(string);
	void mostrar();

private:
	//inicio y final apuntan a frase, por lo que son apuntadores
	Frase* principio, * final, * nodo;
};

