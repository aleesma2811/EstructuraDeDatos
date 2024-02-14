#include "Arreglo.h"

int main() {
	Arreglo numeros;
	int opc;

	do {
		cout << "\n============MENÚ PRINCIPAL==============" << endl;
		cout << "1. Nombre " << endl;
		cout << "2. Poblar " << endl;
		cout << "3. Ordenar " << endl;
		cout << "4. Mostrar " << endl;
		cout << "0. Salir " << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			numeros.leerNombre();
			break;
		case 2:
			numeros.insertar();
			break;
		case 3:
			numeros.ordenar();
			break;
		case 4:
			numeros.mostrar();
			break;
		default:
			cout << "Opción inválida" << endl;
			break;
		case 0:
			cout << "Hasta pronto" << endl;
		}
	} while (opc != 0);

	
	
	return 0;
}