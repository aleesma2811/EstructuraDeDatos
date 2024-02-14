#include "Pilas.h"

int main() {
	Pilas pantallas;
	string modelo;
	int opc, nuevo, retorno;

	do {
		cout << "\n=============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "4) Consultar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;
		if (opc == 0) {
			cout << "¡Hasta pronto! :)" << endl;
		}

		switch (opc)
		{
		case 1:
			cout << "Ingrese el modelo de la pantalla: ";
			cin >> modelo;
			//Insertar modelo
			retorno = pantallas.insertar({modelo});
			if (retorno == -1) {
				cout << "Pila llena, NO se insertó el modelo" << endl;
			}
			else {
				cout << "Modelo insertado" << endl;
			}
			break;
		case 2:
			retorno = pantallas.extraer();
			if (retorno == -1) {
				cout << "Pila vacía, NO se extrajo ningún elemento. " << endl;
			}
			else {
				cout << "Elemento extraido" << endl;
			}
			break;
		case 3:
			cout << "\n--------Pantallas-----------" << endl;
			pantallas.mostrar();
			break;
		case 4:

			break;
		default:
			break;
		}
	} while (opc != 0);

	return 0;
}