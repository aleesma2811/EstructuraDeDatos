#include "Caminos.h"

Caminos::Caminos()
{
	setlocale(LC_ALL, "");
	nodo = principio = final = NULL;
}

Caminos::~Caminos()
{
}

void Caminos::insertar(Motocicleta nueva)
{
	nodo = new Motocicleta;
	nodo->marca = nueva.marca;
	nodo->nCilindros = nueva.nCilindros;
	nodo->sig = NULL;

	if (principio == NULL) {
		principio = nodo;
	}
	if (final != NULL) {
		final->sig = nodo;
	}
	final = nodo;
}

Motocicleta Caminos::extraer()
{
	Motocicleta sale, vacia;

	vacia.marca = "";
	vacia.nCilindros = 0;

	if (principio == NULL) {
		return vacia;
	}

	nodo = principio;
	sale.marca = nodo->marca;
	sale.nCilindros = nodo->nCilindros;

	principio = nodo->sig;

	// Si ya se extrajeron todos los elementos
	if (principio == NULL) {
		final = NULL;
	}
	delete nodo;

	return sale;
}

void Caminos::mostrar()
{
	if (principio == NULL) {
		cout << "... cola vacía..." << endl;
		return;
	}
	nodo = principio;
	do {
		cout << "\t" << nodo->marca
			<< "\t" << nodo->nCilindros;
		if (nodo == principio) cout << "\t <- Principio";
		if (nodo == final) cout << "\t <- Final";
		cout << endl;

		nodo = nodo->sig;

	} while (nodo != NULL);
}
