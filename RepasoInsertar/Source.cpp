#include "Tienda.h"

int main() {
	Tienda prueba;
	int opc;
	bool codigo;
	do {
		cout << "1. Insertar " << endl;
		cout << "2. Mostrar " << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			prueba.poblar();
			break;
		case 2:
			prueba.mostrar();
			break;
		default:
			break;
		}
		return 0;
	} while (opc != 0);
}