#include "Binario.h"

int main() {
	setlocale(LC_ALL, "");

	Binario arbolBB;
	int opc, valor;
	Numero* nodoRaiz;

	do {
		cout << "============= MEN� PRINCIPAL ==============" << endl;
		cout << "1) Insertar " << endl;
		cout << "0) Salir" << endl;
		// cout << "1) " << endl;
		// cout << "1) " << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\nIngrese el valor a insertar en el �rbol: ";
			cin >> valor;
			arbolBB.crearNodo(valor);
			nodoRaiz = arbolBB.consultarRaiz();
			arbolBB.insertar(nodoRaiz);
			break;
		case 0:
			cout << "�Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}

	} while (opc != 0);
}