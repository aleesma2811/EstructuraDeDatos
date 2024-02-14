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
		insertarPrincipio(nuevoM); //Lista vacía, se insertó al inicio
		return -1;
	}

	/* Localizar la posición */
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
				final = nodo; //Solo si anterior es el último nodo
			}
			return 0;
		}
		nodoAnterior = nodoAnterior->sig;
	}
	if (encontrado == false) {
		insertarFinal(nuevoM); //No se encontró
		return -2;
	}

	return 0;
}

int Lista::insertarFinal(string nuevoF)
{
	if (!principio) { //principio == NULL
		insertarPrincipio(nuevoF); //Lista vacía, se inserta al inicio
		return -1;
	}
	/* Crear nodo */
	nodo = new Palabra;

	/* Insertar información */
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
	if (principio == NULL) { // Si la lista está vacía
		return "";
	}

	/* Localizar principio */
	nodo = principio;

	/* tomar información del nodo */
	extraido = nodo->palabrita;

	/* Apuntar al sig nodo */
	principio = nodo->sig;

	if (final == principio) {
		final = NULL;
	}

	/* Borrar información */
	delete nodo;

	return extraido;
}

string Lista::extraerMedio(string aExtraer)
{
	string extraida;
	Palabra* nodoAnterior;

	bool encontrada = false;

	if (principio == NULL) { // Lista vacía
		return "";
	}
	/* Localizar nodo a extraer */
	nodoAnterior = NULL;
	nodo = principio;

	while (nodo != NULL) {
		if (nodo->palabrita == aExtraer) {
			encontrada = true; // Encontró el valor
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
	if (principio == NULL) { //Lista vacía
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
		cout << "... cola vacía... " << endl;
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
