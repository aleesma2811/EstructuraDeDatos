#include "Header.h"

Arbol::Arbol()
{
	raiz = nodo = nullptr;
}

Arbol::~Arbol()
{
}

Nodo* Arbol::crearNodo(int num, char letra)
{
	nodo = new Nodo;
	nodo->dato = num;
	nodo->letra = letra;
	nodo->der = nullptr;
	nodo->izq = nullptr;

	return nodo;
}

void Arbol::insertar(Nodo* nuevoNodo) // Recibe un nodo como parámetro
{
	// Árbol vacío, se inserta en la raíz
	if (!raiz) {
		raiz = nodo;
		cout << "Árbol vacío. Se insertó en la raíz" << endl;
		return;
	}
	// Valor menor se inserta a la izquierda
	if (nodo->dato < nuevoNodo->dato) {
		if (nuevoNodo->izq == nullptr) {
			nuevoNodo->izq = nodo;
			cout << "Número menor, se insertó de lado izquierdo de " << nuevoNodo->dato << endl;
			return;
		}
		else { // Izquierdo ya está ocupado
			insertar(nuevoNodo->izq);
			return;
		}
	}
	// Valor mayor, se inserta del lado derecho
	if (nodo->dato > nuevoNodo->dato) {
		if (nuevoNodo->der == nullptr) {
			nuevoNodo->der = nodo;
			cout << "Número mayor, se insertó del lado derecho de " << nuevoNodo->dato << endl;
			return;
		}
		else { // Derecho ya está ocupado
			insertar(nuevoNodo->der);
			return;
		}
	}
	cout << "Ya existe el nodo. NO se insertó" << endl;
	// Eliminar nodo no insertado
	delete nodo;
}

Nodo* Arbol::getRaiz()
{
	return raiz;
}

Nodo* Arbol::consultar(Nodo* nuevo, int nodoConsultado)
{
	Nodo* encontrado;

	// Se encontró el nodo
	if (nodoConsultado == nuevo->dato) {
		return nuevo;
	}

	// Buscar en el subárbol izquierdo
	if (nodoConsultado < nuevo->dato) {
		if (nuevo->izq != nullptr) {
			// Repetir consulta al subárbol
			encontrado = consultar(nuevo->izq, nodoConsultado);
			return encontrado;
		}
		else {
			// No existe en el nodo consultado
			return nullptr;
		}
	}

	// Buscar en el subárbol derecho
	if (nodoConsultado > nuevo->dato) {
		if (nuevo->der != nullptr) {
			encontrado = consultar(nuevo->der, nodoConsultado);
			return encontrado;
		}
		else {
			return nullptr;
		}
	}

	// No encontró
	return nullptr;
}

void Arbol::recorrerInOrden(Nodo* nuevo) // IRD
{
	if (nuevo->izq != nullptr) {
		recorrerInOrden(nuevo->izq);
	}
	cout << "\t" << nuevo->dato;
	if (nuevo->der != nullptr) {
		recorrerInOrden(nuevo->der);
	}
}

void Arbol::recorrerPostOrden(Nodo* nuevo) // IDR
{
	if (nuevo->izq != nullptr) {
		recorrerPostOrden(nuevo->izq);
	}
	if (nuevo->der != nullptr) {
		recorrerPostOrden(nuevo->der);
	}
	cout << "\t" << nuevo->dato;
}

void Arbol::recorrerPreOrden(Nodo* nuevo)
{
	cout << "\t" << nuevo->dato;
	if (nuevo->izq != nullptr) {
		recorrerPreOrden(nuevo->izq);
	}
	if (nuevo->der != nullptr) {
		recorrerPreOrden(nuevo->der);
	}
}

void Arbol::busquedaPorNivel(Nodo* nuevo)
{
	if (!nuevo) {
		return;
	}
	queue<Nodo*> cola;
	cola.push(nuevo);

	while (!cola.empty())
	{
		// Visitar el inicio de la cola
		nodo = cola.front();
		cout << nodo->dato << " ";

		// Si los hijos existen, añadir a la cola
		if (nodo->izq != nullptr) {
			cola.push(nodo->izq);
		}
		if (nodo->der != nullptr) {
			cola.push(nodo->der);
		}
		cola.pop();
	}
}

int Arbol::contarHojas(Nodo* nuevo)
{
	int contHojas = 0;
	if (nuevo->izq != nullptr) {
		recorrerInOrden(nuevo->izq);
	}
	if (nuevo->der != nullptr) {
		recorrerInOrden(nuevo->der);
	}
	if (nuevo->izq == nullptr && nuevo->der == nullptr) {
		contHojas++;
	}
	return contHojas;
}

/* ---------------------Búsqueda por nivel--------------------- 
Cola::Cola()
{
}

Cola::~Cola()
{
}

void Cola::insertarInicio(Nodo* nodo)
{
	
}

void Cola::extraerFinal()
{
}
*/
