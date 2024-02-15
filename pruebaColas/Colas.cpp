#include "Colas.h"

Colas::Colas()
{
	setlocale(LC_ALL, "");

	max = TAM - 1;
	min = 0;
	principio = final = -1; //Apunta fuera del arreglo

	for (int i = 0; i < TAM; i++) {
		palabras[i] = "-";
	}
}

Colas::~Colas()
{
}

int Colas::insertar(string nuevo)
{
	/*1) Revisar que haya capacidad*/
	if (final == max) {
		return -1;
	}
	final++;
	if (principio == -1) {
		principio++;
	}
	palabras[final] = nuevo;
	return 0;
}

int Colas::extraer()
{
	string extraido;
	/*Verificar que haya espacio*/
	if (final < min && principio < min) {
		return -1;
	}
	if (principio > final) {
		return -2;
	}

	/*Extraer valor*/
	extraido = palabras[principio];
	palabras[principio] = "-";

	/*Incrementar valor principio*/
	principio++;

	cout << "\tLa palabra '" << extraido << "' ha sido extraida" << endl;

	return 0;
}

void Colas::mostrar()
{
	cout << "---------COLA---------" << endl;
	for (int i = max; i >= min; i--) {
		cout << "\t" << palabras[i];
		if (i == min) cout << "\t <-- Mínimo";
		if (i == max) cout << "\t <-- Máximo";
		if (i == principio) cout << "\t <-- Principio";
		if (i == final) cout << "\t <-- Final";
		cout << endl;
	}
}
