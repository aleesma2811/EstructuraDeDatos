#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
	setlocale(LC_ALL, "");
}

ListaCircular::~ListaCircular()
{
}

int ListaCircular::insertarInicio(int nuevo)
{
	nodo = new Entero;
	nodo->dato = nuevo;

	if (principio == NULL) {
		principio = revisado = final = nodo;
		nodo->sig = principio;
	}
	else {
		nodo->sig = principio;
		principio = nodo;
		final->sig = nodo;
	}
	return 0;
}

int ListaCircular::insertarFinal(int nuevo)
{
	if (principio == NULL) {
		insertarInicio(nuevo);
		return -1; //Lista vacía
	}
	/* Crear nodo */
	nodo = new Entero;

	/* Insertar dato */
	nodo->dato = nuevo;

	/* Último apunta a principio */
	nodo->sig = principio;

	if (principio == NULL) { //Primera inserción
		principio = nodo;
	}
	else {
		/* Enlazar el ultimo nodo (anterior) al nuevo nodo insertado */
		final->sig = nodo;
	}

	final = nodo;
	return 0;
}


bool ListaCircular::busqueda(int aBuscar)
{
	nodo = revisado;

	if (principio == NULL) {
		cout << "Lista vacía. No se encontró ningun elemento"; //Lista vacía
		return false;
	}

	do {
		if (nodo->dato == aBuscar) {
			revisado = nodo;
			return true;
		}
		/*if (principio = nodo) { //Primera búsqueda
			revisado = nodo;
			return;
		}*/
		nodo = nodo->sig;

			//nodo->sig = revisado
	} while (nodo != revisado);

	return false;
}



void ListaCircular::mostrarInicio()
{
	if (principio == NULL) {
		cout << "... lista vacía ..." << endl;
		return;
	}
	nodo = principio;

	 do {
		cout << "\t" << nodo->dato;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;
		
		nodo = nodo->sig;
	 } while (nodo != principio);

}

void ListaCircular::mostrarRevisado()
{
}
