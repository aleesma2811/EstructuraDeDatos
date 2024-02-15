#include "Tarea.h"

Tarea::Tarea()
{
}

Tarea::~Tarea()
{
}

//Imprimir arreglo de enteros
void Tarea::mostrarI() 
{
	cout << "\nARREGLO: ";
	for (int i = 0; i < TAM; i++) {
		cout << "\t" << arrayI[i];
	}
}

//Imprimir arreglo de strings
void Tarea::mostrarS()
{
	cout << "\nARREGLO: ";
	for (int i = 0; i < TAM; i++) {
		cout << " \t" << arrayS[i];
	}
}

//Ordenar arreglo de enteros de manera ascendente
int Tarea::ordenarA()
{
	int temp;
	for (int i = 0; i < TAM; i++) {
		for (int j = i + 1; j < TAM; j++) {
			if (arrayI[i] > arrayI[j]) {
				temp = arrayI[i];
				arrayI[i] = arrayI[j];
				arrayI[j] = temp;
			}
		}
	}
	return 0;
}

//Ordenar arreglo de enteros de manera descendente
int Tarea::ordernarD()
{
	int temp;
	for (int i = 0; i < TAM; i++) {
		for (int j = i + 1; j < TAM; j++) {
			if (arrayI[i] < arrayI[j]) {
				temp = arrayI[i];
				arrayI[i] = arrayI[j];
				arrayI[j] = temp;
			}
		}
	}
	return 0;
}

//Ordenar arreglo de string alfabéticamente
void Tarea::ordenarString()
{
	string temp;
	for (int i = 0; i < TAM - 1; i++) {
		for (int j = 0; j < TAM - i - 1; j++) {
			if (arrayS[j] > arrayS[j + 1]) {
				temp = arrayS[j];
				arrayS[j] = arrayS[j + 1];
				arrayS[j + 1] = temp;
			}
		}
	}
}

