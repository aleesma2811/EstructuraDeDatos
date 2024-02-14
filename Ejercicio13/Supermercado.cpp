#include "Supermercado.h"

Supermercado::Supermercado()
{
	setlocale(LC_ALL, "");
	principio = final = nodo = NULL;
}

Supermercado::~Supermercado()
{
}

void Supermercado::formar(string nuevo)
{
	nodo = new Cliente;
	nodo->turno = nuevo;

	nodo->sig = NULL;
	if (principio == NULL) {
		principio = nodo;
	}
	if (final != NULL) {
		final->sig = nodo;
	}
	final = nodo;
}

string Supermercado::pagar()
{
	string saleTurno;

	if (principio == NULL) {
		return "";
	}
	nodo = principio;
	saleTurno = nodo->turno;

	principio = nodo->sig;

	if (principio == NULL) {
		final = NULL;
	}

	cout << saleTurno;

	return saleTurno;
}

void Supermercado::mostrar()
{
	if (principio == NULL) {
		cout << "... cola vacía ..." << endl;
		return;
	}

	nodo = principio;

	do {
		cout << "\t" << nodo->turno;
		if (nodo == principio) cout << "\t <- Principio";
		if (nodo == final) cout << "\t <- Final";
		cout << endl;
		nodo = nodo->sig;
	} while (nodo != NULL);
}

//----------------------------------------------------

int Supermercado::escogerCaja()
{
	int opcC;
	cout << "1. C20" << endl;
	cout << "2. C25" << endl;
	cin >> opcC;
	
	return opcC;
}
