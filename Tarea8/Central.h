#pragma once
#include <iostream>

using namespace std;

struct Trailer
{
	string placa;
	string producto;
	Trailer* sig;
};

class Central
{
public:
	Central();
	~Central();

	void llegada(string, string);
	string extraer();
	void mostrar();

private:
	Trailer* trailers, * principio, * final, * nodo;
};

