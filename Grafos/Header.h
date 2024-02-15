#pragma once
#include <iostream>

using namespace std;

class MatrizAdy
{
public:
	MatrizAdy(int);
	~MatrizAdy();

	int insertarNodo(char);
	int insertarArco(char, char, int);
	void mostrar();

private:
	int buscarNodo(int);
	char* nodos;
	int** arcos;
	int maxNodos, ocupados, posNodo;
};

