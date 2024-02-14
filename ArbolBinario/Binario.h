#pragma once
#include <iostream>

using namespace std;

struct Numero {
	Numero* izq;
	int num;
	Numero* der;
};

/*
No se va a mostrar el árbol
*/

class Binario
{
public:
	Binario();
	~Binario();
	Numero* consultarRaiz();
	void crearNodo(int); // Crear el nodo
	void insertar(Numero*); // Pasar nodo creado como parámetro

	// Recorrer
	void recorrerInOrden(Numero*);
	void recorrerPreOrden(Numero*);
	void recorrerPosOrden(Numero*);

private:
	Numero* raiz, * nodo;

};