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

void Arbol::insertar(Nodo* nuevoNodo) // Recibe un nodo como par�metro
{
	// �rbol vac�o, se inserta en la ra�z
	if (!raiz) {
		raiz = nodo;
		cout << "�rbol vac�o. Se insert� en la ra�z" << endl;
		return;
	}
	// Valor menor se inserta a la izquierda
	if (nodo->dato < nuevoNodo->dato) {
		if (nuevoNodo->izq == nullptr) {
			nuevoNodo->izq = nodo;
			cout << "N�mero menor, se insert� de lado izquierdo de " << nuevoNodo->dato << endl;
			return;
		}
		else { // Izquierdo ya est� ocupado
			insertar(nuevoNodo->izq);
			return;
		}
	}
	// Valor mayor, se inserta del lado derecho
	if (nodo->dato > nuevoNodo->dato) {
		if (nuevoNodo->der == nullptr) {
			nuevoNodo->der = nodo;
			cout << "N�mero mayor, se insert� del lado derecho de " << nuevoNodo->dato << endl;
			return;
		}
		else { // Derecho ya est� ocupado
			insertar(nuevoNodo->der);
			return;
		}
	}
	cout << "Ya existe el nodo. NO se insert�" << endl;
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

	// Se encontr� el nodo
	if (nodoConsultado == nuevo->dato) {
		return nuevo;
	}

	// Buscar en el sub�rbol izquierdo
	if (nodoConsultado < nuevo->dato) {
		if (nuevo->izq != nullptr) {
			// Repetir consulta al sub�rbol
			encontrado = consultar(nuevo->izq, nodoConsultado);
			return encontrado;
		}
		else {
			// No existe en el nodo consultado
			return nullptr;
		}
	}

	// Buscar en el sub�rbol derecho
	if (nodoConsultado > nuevo->dato) {
		if (nuevo->der != nullptr) {
			encontrado = consultar(nuevo->der, nodoConsultado);
			return encontrado;
		}
		else {
			return nullptr;
		}
	}

	// No encontr�
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

		// Si los hijos existen, a�adir a la cola
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

/* ---------------------B�squeda por nivel--------------------- 
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
