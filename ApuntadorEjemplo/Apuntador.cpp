#include "Apuntador.h"

Apuntador::Apuntador()
{
}

Apuntador::~Apuntador()
{
}

/*Arreglo de enteros manejando como apuntador a entero*/
void Apuntador::ejemplo1()
{
}

void Apuntador::ejemplo2()
{
	//Arreglo de memoria estática
	int lista[6] = { 10, 20, 30 };

	//Dirección del primer elemento de la lista
	cout << "Lista: " << lista << endl;
	cout << "Lista + 0: " << (lista + 0) << endl;
	cout << "Lista + 1: " << (lista + 1) << endl;
	cout << "Lista + 4: " << (lista + 4) << endl;
	cout << "Lista + [0]: " << *lista << endl;
	cout << "Lista + [5]: " << *(lista + 5) << endl;
}


void Apuntador::ejemplo3()
{
	int* p;
	//Asigna 5 localidades de memoraia para int, apuntadas por p
	p = new int[5]; 

	//
	*(p + 0) = 1; 
	*(p + 1) = 3;
	*(p + 2) = 5;
	*(p + 3) = 7;
	*(p + 4) = 9;

	cout << p << endl;
	for (int i = 0; i < 5; i++) {
		cout << *(p + i) << "\t";
	}
	for (int i = 0; i < 5; i++) {
		cout <<p[i] << "\t";
	}
	//Liberar las 5 localidades de memoria apuntadas por p
	delete p;

	cout << p << endl;

	for (int i = 0; i < 5; i++) {
		cout << *(p + i) << "\t";
		cout << endl;
	}
}
