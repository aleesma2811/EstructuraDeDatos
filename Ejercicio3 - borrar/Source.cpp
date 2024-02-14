#include "Arreglo.h"

int main() {
	setlocale(LC_ALL, "");
	int nuevo, codigo, opc, aBorrar;

	Arreglo numeros;

	do {
		numeros.mostrar();

		cout << "\n==============MEN�=================" << endl;
		cout << "1. Borrar" << endl;
		cout << "2. Insertar" << endl;
		cout << "0. Salir" << endl;
		cout << "Ingrese una opci�n" << endl;
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "Ingrese el entero a borrar: ";
			cin >> aBorrar;

			codigo = numeros.borrar(aBorrar);

				if (codigo == -1) {
					cout << "No existe el numero ingresado en el arreglo. NO se borr�. " << endl;
				}
				else {
					cout << "Elemento borrado" << endl;
				}
			break;
		case 2:
			cout << "'Inserte un entero: ";
			cin >> nuevo;

			codigo = numeros.insertar(nuevo);
			if (codigo == -2) {
				cout << "\nERROR, arreglo est� lleno, NO se insert� entero. " << endl;
			}
			if (codigo == -1) {
				cout << "\nERROR, ya existe en el arreglo, NO se insert� el entero. " << endl;
			}
			if (codigo == 0) {
				cout << "\nEntero insertado. " << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "Opci�n inv�lida" << endl;
		}

		
	} while (opc != 0);
		
	return 0;
}