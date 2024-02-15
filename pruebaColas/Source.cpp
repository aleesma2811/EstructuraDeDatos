#include "Colas.h"

int main() {
	Colas prueba;
	int numeros;

	int opc, retorno;
	string palabraNueva;
	do {
		cout << "\n=============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Ingrese una palabra: ";
			cin >> palabraNueva;

			retorno = prueba.insertar(palabraNueva);
			if (retorno == -1) {
				cout << "\tCola llena, NO se insertó la palabra" << endl;
			}
			else {
				cout << "\tPalabra insertada" << endl;
			}
			break;

		case 2:
			retorno = prueba.extraer();

			if (retorno == -1 || retorno == -2) {
				cout << "\tCola vacía, NO se extrajo ninguna palabra" << endl;
			}
			break;

		case 3:
			prueba.mostrar();
			break;
		case 0:
			cout << "\n¡Hasta pronto! :)" << endl;
			break;

		default:
			break;
		}

	} while (opc != 0);

	return 0;
}