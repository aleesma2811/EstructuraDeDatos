#include "Central.h"

Central::Central()
{
	setlocale(LC_ALL, "");
	principio = final = nodo = NULL;
}

Central::~Central()
{
}

void Central::llegada(string nuevaPlaca, string nuevoProducto)
{
	/*1) Crear nodo*/
	nodo = new Trailer;

	nodo->placa = nuevaPlaca;
	nodo->producto = nuevoProducto;

	nodo->sig = NULL;

	if (principio == NULL) {
		principio = nodo;
	}
	if (final != NULL) {
		final->sig = nodo;
	}
	final = nodo;
}

string Central::extraer()
{
	string salePlaca, saleProducto;

	if (principio == NULL) {
		return "";
	}

	nodo = principio;

	salePlaca = nodo->placa;
	saleProducto = nodo->producto;

	principio = nodo->sig;

	if (principio == NULL) {
		final = NULL;
	}

	delete nodo;

	return saleProducto;
}

void Central::mostrar()
{
	cout << "\n--------TRAILERS---------" << endl;
	if (principio == NULL) {
		cout << "\n\t...cola vacía..." << endl;
		return;
	}
	nodo = principio;
	do {
		cout << "\t" << nodo->placa
			<< "\t" << nodo->producto;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;

		nodo = nodo->sig;
	} while (nodo != NULL);

}
