#include "Pila.h"

int main() {
	Pila pila(10);
	int opc, nuevo, retorno;
	do {
		cout << "\n===============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Consultar" << endl;
		cout << "4) Mostrar" << endl;
		cout << "0) Salir" << endl << endl;

		cout << "Ingrese una opción: ";
		cin >> opc;

		if (opc == 0) {
			cout << "¡Hasta pronto! :)" << endl;
		}

		switch (opc)
		{
		case 1:
			cout << "Ingrese el númweo a insertar: ";
			cin >> nuevo;
			retorno = pila.insertar(nuevo);
			if (retorno == -1) {
				cout << "La pila está llena, nose insertó" << endl;
			}
			else {
				cout << "Elemento insertado... " << endl;
			}
			break;
		case 2:
			retorno = pila.extraer();
			if (retorno == -1) {
				cout << "Pila vacía, no se extrajo nada " << endl;
			}
			else {
				cout << "Elemento extraido..." << endl;
			}
			break;
		case 3:
			retorno = pila.consultar();
			if (retorno == -1) {
				cout << "Pila vacía " << endl;
			}
			else {
				cout << "Próximo a extraer : " << retorno << endl;
			}
			break;
		case 4:
			pila.mostrar();
			break;
		default:
			break;
		}

	} while (opc != 0);
	return 0;
}