#include "Arreglo.h"

int main() {
	setlocale(LC_ALL, "");
	int nuevo, codigo;

	Arreglo numeros;

	do {
		numeros.mostrar();
		cout << "'Inserte un entero (oprima -1 para terminar): ";
		cin >> nuevo;
		if (nuevo != -1) {
			codigo = numeros.insertar(nuevo);
			if (codigo == -2) {
				cout << "\nERROR, arreglo está lleno, NO se insertó entero. " << endl;
			}
			if (codigo == -1) {
				cout << "\nERROR, ya existe en el arreglo, NO se insertó el entero. " << endl;
			}
			if (codigo == 0) {
				cout << "\nEntero insertado. " << endl;
			}
		}
	} while (nuevo != -1);
	return 0;
}