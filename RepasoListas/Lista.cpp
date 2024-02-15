#include "Lista.h"

Lista::Lista()
{
}

Lista::~Lista()
{
}

void Lista::insertarInicio(string nuevo)
{
	nodo = new Empleado; // 1 Crear nodo
	// Insertar info
	nodo->nombre = nuevo;

	nodo->sig = principio;

	principio = nodo;

	if (final == NULL) {
		final = nodo;
	}
}

int Lista::insertarInter(string aBuscar, string nuevo)
{
	Empleado* nodoAnterior;
	bool encontrado = false;

	if (principio == NULL) {
		insertarInicio(nuevo); //Lista vacía
		return -1;
	}

	nodoAnterior = principio;

	while (nodoAnterior != final) {
		if (nodoAnterior->nombre == aBuscar) {
			encontrado = true;

			nodo = new Empleado;

			nodo->nombre = nuevo;

			nodo->sig = nodoAnterior->sig;
			nodoAnterior->sig = nodo;

			if (nodo == final) {
				final = nodo; // Si anterior es el último nodo
			}
			return 0;
		}
		nodoAnterior = nodoAnterior->sig;
	}
	if (encontrado == false) {
		insertarFinal(nuevo);
		return -2; //No se encontró
	}
	return 0;
}

string Lista::insertarFinal(string nuevo)
{

	if (principio == NULL) {
		insertarInicio(nuevo);
		return ""; // Lista vacía, se inserta al inicio
	}
	nodo = new Empleado;
	nodo->nombre = nuevo;

	nodo->sig = NULL;

	final->sig = nodo;
	final = nodo;

	return "prueba";
}

string Lista::extraerInicio()
{
	string extraido;
	if (principio == NULL) {
		return ""; // Lista vacía, no se extrajo nada
	}
	nodo = principio;

	extraido = nodo->nombre;

	principio = nodo->sig;

	if (final == principio) {
		final == NULL;
	}
	delete nodo;

	return extraido;
}

string Lista::extraerInter(string)
{
	
	return string();
}

string Lista::extraerFinal()
{
	Empleado* nodoAnterior;
	string extraido;
	if (principio == NULL) {
		return ""; // Lista vacía, no se extrajo nada
	}
	if (principio == final) {
		extraido = extraerInicio();
		return extraido;
	}
	nodoAnterior = NULL;
	nodo = principio;

	while (nodo != final) {
		nodoAnterior = nodo;
		nodo = nodo->sig;

	}

	extraido = nodo->nombre;

	nodoAnterior->sig = NULL;

	final = nodoAnterior;

	delete nodo;

	return extraido;
}

void Lista::mostrar()
{
	if (principio == NULL) {
		cout << "... Lista vacía ..." << endl;
		return;
	}
	nodo = principio;

	while (nodo) {
		cout << "\t" << nodo->nombre;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;

		nodo = nodo->sig;
	}
}
