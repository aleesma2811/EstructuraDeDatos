#include "Lista.h"

int main() {
	int opc, retornoI;
	Lista lista;
	string nombre, empleado, retorno, aBuscar;

	do {
		cout << "\n==============MENÚ PRINCIPAL===============" << endl;
		cout << "1) Insertar al incio " << endl;
		cout << "2) Insertar intermedio " << endl;
		cout << "3) Insertar al final " << endl;
		cout << "\n4) Extraer al incio " << endl;
		cout << "5) Extraer intermedio " << endl;
		cout << "6) Extraer al final " << endl;
		cout << "\n7) Mostrar " << endl;
		cout << "0) Salir" << endl;
		cout << "\nIngrese una opción: ";
		cin >> opc;

		if (opc >= 1 && opc <= 3) {
			cout << "Ingrese el nombre del empleado: ";
			cin >> nombre;
		}

		switch (opc)
		{
		case 1:
			lista.insertarInicio(nombre);
			break;
		case 2:
			cout << "Ingrese el nombre a buscar: ";
			cin >> aBuscar;
			retornoI = lista.insertarInter(aBuscar, nombre);

			if (retornoI == -1) {
				cout << "Lista vacía. Se inserto al inicio" << endl;
			}
			else if (retornoI == -2) {
				cout << "No se encontró, se insertó al final";
			}
			else {
				cout << "Insertado";
			}

			break;
		case 3:
			retorno = lista.insertarFinal(nombre);
			if (retorno == "") {
				cout << "Lista vacía. Se inserto al inicio" << endl;
			}
			else {
				cout << "Se insertó al final" << endl;
			}
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			lista.mostrar();
			break;
		case 0:
			cout << "¡Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}
	} while (opc != 0);
}