#include "Ejemplo.h"

using namespace std;

Ejemplo::Ejemplo()
{
}

Ejemplo::~Ejemplo()
{
}

void Ejemplo::mostrar()
{
	cout << "Mi primera linea." << endl;
	cout << "Hola mundo" << endl << endl;;
}

int Ejemplo::sumar(int a, int b)
{
	return a + b;
}
