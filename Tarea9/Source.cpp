#include "Lista.h"

int main() {
	Lista numeros;
	Numeros n;
	int opc, num, retorno;

	do {

		cout << "\n==============MEN� PRINCIPAL===============" << endl;
		cout << "1) Insertar  " << endl;
		cout << "\n2) Mostrar " << endl;

		cout << "0) Salir" << endl;

		cout << "\nIngrese una opci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Ingrese un n�mero: ";
			cin >> num;
			retorno = numeros.insertarIntermedio(num);
			if (retorno == -1) {
				cout << "PRUEBA lista vac�a, se insert� al inicio" << endl;
			}
			else {
				cout << "N�mero insertado" << endl;
			}
			break;
		case 2:
			cout << "----------N�MEROS-----------" << endl;
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