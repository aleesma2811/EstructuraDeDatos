#include "MatrizAdy.h"

MatrizAdy::MatrizAdy(int tam)
{
	maxNodos = tam;
	ocupados = 0;
	posNodo = -1;
	nodos = new char[tam]; // Arreglo de nodos
	arcos = new int* [tam]; // Renglones del arreglo de arcos
	for (int i = 0; i < tam; i++) {
		arcos[i] = new int[tam]; // Columnas de cada renglon de arcos
	}
	for (int i = 0; i < tam; i++) {
		nodos[i] = '=';
	}
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			arcos[i][j] = -1; // Inicializar adyacencias vacías
		}
	}
}

MatrizAdy::~MatrizAdy()
{
}

int MatrizAdy::insertarNodo(char nuevo)
{
	if (ocupados == maxNodos) { // Arreglo lleno, no se inserta
		return -1; 
	}
	if (ocupados == 0) { // Si el grafo está vacío
		nodos[ocupados] = nuevo;
		ocupados++;
		return 0;
	}
	if (buscarNodo(nuevo) != -1) { // Ya existe el nodo, no se inserta
		return -2;
	}
	nodos[ocupados] = nuevo; // Insertar el nodo
	ocupados++;
	return 0;
}

int MatrizAdy::insertarArco(char ori, char des, int peso)
{
	int posiDes = -1;

	if (ocupados == 0) { // Grafo vacío, no se inserta
		return -1;
	}
	posNodo = buscarNodo(ori);
	posiDes = buscarNodo(des);
	if (posNodo == -1 || posiDes == -1) { // No existe origen o destino, no se inserta
		return -2;
	}
	if (arcos[posNodo][posiDes] != -1) { // Ya existe el arco
		arcos[posNodo][posiDes] = peso;
		arcos[posiDes][posNodo] = peso; // Se modifica arco bidireccional;
		return -3;
	}
	else {
		arcos[posNodo][posiDes] = peso;
		arcos[posiDes][posNodo] = peso; // Se inserta arco bidireccional;
		return 0;
	}
	return 0;
}

void MatrizAdy::mostrar()
{
	cout << "\nMATRIZ DE ADYACENCIAS" << endl;
	cout << "\n\t" << endl;
	for (int i = 0; i < maxNodos; i++) {
		cout << "\t" << nodos[i];
		for (int j = 0; j < maxNodos; j++) {
			if (arcos[i][j] != -1) {
				cout << "\t" << arcos[i][j];
			}
			else {
				cout << "\t" << "-";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int MatrizAdy::buscarNodo(int buscado)
{
	for (int i = 0; i < ocupados; i++) {
		if (nodos[i] == buscado) {
			return i;
		}
	}
	return -1;
}
