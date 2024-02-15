#include "Lista.h"

int main() {
	Lista numeros;
	Numeros n;
	int opc, num, retorno;

	do {

		cout << "\n==============MENÚ PRINCIPAL===============" << endl;
		cout << "1) Insertar  " << endl;
		cout << "\n2) Mostrar " << endl;

		cout << "0) Salir" << endl;

		cout << "\nIngrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Ingrese un número: ";
			cin >> num;
			retorno = numeros.insertarIntermedio(num);
			if (retorno == -1) {
				cout << "PRUEBA lista vacía, se insertó al inicio" << endl;
			}
			else {
				cout << "Número insertado" << endl;
			}
			break;
		case 2:
			cout << "----------NÚMEROS-----------" << endl;
			numeros.mostrar();
			break;
		case 0:

			break;
		default:
			break;
		}
	} while (opc != 0);

	return 0;
}