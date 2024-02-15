#pragma once
#include <iostream>

using namespace std;

/*
Tienda de motocicletas. Mostrar en una cola la marca y número de cilindros de cada 
una. Insertar y pagar (extraer). Si acepta el pago se extrae sin problema, si no 
se acepta, se agrega moto a otra cola de rechazados.
*/

struct Motocicleta {
	string marca;
	int nCilindros;
	Motocicleta* sig;
};

class Caminos
{
public:
	Caminos();
	~Caminos();

	void insertar(Motocicleta);
	Motocicleta extraer();
	void mostrar();

private:
	Motocicleta* moto, * principio, * final, * nodo;
};

