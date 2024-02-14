#include "Lista.h"

Lista::Lista()
{
	setlocale(LC_ALL, "");
}

Lista::~Lista()
{
}

void Lista::insertarPrincipio(string nuevoP)
{
	nodo = new Palabra;
	nodo->palabrita = nuevoP;

	nodo->sig = principio;

	principio = nodo;
	if (final == NULL) {
		final = nodo;
	}
}

int Lista::insertarMedio(string nuevoM, string anterior)
{
	Palabra* nodoAnterior;
	bool encontrado = false; //false si no lo encuentra, true si lo encuentra

	if (!principio) {
		insertarPrincipio(nuevoM); //Lista vac�a, se insert� al inicio
		return -1;
	}

	/* Localizar la posici�n */
	nodoAnterior = principio;
	//nodo = principio;

	while (nodoAnterior != final) {
		if (nodoAnterior->palabrita == anterior) { //Si lo encuentra
			encontrado = true;
			/* Crear nodo */
			nodo = new Palabra;

			/* Insertar info */
			nodo->palabrita = nuevoM;

			/* Enlace */
			nodo->sig = nodoAnterior->sig;

			/* Enlace de nodo anterior */
			nodoAnterior->sig = nodo;
			
			if (nodo == final) {
				final = nodo; //Solo si anterior es el �ltimo nodo
			}
			return 0;
		}
		nodoAnterior = nodoAnterior->sig;
	}
	if (encontrado == false) {
		insertarFinal(nuevoM); //No se encontr�
		return -2;
	}

	return 0;
}

int Lista::insertarFinal(string nuevoF)
{
	if (!principio) { //principio == NULL
		insertarPrincipio(nuevoF); //Lista vac�a, se inserta al inicio
		return -1;
	}
	/* Crear nodo */
	nodo = new Palabra;

	/* Insertar informaci�n */
	nodo->palabrita = nuevoF;

	/* Apuntar a NULL el campo de enlace */
	nodo->sig = NULL;

	/* Apuntar nuevo nodo al nuevo campo de enlace */
	final->sig = nodo;
	final = nodo;
	return 0;
}

string Lista::extraerPrincipio()
{
	string extraido;
	if (principio == NULL) { // Si la lista est� vac�a
		return "";
	}

	/* Localizar principio */
	nodo = principio;

	/* tomar informaci�n del nodo */
	extraido = nodo->palabrita;

	/* Apuntar al sig nodo */
	principio = nodo->sig;

	if (final == principio) {
		final = NULL;
	}

	/* Borrar informaci�n */
	delete nodo;

	return extraido;
}

string Lista::extraerMedio(string aExtraer)
{
	string extraida;
	Palabra* nodoAnterior;

	bool encontrada = false;

	if (principio == NULL) { // Lista vac�a
		return "";
	}
	/* Localizar nodo a extraer */
	nodoAnterior = NULL;
	nodo = principio;

	while (nodo != NULL) {
		if (nodo->palabrita == aExtraer) {
			encontrada = true; // Encontr� el valor
			break;
		}
		nodoAnterior = nodo;
		nodo = nodo->sig;
	}

	if (encontrada == false) {
		return "NO";
	}
	extraida = nodo->palabrita;

	if (nodo == principio) {
		principio = nodo->sig;
	}
	else {
		nodoAnterior->sig = nodo->sig;
	}

	if (nodo == final) {
		final = nodoAnterior;
	}

	delete nodo;

	return extraida;
}

string Lista::extraerFinal()
{
	Palabra* nodoAnterior;
	string extraido;
	if (principio == NULL) { //Lista vac�a
		return "";
	}

	if (principio == final) { //1 elemento en la lista
		extraido = extraerPrincipio();
		return extraido;
	}

	/* Localizar nodo final y su anterior */
	nodoAnterior = NULL;
	nodo = principio;
	while (nodo != final) {
		nodoAnterior = nodo;
		nodo = nodo->sig;
	}

	/* Tomar info del nodo a extraer */
	extraido = nodo->palabrita;

	nodoAnterior->sig = NULL;

	final = nodoAnterior;

	delete nodo;

	return extraido;
}

void Lista::mostrar()
{
	if (!principio) {
		cout << "... cola vac�a... " << endl;
		return;
	}
	nodo = principio;
	while (nodo) {
		cout << "\t" << nodo->palabrita;
		if (nodo == principio) cout << "\t <- Principio";
		if (nodo == final) cout << "\t <- Final";
		cout << endl;

		nodo = nodo->sig;
	}
}
