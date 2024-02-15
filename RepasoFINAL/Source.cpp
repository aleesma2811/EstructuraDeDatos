#include "Header.h"

int main() {

	setlocale(LC_ALL, "");
	int opc, num, aConsultar, nHojas;
	char letra;
	Arbol arbolBB;
	Nodo* raiz = nullptr;
	Nodo* encontrado;

	do {
		cout << "\n============== MEN� PRINCIPAL ===============" << endl;
		cout << "1) Insertar " << endl;
		cout << "2) Consultar " << endl;
		cout << "3) Mostrar (In-Orden) " << endl;
		cout << "4) Mostrar (Post-Orden) " << endl;
		cout << "5) Mostrar (Pre-Orden) " << endl;
		cout << "6) Contar hojas" << endl;
		cout << "0) Salir " << endl;
		cout << "Ingrese una opci�n: " << endl;
		cin >> opc;

		if (opc <= 3) {
			raiz = arbolBB.getRaiz();
		}

		switch (opc)
		{
		case 1:
			cout << "\nIngrese un n�mero: ";
			cin >> num;
			cout << "Ingrese una letra: ";
			cin >> letra;
			arbolBB.crearNodo(num, letra);
			arbolBB.insertar(raiz);
			break;
		case 2:
			// �rbol vac�o
			if (!raiz) {
				cout << "�rbol vac�o, no se consult+o ning�n nodo " << endl;
			}
			else {
				cout << "\nIngrese el n�mero a consultar: ";
				cin >> aConsultar;
				encontrado = arbolBB.consultar(raiz, aConsultar);
				// Encontrado existe
				if (encontrado != nullptr) {
					cout << "La letra del nodo " << encontrado->dato << "es '" << encontrado->letra << "'" << endl;
				}
				else {
					cout << "No se encontr� el nodo " << endl;
				}
			}
			break;
		case 3:
			if (!raiz) {
				cout << "�rbol vac�o " << endl;
			}
			else {
				cout << "Recorrido In-Orden: ";
				arbolBB.recorrerInOrden(raiz);
			}
			break;
		case 4:
			if (!raiz) {
				cout << "�rbol vac�o " << endl;
			}
			else {
				cout << "Recorrido Post-Orden: ";
				arbolBB.recorrerPostOrden(raiz);
			}
			break;
		case 5:
			if (!raiz) {
				cout << "�rbol vac�o " << endl;
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