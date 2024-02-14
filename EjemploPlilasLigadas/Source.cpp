#include "PilaDinamica.h"

int main() {
	PilaDinamica enteros;
	enteros.mostrar();

	enteros.insertar(24);
	enteros.insertar(39);
	enteros.insertar(43);

	enteros.mostrar();


	int opc, nuevo;
	do {
		cout << "\n===============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Consultar" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl << endl;

		cout << "Ingrese una opción: ";
		cin >> opc;

		if (opc == 0) {
			cout << "Hasta pronto :)" << endl;
		}
		
		switch (opc)
		{
		case 1:
			cout << "Ingrese un entero a insertar: ";
			cin >> nuevo;
			enteros.insertar(nuevo);
			cout << "Entero insertado" << endl << endl;
			break;
		case 2:
			int retorno;
			retorno = enteros.extraer();
			if (retorno == -1) {
				cout << "Pila vacía, no se extrajo ningún elemento" << endl;
			}
			else {
				cout << "Se extrajo el entero correctamente " << endl;
			}
			break;
		case 3:
			int retorno3;
			retorno3 = enteros.consultar();
			if (retorno3 == -1) {
				cout << "Pila vacía, no se extrajo ningún elemento" << endl;
			}
			else {
				cout << "Próximo a extraer: " << retorno3 << endl;
			}
			break;
		case 4:
			enteros.mostrar();
			break;
		default:
			break;
		}

	} while (opc != 0);

}