#include "Cola.h"

int main() {
	Cola concierto;
	Comprador nuevo;
	int opc, retorno;


	do {
		cout << "\n=============MEN� PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:

			cout << "Nombre del comprador: ";
			cin >> nuevo.nombre;
			cout << "No. del boleto: ";
			cin >> nuevo.nBoleto;

			retorno = concierto.registrar(nuevo);
			//Pila llena
			if (retorno == -1) {
				cout << "Pila llena. NO se insert� el boleto" << endl;
			}
			//Boleto ingresado es m�ltiplo de 5
			if (retorno == 1) {
				cout << "\t�El boleto No." << nuevo.nBoleto << " del comprador '" << nuevo.nombre << "' ha ganado un vale de 50% de descuento en su siguiente compra de boleto!" << endl;
			}
			else { //Boleto ingresado a la fila
				cout << "Boleto registrado. " << endl;
			}
			concierto.mostrar();
			break;
		case 2:
			retorno = concierto.extraer();
			//Pila vac�a
			if (retorno == -1) {
				cout << "Pila vac�a. NO se elimin� ning�n boleto" << endl;
			}
			else { //Se extrae el boleto
				cout << "Boleto No." << retorno << " extra�do" << endl;
			}
			concierto.mostrar();
			break;
		case 3:
			//Imprimir cola
			concierto.mostrar();
			break;
		case 0:
			cout << "\n�Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}
	} while (opc != 0);

	return 0;
}