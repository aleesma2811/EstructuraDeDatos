#include "Binario.h"

Binario::Binario()
{
	raiz = nodo = NULL;
}

Binario::~Binario()
{
}

Numero* Binario::consultarRaiz()
{
	return raiz; // Devuelve la direcci�n de la ra�z
}

void Binario::crearNodo(int valor)
{
	nodo = new Numero;
	nodo->num = valor; // Insertar el valor en el nodo
	nodo->izq = NULL;
	nodo->der = NULL;
}

void Binario::insertar(Numero* inicio)
{
	if (raiz == NULL) { // Si el �rbol est� vac�o, se inserta en la ra�z
		raiz = nodo;
		cout << "Se insert� en la ra�z" << endl;
		return;
	}

	if (nodo->num < inicio->num) { // Valor es menor, se inserta a la izquierda
		if (inicio->izq == NULL) { // Si el espacio izquierdo es NULL, se inserta el nodo
			inicio->izq = nodo;
			cout << "\tSe insert� a la izquierda de " << inicio->izq << endl;
			return;
		}
		else { // Si el izquierdo ya est� ocupado, se vuelve a repetir el procedimiento en ese nodo hasta que encuentre espacio
			insertar(inicio->izq);
			return;
		}
	}

	if (nodo->num > inicio->num) { // Valor es mayor, se inserta a la derecha
		if (inicio->der == NULL) { // Si el espacio derecho es NULL, se inserta el nodo
			inicio->der = nodo;
			cout << "\tSe insert� a la derecha de " << inicio->der << endl;
			return;
		}
		else {
			insertar(inicio->der);
			return;
		}
	}

	cout << "Ya existe " << nodo->num << " en el �rbol. No se insert�" << endl;
	delete nodo;
	return;
}

void Binario::recorrerInOrden(Numero* inicio)
{
	if (inicio->izq != NULL) {
		recorrerInOrden(inicio->izq);
	}
	cout << "\t" << inicio->num;
	if (inicio->der != NULL) {
		recorrerInOrden(inicio->der);
	}
}

void Binario::recorrerPreOrden(Numero* inicio)
{
	cout << "\t" << inicio->num;
	if (inicio->izq != NULL) recorrerPreOrden(inicio->izq);
	if (inicio->der != NULL) recorrerPreOrden(inicio->der);
}

void Binario::recorrerPosOrden(Numero* inicio)
{
	if (inicio->izq != NULL) recorrerPosOrden(inicio->izq);
	if (inicio->der != NULL) recorrerPosOrden(inicio->der);
	cout << "\t" << inicio->num;
}
