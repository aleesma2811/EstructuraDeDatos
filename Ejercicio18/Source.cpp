#include "ListaDE.h"

int main() {
	int opc;
	ListaDE prueba;
	Palabra palabra;
	string aBuscar, retornoE;
	bool retorno;
	do {
		cout << "\n==============MEN� PRINCIPAL===============" << endl;
		cout << "1) Insertar al incio " << endl;
		cout << "2) Insertar intermedio " << endl;
		cout << "3) Insertar al final " << endl;
		cout << "\n4) Extraer al incio " << endl;
		//cout << "5) Extraer intermedio " << endl;
		//cout << "6) Extraer al final " << endl;
		cout << "\n7) Mostrar " << endl;
		cout << "0) Salir" << endl;
		cout << "\nIngrese una opci�n: ";
		cin >> opc;

		if (opc < 4) {
			cout << "Ingrese una palabra: ";
			cin >> palabra.dato;
		}

		switch (opc)
		{
		case 1:
			prueba.insertarInicio(palabra.dato);
			break;
		case 2:
			cout << "Despu�s de qu� palabra: ";
			cin >> aBuscar;
			retorno = prueba.insertarInter(aBuscar, palabra.dato);
			if (retorno == false) {
				cout << "No se encontr� la palabra. Insertado al final";
			}
			else {
				cout << "Insertado correctamente." << endl;
			}
			break;
		case 3:
			prueba.insertarFinal(palabra.dato);
			break;
		case 4:
			retornoE = prueba.extraerInicio();
			if (retornoE == "") {
				cout << "Lista vac�a, NO se extrajo ning�n elemento" << endl;
			}
			else {
				cout << "Se extrajo '" << retornoE << "' " << endl;
			}

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			prueba.mostrarInicioFin();
			break;
		case 0:

			break;
		default:
			break;
		}

	} while (opc != 0);
	return 0;
}