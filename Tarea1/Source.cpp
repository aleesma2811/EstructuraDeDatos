#include "Tarea.h"

int main() {
	setlocale(LC_ALL, "");
	Tarea arregloI;
	Tarea arregloS;
	int opc;
	do {
		cout << "\n=============MENÚ PRINCIPAL==============" << endl;
		cout << "1. Arreglo de enteros. " << endl;
		cout << "2. Arreglo de strings. " << endl;
		cout << "0. Terminar. " << endl;
		cout << "Escoga el arreglo que desea ordenar: ";
		cin >> opc;

		switch (opc) {
		case 1: //Submenú de arreglo de enteros
			int opcS;
			do {
				cout << "\n----------Submenú----------" << endl;
				cout << "\n1. Orden ascendente" << endl;
				cout << "2. Orden descendente" << endl;
				cout << "3. Regresar al menú principal" << endl;
				cout << "Escoja como quiere ordenar el arreglo de enteros: ";
				cin >> opcS;

				switch (opcS) {
				case 1: //Ordenar arreglo de int de manera ascendente 
					arregloI.mostrarI(); //Mostrar desordenado
					arregloI.ordenarA(); //Ordenar arreglo
					arregloI.mostrarI(); //Mostrar ordenado
					break;
				case 2: //Ordenar arreglo de int de manera descendente
					arregloI.ordernarD();
					arregloI.mostrarI();
					break;
				default: //Regresar al menú principal
					break;
				}
			} while (opcS != 3);
			break;
		case 2: //Ordenar arreglo de strings alfabeticamente
			arregloS.mostrarS();
			arregloS.ordenarString();
			arregloS.mostrarS();

			break;

		default:
			cout << "Opción inválida. " << endl;
			break;
		}
	} while (opc != 0);

	return 0;
}