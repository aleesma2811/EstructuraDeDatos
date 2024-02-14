#include "PilaDinamica.h"

PilaDinamica::PilaDinamica()
{
	tope = NULL;
}

int PilaDinamica::Consultar()
{
	Nodo* extraido;
	int num;

	/* Paso 1: Verificar si hay valores en la pila */
	if (tope == NULL)
		return -1;	// Pila vacía. NO se extrae nada
	/* paso 2: Extraer la información del tope */
	extraido = tope;
	/* Paso 3: Entregar los datos extraidos */
	num = extraido->dato;

	return num;
}

int PilaDinamica::Extraer()
{
	Nodo *extraido;
	int num;

	/* Paso 1: Verificar si hay valores en la pila */
	if (tope == NULL)
		return -1;	// Pila vacía. NO se extrae nada
	/* paso 2: Extraer la información del tope */
	extraido = tope;
	/* Paso 3: Descender el tope */
	tope = tope->anterior;
	/* Paso 4: Entregar los datos extraidos */
	num = extraido->dato;
	/* Paso 5: Liberar extraido */
	delete extraido;

	return num;
}

void PilaDinamica::Insertar(int entra)
{
	/* Paso 1: Crear nodo */
	nodo = new Nodo;
	/* Paso 2: Registrar los datos en el nuevo nodo */
	nodo->dato = entra;
	/* Paso 3: Asignar dirección de nodo anterior al campo de enlace */
	nodo->anterior = tope;
	/* Paso 4: Apuntar el tope al nuevo nodo */
	tope = nodo;
}

void PilaDinamica::Mostrar()
{
	cout << "\nPila Dinámica: " << endl;
	if (tope == NULL)
	{
		cout << "\tPila VACÍA\n" << endl;
		return;
	}

	nodo = tope;

	while (nodo != NULL)
	{
		cout << "\t" << nodo->dato << "\t" << nodo->anterior;
		if (nodo == tope) cout << "\t<= tope";
		cout << endl;
		nodo = nodo->anterior;
	}
	cout << endl;
}
