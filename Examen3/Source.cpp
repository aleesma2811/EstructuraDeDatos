#include "Caminos.h"

int main() {
	Caminos cliente, rechazados;
	Motocicleta moto, retorno;
	string marca;
	int opc, nCilindros, respuesta;

	do {
		cout << "\n==============MENÚ PRINCIPAL================" << endl;
		cout << "1) Ingresar moto " << endl;
		cout << "2) Pagar moto " << endl;
		cout << "3) Mostrar motocicletas " << endl;
		cout << "0) Salir " << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		//Insertar moto
		case 1:
			//Ingresar datos
			cout << "Ingrese la marca de la moto: ";
			cin >> moto.marca;
			cout << "Ingrese el número de cilindros de la moto: ";
			cin >> moto.nCilindros;

			//Insertar moto
			cliente.insertar(moto);
			cout << "Motocicleta insertada" << endl;
			break;

		//Extraer motocicleta
		case 2:
			retorno = cliente.extraer();

			//Si la cola está vacía
			if (retorno.marca == "" && retorno.nCilindros == 0) {
				cout << "La cola está vacía. NO se extrajo ninguna motocicleta." << endl;
			}
			else {

				//Preguntar si el pago fue aceptado
				cout << "El pago fue aceptado? \t1. Sí \t2. No" << endl;
				cin >> respuesta;

				//Si el pago fue aceptado, se extrae motocicleta
				if (respuesta == 1) {
					cout << "Motocicleta extraida: '" << retorno.marca << "' de " << retorno.nCilindros << " cilindros" << endl;
				}

				//Si no fue aceptado, se extrae motocicleta y se inserta en Rechazados
				else {
					cout << "El pago fue rechazado. Ingresando la motocicleta '" << retorno.marca << "' de " << retorno.nCilindros << " cilindros a 'Rechazados'" << endl;
					rechazados.insertar(retorno);
				}
			}

			break;

		//Mostrar
		case 3:
			cout << "\n-----------Motocicletas-------------" << endl;
			//Cola de Motocicletas
			cliente.mostrar();

			cout << "\n-----------Rechazados-------------" << endl;
			//Cola de rechazados
			rechazados.mostrar();
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