#include "CCircular.h"

CCircular::CCircular(int n)
{
	setlocale(LC_ALL, "");
	min = 0;
	max = n - 1;
	principio = final = -1;
	palabras = new string[n];

	for (int i = min; i <= max; i++) {
		palabras[i] = "-";
	}
}

CCircular::~CCircular()
{
}

int CCircular::insertar(string nuevo)
{
	/*Ver que haya espacio*/
	if ((final + 1) == principio) {
		return -1;
	}
	if (principio == min && final == max) {
		return -1;
	}
	/*Incrementar final*/
	final++;
	
	/*Incrementar principio la primera vez*/
	if (principio == -1) {
		principio++;
	}
	if (final > max) {
		final = min; //Final regresa a mínimo (al que sigue)
	}

	/*Insertar valor*/
	palabras[final] = nuevo;
	return 0;
}

int CCircular::extraer()
{
	string extraido;

	/*Revisar que no esté vacía*/
	if (principio < min && final < min) {
		return -1;
	}
	/*Extraer*/
	extraido = palabras[principio];
	palabras[principio] = "-";

	/*Incrementar principio*/
	if (final == principio) {
		return 0;
	}
	principio++;
	if (principio > max) {
		principio = min = -1; //Se extrajo el último elemento
	}
	cout << "Se extrajo el elemento '" << extraido << "'" << endl;
	return 0;
}

string CCircular::consultar()
{
	string extraido;

	/*Revisar que no esté vacía*/
	if (principio < min && final < min) {
		return " ";
	}
	/*Extraer*/
	extraido = palabras[principio];

	return extraido;
}

void CCircular::mostrar()
{
	cout << "---------COLAS---------" << endl;
	for (int i = min; i <= max; i++) {
		cout << "\t" << palabras[i];
		if (i == min) cout << "\t <- Mínimo";
		if (i == max) cout << "\t <- Máximo";
		if (i == principio) cout << "\t <- Principio";
		if (i == final) cout << "\t <- Final";
		cout << endl;
	}
}
