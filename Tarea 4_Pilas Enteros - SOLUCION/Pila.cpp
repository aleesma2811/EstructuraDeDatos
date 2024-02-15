#include "Pila.h"

Pila::Pila(int capacidad)
{
	setlocale(LC_ALL, "");

	arrPila = new int[capacidad];
	min = 0;
	max = capacidad - 1;
	tope = -1;

	for (int i = 0; i < capacidad; i++)
		arrPila[i] = 0;
}

Pila::~Pila()
{
}

void Pila::Insertar(int nuevo)
{
	//Paso 1
	if (tope == max)
	{
		cout << "\n\t**Pila Llena. NO se puede insertar\n" << endl;
		return;
	}
	//Paso 2
	tope++;
	//Paso 3
	arrPila[tope] = nuevo;
	cout << "\tOK. Se insertó " << nuevo << endl;
}

int Pila::Extraer()
{
	int extraido;

	if (tope < min)
	{
		cout << "\n\t**Pila Vacía. NO se extrae nada\n" << endl;
		return -1;
	}
	extraido = arrPila[tope];
	arrPila[tope] = 0;
	tope--;
	return extraido;
}

void Pila::Mostrar()
{
	cout << "PILA: " << endl;
	for (int i = max; i >= min; i--)
	{
		cout << "\t" << arrPila[i] << "\t";
		if (i == min)
			cout << "<== Min ";
		if (i == tope)
			cout << "<== Tope ";
		if (i == max)
			cout << "<== Max ";
		cout << endl;
	}
	cout << endl;
}
