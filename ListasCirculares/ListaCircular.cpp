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
		return -1; //Lista vac�a
	}
	/* Crear nodo */
	nodo = new Entero;

	/* Insertar dato */
	nodo->dato = nuevo;

	/* �ltimo apunta a principio */
	nodo->sig = principio;

	if (principio == NULL) { //Primera inserci�n
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
		cout << "Lista vac�a. No se encontr� ningun elemento"; //Lista vac�a
		return false;
	}

	do {
		if (nodo->dato == aBuscar) {
			revisado = nodo;
			return true;
		}
		/*if (principio = nodo) { //Primera b�squeda
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
		cout << "... lista vac�a ..." << endl;
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
