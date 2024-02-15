#include "Colas.h"

Colas::Colas()
{
	setlocale(LC_ALL, "");
	nodo = principio = final = NULL;
}

Colas::~Colas()
{
}

void Colas::insertar(string fruta, int cant)
{
	nodo = new Frutas;

	nodo->fruta = fruta;
	nodo->cant = cant;

	nodo->sig = NULL;

	if (principio == NULL) {
		principio = nodo;
	}
	if (final != NULL) {
		final->sig = nodo;
	}
	final = nodo;
}

string Colas::extraer()
{
	string saleFruta;
	int saleCant;

	if (final == NULL) {
		return "";
	}
	nodo = principio;

	saleFruta = nodo->fruta;
	saleCant = nodo->cant;

	principio = nodo->sig;

	if (principio == NULL) {
		final = NULL;
	}
	delete nodo;
	return saleFruta;
}

void Colas::mostrar()
{
	cout << "------------------------" << endl;
	if (principio == NULL) {
		cout << "... cola vacía ..." << endl;
		return;
	}
	nodo = principio;
	do {
		cout << "\t" << nodo->fruta
			<< "\t" << nodo->cant;
		if (nodo == principio) cout << "\t <- Principio";
		if (nodo == final) cout << "\t <- Final";
		cout << endl;
		nodo = nodo->sig;
	} while (nodo != NULL);
}
