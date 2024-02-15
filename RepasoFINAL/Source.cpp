#include "Header.h"

int main() {

	setlocale(LC_ALL, "");
	int opc, num, aConsultar, nHojas;
	char letra;
	Arbol arbolBB;
	Nodo* raiz = nullptr;
	Nodo* encontrado;

	do {
		cout << "\n============== MENÚ PRINCIPAL ===============" << endl;
		cout << "1) Insertar " << endl;
		cout << "2) Consultar " << endl;
		cout << "3) Mostrar (In-Orden) " << endl;
		cout << "4) Mostrar (Post-Orden) " << endl;
		cout << "5) Mostrar (Pre-Orden) " << endl;
		cout << "6) Contar hojas" << endl;
		cout << "0) Salir " << endl;
		cout << "Ingrese una opción: " << endl;
		cin >> opc;

		if (opc <= 3) {
			raiz = arbolBB.getRaiz();
		}

		switch (opc)
		{
		case 1:
			cout << "\nIngrese un número: ";
			cin >> num;
			cout << "Ingrese una letra: ";
			cin >> letra;
			arbolBB.crearNodo(num, letra);
			arbolBB.insertar(raiz);
			break;
		case 2:
			// Árbol vacío
			if (!raiz) {
				cout << "Árbol vacío, no se consult+o ningún nodo " << endl;
			}
			else {
				cout << "\nIngrese el número a consultar: ";
				cin >> aConsultar;
				encontrado = arbolBB.consultar(raiz, aConsultar);
				// Encontrado existe
				if (encontrado != nullptr) {
					cout << "La letra del nodo " << encontrado->dato << "es '" << encontrado->letra << "'" << endl;
				}
				else {
					cout << "No se encontró el nodo " << endl;
				}
			}
			break;
		case 3:
			if (!raiz) {
				cout << "Árbol vacío " << endl;
			}
			else {
				cout << "Recorrido In-Orden: ";
				arbolBB.recorrerInOrden(raiz);
			}
			break;
		case 4:
			if (!raiz) {
				cout << "Árbol vacío " << endl;
			}
			else {
				cout << "Recorrido Post-Orden: ";
				arbolBB.recorrerPostOrden(raiz);
			}
			break;
		case 5:
			if (!raiz) {
				cout << "Árbol vacío " << endl;
			}
			else {
				cout << "Recorrido Pre-Orden: ";
				arbolBB.recorrerPreOrden(raiz);
			}
			break;
		case 6:
			nHojas = arbolBB.contarHojas(raiz);
			cout << "No. de hojas: " << nHojas << endl;
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (opc != 0);

	return 0;
}