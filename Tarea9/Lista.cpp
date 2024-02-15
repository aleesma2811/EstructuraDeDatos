#include "Lista.h"

Lista::Lista()
{
	setlocale(LC_ALL, "");
}

Lista::~Lista()
{
}

void Lista::insertarInicio(int nuevo)
{
	nodo = new Numeros;
	nodo->num = nuevo;

	nodo->sig = principio; // Enlazar nuevo nodo a principio
	principio = nodo; // Principio apunta al nodo insertado (el primero en la lista)

	if (final == NULL) {
		final = nodo;
	}
}

int Lista::insertarIntermedio(int nuevo) //Número ingresado
{
	Numeros* nodoAnterior;

	if (!principio) {
		insertarInicio(nuevo);
		cout << "prueba 1" << endl;
		return -1;
	}

	nodoAnterior = principio;

	cout << &nodoAnterior << endl;
	cout << &final << endl;

	cout << "prueba 2" << endl;
	while (nodoAnterior != final) {
		cout << "prueba 3" << endl;
		if (nodoAnterior->num >= nuevo) {
			insertarInicio(nuevo);
			cout << "prueba 4" << endl;
		}
		else if (nodoAnterior->num < nuevo && nodoAnterior->sig->num > nuevo) { //Si nodo anterior es mayor que nuevoNodo y menor que nodo siguiente
			nodo = new Numeros;
			nodo->num = nuevo;

			// Enlazar nodo anterior, nuevo nodo y nodo siguiente
			nodo->sig = nodoAnterior->sig;
			nodoAnterior->sig = nodo;

			if (nodo == final) {
				final = nodo;
			}
		}
		else if (nodoAnterior->sig->num < nuevo) {
			insertarFinal(nuevo);
		}
		//Pasar al siguiente nodo del while
		nodoAnterior = nodoAnterior->sig;
	}
	return 0;
}

int Lista::insertarFinal(int nuevo)
{
	if (principio == NULL) {
		insertarInicio(nuevo);
		return -1;
	}
	nodo = new Numeros;
	nodo->num = nuevo;

	nodo->sig = NULL; // Que apunte a NULL para que sea el final de la lista

	final->sig = nodo;
	final = nodo;
	return 0;
}

int Lista::extraerInicio()
{
	int extraido;

	if (principio == NULL) {
		return -1;
	}
	nodo = principio;

	extraido = nodo->num;

	return 0;
}

int Lista::extraerIntermedio(int)
{
	return 0;
}

int Lista::extraerFinal()
{
	return 0;
}

void Lista::mostrar()
{
	if (principio == NULL) {
		cout << "... Cola vacía ..." << endl;
		return;
	}
	nodo = principio;
	while (nodo) {
		cout << "\t" << nodo->num;
		if (nodo == principio) cout << "\t <- Principio";
		if (nodo == final) cout << "\t <- Final";
		cout << endl;

		nodo = nodo->sig;
	}

}
