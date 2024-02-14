#include "ListaDE.h"

ListaDE::ListaDE()
{
	principio = final = nodo = NULL;
	setlocale(LC_ALL, "");
}

ListaDE::~ListaDE()
{
}

void ListaDE::insertarInicio(string nuevo) /**/
{
	nodo = new Palabra;
	nodo->dato = nuevo;
	if (principio == NULL) {
		final = nodo; // Final se mueve
	}
	else {
		nodo->sig = principio; // 
	}
	nodo->prev = NULL;

	if (principio) { //Si lista está vacía
		principio->prev = nodo; 
	}
	else {
		final = nodo;
	}
	principio = nodo;
}

bool ListaDE::insertarInter(string aBuscar, string nuevo)
{
	Palabra* anterior;
	bool encontrada = false; // false = no encontrada

	if (principio == NULL) {
		return false; //Lista vacía
	}
	anterior = principio;

	do {
		if (anterior->dato == aBuscar) {
			encontrada = true; //Lo encontró
			break;
		}
		anterior = anterior->sig;
	} while (anterior != NULL);

	if (encontrada == false) {
		return false; // No encontró la palabra
	}
	if (anterior == final) { // Si lo encontró en el último nodo
		insertarFinal(nuevo); //Insertado al final
		return true; 
	}

	/* ----------------- */

	nodo = new Palabra;
	nodo->dato = nuevo;

	nodo->sig = anterior->sig; //Enlazar newNode con B
	nodo->prev = anterior; // Enlace newNode con A

	anterior->sig = nodo; // Enlazar A con newNode
	nodo->sig->prev = nodo;

	return true;
}

string ListaDE::insertarFinal(string nuevo)
{
	if (principio == NULL) {
		insertarInicio(nuevo);
	}
	nodo = new Palabra;
	nodo->dato = nuevo;

	nodo->sig = NULL;
	nodo->prev = final; // Nodo anterior apunta al final
	final->sig = nodo;
	final = nodo;


	return string();
}

string ListaDE::extraerInicio() /**/
{
	string extraido;
	if (!principio) {
		return ""; //Lista vacía, no se extrae
	}
	nodo = principio;
	extraido = nodo->dato;
	principio = principio->sig; //Principio apunta al nuevo "Principio"

	if (principio == NULL) {
		final = NULL; // Principio igual a final
	}
	else {
		principio->prev = NULL;
	}
	delete nodo;

	return extraido;
}

string ListaDE::extraerInter(string)
{
	return string();
}

string ListaDE::extraerFinal()
{
	return string();
}

void ListaDE::mostrarInicioFin()
{
	if (principio == NULL) {
		cout << "\t... Lista vacía ..." << endl;
		return;
	}
	nodo = principio;
	cout << "------------INICIO DE LA LISTA-------------" << endl;
	while (nodo!= NULL) {
		cout << "\t" << nodo->dato;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;
		nodo = nodo->sig;
	}
	cout << "------------FINAL DE LA LISTA-------------" << endl;
}

void ListaDE::mostrarFinInicio()
{
	if (principio == NULL) {
		cout << "\t... cola vacía ..." << endl;
		return;
	}
	nodo = final; //Empezamos en el último nodo
	cout << "------------FINAL DE LA LISTA-------------" << endl;
	while (nodo != NULL) {
		cout << "\t" << nodo->dato;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;
		nodo = nodo->prev; //Toma el nodo anterior como "siguiente" (va de atrás para adelante)
	} 
	cout << "------------INICIO DE LA LISTA-------------" << endl;
}
