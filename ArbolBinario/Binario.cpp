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
	return raiz; // Devuelve la dirección de la raíz
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
	if (raiz == NULL) { // Si el árbol está vacío, se inserta en la raíz
		raiz = nodo;
		cout << "Se insertó en la raíz" << endl;
		return;
	}

	if (nodo->num < inicio->num) { // Valor es menor, se inserta a la izquierda
		if (inicio->izq == NULL) { // Si el espacio izquierdo es NULL, se inserta el nodo
			inicio->izq = nodo;
			cout << "\tSe insertó a la izquierda de " << inicio->izq << endl;
			return;
		}
		else { // Si el izquierdo ya está ocupado, se vuelve a repetir el procedimiento en ese nodo hasta que encuentre espacio
			insertar(inicio->izq);
			return;
		}
	}

	if (nodo->num > inicio->num) { // Valor es mayor, se inserta a la derecha
		if (inicio->der == NULL) { // Si el espacio derecho es NULL, se inserta el nodo
			inicio->der = nodo;
			cout << "\tSe insertó a la derecha de " << inicio->der << endl;
			return;
		}
		else {
			insertar(inicio->der);
			return;
		}
	}

	cout << "Ya existe " << nodo->num << " en el árbol. No se insertó" << endl;
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
