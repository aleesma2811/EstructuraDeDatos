#include "ColaDinamica.h"

int main() {
	string nuevaFrase, fraseExtraida;
	ColaDinamica misFrases;
	int opc;
	do {
		cout << "\n=============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "4) Consultar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Ingrese la nueva frase: ";
			cin >> nuevaFrase;
			misFrases.insertar(nuevaFrase);
			break;
		case 2:
			fraseExtraida = misFrases.extraer();
			if (fraseExtraida == " ") {
				cout << "Pila vacía" << endl;
			}
			else {
				cout << "Próximo a extraer: " << fraseExtraida << endl;
			}
			break;
		case 3:
			misFrases.mostrar();
			break;
		case 4:

			break;
		case 0:
			cout << "¡Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}

	} while (opc != 0);
}