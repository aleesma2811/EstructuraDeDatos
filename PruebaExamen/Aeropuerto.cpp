#include "Aeropuerto.h"

Aeropuerto::Aeropuerto()
{
	setlocale(LC_ALL, "");
}

Aeropuerto::~Aeropuerto()
{
}

void Aeropuerto::insertarPrincipio(Vuelo vuelo)
{
	nodo = new Vuelo;

	nodo->destino = vuelo.destino;
	nodo->nacional = vuelo.nacional;

	nodo->sig = principio;

	principio = nodo;

	if (final == NULL) {
		final = nodo;
	}
}

int Aeropuerto::insertarFinal(Vuelo vuelo)
{
	if (principio == NULL) {
		insertarPrincipio(vuelo);
		return -1;
	}

	nodo = new Vuelo;

	nodo->destino = vuelo.destino;
	nodo->nacional = vuelo.nacional;

	nodo->sig = NULL;

	final->sig = nodo;
	final = nodo;

	if (vuelo.nacional == true) { // SI el vuelo es nacional
		return 1;
	}
	else {
		return 2; // SI el vuelo es internacional
	}

	return 0;
}

Vuelo Aeropuerto::extraerPrincipio()
{
	Vuelo extraido;

	if (principio == NULL) {
		cout << "Lista vacía" << endl;

	}
	return Vuelo();
}

void Aeropuerto::mostrar()
{
	if (principio == NULL) {
		cout << "Cola vacía";
	}
	nodo = principio;

	while (nodo) {
		cout << "\t" << nodo->destino << "\t" << nodo->nacional;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;

		nodo = nodo->sig;
	}
}



