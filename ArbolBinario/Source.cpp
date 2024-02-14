#include "Binario.h"

int main() {
	setlocale(LC_ALL, "");

	Binario arbolBB;
	int opc, valor;
	Numero* nodoRaiz = NULL;

	do {
		cout << "\n============= MENÚ PRINCIPAL ==============" << endl;
		cout << "1) Insertar " << endl;

		cout << "\n2) In-orden " << endl;
		cout << "3) Pre-orden " << endl;
		cout << "4) Pos-orden " << endl;

		cout << "\n0) Salir" << endl;

		cout << "Ingrese una opción: ";
		cin >> opc;

		if (opc <= 4) {
			nodoRaiz = arbolBB.consultarRaiz();
		}

		switch (opc)
		{
		case 1:
			cout << "\nIngrese el valor a insertar en el árbol: ";
			cin >> valor;
			arbolBB.crearNodo(valor);
			nodoRaiz = arbolBB.consultarRaiz();
			arbolBB.insertar(nodoRaiz);
			break;
		case 2:
			if (nodoRaiz == NULL) {
				cout << "El árbol está vacío" << endl;
			}
			else {
				arbolBB.recorrerInOrden(nodoRaiz);
			}
			break;
		case 3:
			if (nodoRaiz == NULL) {
				cout << "El árbol está vacío" << endl;
			}
			else {
				arbolBB.recorrerPreOrden(nodoRaiz);
			}
			break;
		case 4:
			if (nodoRaiz == NULL) {
				cout << "El árbol está vacío" << endl;
			}
			else {
				arbolBB.recorrerPosOrden(nodoRaiz);
			}
			break;
		case 5:

			break;
		case 0:
			cout << "¡Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}

	} while (opc != 0);
}