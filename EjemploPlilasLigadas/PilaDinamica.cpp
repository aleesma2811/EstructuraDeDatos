#include "PilaDinamica.h"

PilaDinamica::PilaDinamica()
{
	setlocale(LC_ALL, "");
	tope = NULL;
}

PilaDinamica::~PilaDinamica()
{
}

int PilaDinamica::consultar()
{
	Nodo* extraido; //En extraido se pone la dirección de tope
	int num;

	//1) Verificar si hay valores en la pila
	if (tope == NULL) {
		return -1; //Pila vacía
	}

	//2) Extraer la información de tope
	extraido = tope; //Consultar la información de tope en extraído

	//3) Entregar los datos extraidos
	num = extraido->dato;

	return num;
}

int PilaDinamica::extraer()
{
	Nodo* extraido; //En extraido se pone la dirección de tope
	int num;

	//1) Verificar si hay valores en la pila
	if (tope == NULL) {
		return -1; //Pila vacía
	}

	//2) Extraer la información de tope
	extraido = tope;

	//3) Descender el tope
	tope = tope->anterior;

	//4) Entregar los datos extraidos
	num = extraido->dato;

	//5) Liberar extraido
	delete extraido;

	return num;
}

void PilaDinamica::insertar(int entra)
{
	//1) Crear nodo
	nodo = new Nodo;

	//2) Rehistrar los datos en el nuevo nodo
	nodo->dato = entra;

	//3) Asignar dirección de nodo anterior al campo de enlace
	nodo->anterior = tope;

	tope = nodo;

}

void PilaDinamica::mostrar()
{
	cout << "\Pila Dinamica" << endl;
	if (tope == NULL) {
		cout << "Pila vacía" << endl;
		return;
	}

	//Como no podemos mover tope, asignamos otra variable con el mismo valor, y ese lo movemos.
	nodo = tope;

	while (nodo != NULL) {
		cout << "\t" << nodo->dato << "\t" << nodo->anterior;
		if (nodo == tope) {
			cout << "\t <- tope";
		}
		cout << endl;
		nodo = nodo->anterior;
	}
}
