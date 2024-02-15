#include "ListaCircular.h"

int main() {
	int opc, retorno, aBuscar;
	int num;
	bool retornoB;
	ListaCircular lista;

	do {
		cout << "\n==============MENÚ PRINCIPAL===============" << endl;


		cout << "1) Insertar al final " << endl;
		cout << "2) Insertar al inicio " << endl;
		cout << "3) Buscar " << endl;

		cout << "\n4) Mostrar " << endl;
		cout << "0) Salir" << endl;
		cout << "\nIngrese una opción: ";
		cin >> opc;

		if (opc >= 1 && opc <= 2) {
			cout << "Ingrese un entero: ";
			cin >> num;
		}

		switch (opc)
		{
		case 1:

			retorno = lista.insertarFinal(num);
			if (retorno == -1) {
				cout << "Lista vacía, se insertó al final" << endl;
			}
			else {
				cout << "Insertado correctamente" << endl;
			}
			break;

		case 2:
			lista.insertarInicio(num);
			break;

		case 3:
			cout << "Ingrese el elemento a buscar: ";
			cin >> aBuscar;
			retornoB = lista.busqueda(aBuscar);
			if (retornoB == false) {
				cout << "No se encontró el elemento. ";
			}
			else {
				cout << "Se encontró el elemento " << aBuscar;
			}
			break;

		case 4:
			lista.mostrarInicio();
			break;

		case 0:
			cout << "¡Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}
	} while (opc != 0);

	return 0;
}