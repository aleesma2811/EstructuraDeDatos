#include "Lista.h"

Lista::Lista()
{
}

Lista::~Lista()
{
}

void Lista::insertarInicio(Nombre nuevo)
{
	nodo = new Nombre;

	nodo->nombre = nuevo.nombre;

	if (principio == NULL) {
		principio = rev = final = nodo;
		nodo->sig = principio;
	}
	else {
		nodo->sig = principio;
		principio = nodo;
		final->sig = nodo;
	}
}

int Lista::insertarFinal(Nombre nuevo)
{
	if (!principio) { // Si está vacío, se inserta al inicio
		insertarInicio(nuevo);
		return -1; 
	}
	nodo = new Nombre;

	nodo->nombre = nuevo.nombre;

	final->sig = nodo;
	final = nodo;
	nodo->sig = principio;
}

void Lista::mostrar()
{
	cout << "\n---------------------------------" << endl;
	if (principio == NULL) {
		cout << "... lista vacía ..." << endl;
		return;
	}

	nodo = principio;

	do {
		cout << "\t" << nodo->nombre;
		if (nodo == principio) cout << "\t<- Principio";
		if (nodo == final) cout << "\t<- Final";
		cout << endl;

		nodo = nodo->sig;
	} while (nodo != principio);
}

int Lista::extraerIntermedio()
{
	Nombre* nodoAnterior = NULL;

	if (!principio) {
		return -1; // SI la lista está vacía
	}

	nodo = principio;
	int contador = 1;

	do {
		if (contador % 2 == 1) {

			// Primer nodo
			if (nodo == principio) { 
				principio = principio->sig; // Actualizar principio 
				final->sig = principio; // Ajustar final

				// Eliminar
				Nombre* temp = nodo;
				nodo = nodo->sig;
				delete temp;
			}
			else {
				// Saltar del nodo anterior al nodo siguiente
				nodoAnterior->sig = nodo->sig;

				Nombre* temp = nodo;
				// Apuntar al siguiente nodo
				nodo = nodo->sig;
				// Eliminar nodo
				delete temp;
			}
		}
		else {
			nodoAnterior = nodo;
			nodo = nodo->sig;
		}

		contador++;

	} while (nodo != principio);

	return 0;
}

int Lista::contarNodos()
{
	int contador = 0;

	if (!principio) {
		return contador; //Lista vacía, devuelve 0
	} 

	nodo = principio;

	do {
		//Agregar valor al contador hasta que termine la lista
		contador++;
		nodo = nodo->sig;
	} while (nodo != principio);

	// Devolver valor final del contador
	return contador;
}
