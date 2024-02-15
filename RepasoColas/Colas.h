#pragma once
#include <iostream>;
#define TAM 8

using namespace std;

/*Cola dinámica*/

struct Frutas {
	string fruta;
	int cant;
	Frutas* sig;
};

class Colas
{
public:
	Colas();
	~Colas();

	void insertar(string, int);
	string extraer();
	void mostrar();

private:
	Frutas* frutas, * nodo, * final, * principio;
};

