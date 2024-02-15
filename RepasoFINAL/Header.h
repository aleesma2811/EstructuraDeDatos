#pragma once
#include <iostream>
#include <queue>

using namespace std;

struct Nodo {
	int dato;
	char letra;
	Nodo* der;
	Nodo* izq;
};

/*
struct NodoCola {
	Nodo* nodo;
	NodoCola* sig;
};
*/


class Arbol {
public:
	Arbol();
	~Arbol();

	Nodo* crearNodo(int, char); // Tipo del nodo
	void insertar(Nodo*);
	Nodo* getRaiz();
	Nodo* consultar(Nodo*, int);
	void recorrerInOrden(Nodo*);
	void recorrerPostOrden(Nodo*);
	void recorrerPreOrden(Nodo*);
	void busquedaPorNivel(Nodo*);
	int contarHojas(Nodo*);

private:
	Nodo* nodo, *raiz;
};

/*
class Cola {
public:
	Cola();
	~Cola();
	void insertarInicio(Nodo*);
	void extraerFinal();
private:
	NodoCola* inicio, * final;
};

void busquedaPorNivel(Nodo*);

*/
