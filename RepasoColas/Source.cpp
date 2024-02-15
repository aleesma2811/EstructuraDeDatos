#include "Colas.h"

int main() {
	Colas bolsa;
	string frutas, retornoE;
	int opc, cant;
	do {
		cout << "\n================MENÚ PRINCIPAL===================" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Ingrese el nombre de la fruta: ";
			cin >> frutas;
			cout << "Ingrese la cantidad de frutas en su bolsa: ";
			cin >> cant;

			bolsa.insertar(frutas, cant);
			cout << "Frutas agregadas a la bolsa" << endl;
			break;
		case 2:
			retornoE = bolsa.extraer();
			if (retornoE == "") {
				cout << "Cola vacía. NO se extrajo ninguna fruta" << endl;
			}
			else {
				cout << "Se extrajo la fruta '" << retornoE << "' de la bolsa" << endl;
			}
			break;
		case 3:
			bolsa.mostrar();
			break;
		case 0:

			break;
		default:
			break;
		}
	} while (opc != 0);


	return 0;
}