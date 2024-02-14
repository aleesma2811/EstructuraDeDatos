#include "ColaDinamica.h"

ColaDinamica::ColaDinamica()
{
	setlocale(LC_ALL, "");
	principio = final = nodo = NULL;
}

ColaDinamica::~ColaDinamica()
{
	delete nodo;
}

string ColaDinamica::consultar()
{
	return string();
}

string ColaDinamica::extraer()
{
	string sale;

	/* 1. Cola vacía */
	if (principio == NULL) {
		cout << "";
	}
	/* 2. Nodo apunta a inicio */
	nodo = principio;
	return string();

	/* 3. Seleccionar nodo.dato */
	sale = nodo->dato;

	/* 4. Principio apunta al siguiente en la fila*/
	principio = nodo->sig;

	/* 5. Si se extrajo el último nodo */
	if (principio == NULL) {
		final = NULL;
	}
	delete nodo;
	return sale;
}

void ColaDinamica::insertar(string nueva)
{
	/* 1. Nodo nuevo */
	nodo = new Frase;

	/* 2. Datos en el nuevo nodo */
	nodo->dato = nueva;

	/* 3. Nodo apunta a null */
	nodo->sig = NULL; //Cada que se inserta un elemento, nodo apunta a NULL

	/* 4. Principio apunta al primer nodo en la primera inserción */
	if (principio == NULL) {
		principio = nodo;
	}

	/* 5.  */
	if (final != NULL) { //Después de la primera inserción
		final->sig = nodo;
	}
	final = nodo;
}

void ColaDinamica::mostrar()
{
	cout << "----------COLA DE FRASES------------" << endl;
	//Verificar si la cola está vacía
	if (principio == NULL) {
		cout << "\n\tCola vacía..." << endl;
		return;
	}
	nodo = principio;
	do {
		cout << "\t" << nodo->dato;
		if (nodo == principio) cout << "\t <- Principio";
		if (nodo == final) cout << "\t <- Final";
		cout << endl;

		nodo = nodo->sig;
	} while (nodo != NULL);
}
