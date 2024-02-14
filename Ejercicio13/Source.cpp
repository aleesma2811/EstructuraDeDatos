#include "Supermercado.h"

int main() {
	Supermercado C20, C25, D10;
	string nuevoTurno = "", retornoC20 = "", retornoC25 = "";
	int opc, opcC, retornoCaja;
	do {
		cout << "\n=============MEN� PRINCIPAL==============" << endl;
		cout << "1) Formar" << endl;
		cout << "2) Pagar " << endl;
		cout << "3) Bloquear C20 y C25" << endl;
		cout << "4) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			//Ingresar turno del cliente
			cout << "Ingrese el turno del cliente (AA00): ";
			cin >> nuevoTurno;
			//Ingresar caja a formarse
			cout << "Ingrese la caja en la que se formar� el cliente: " << endl;
			retornoCaja = C20.escogerCaja();
			if (retornoCaja == 1) {
				//Escogi� C20
				C20.formar(nuevoTurno);
				cout << "Cliente formado en C20" << endl;
			}
			else {
				//Escogi� C25
				C25.formar(nuevoTurno);
				cout << "Cliente formado en C25" << endl;
			}
			break;

		case 2:
			//Escoger caja pr�xima a pagar
			cout << "Ingrese la caja pr�xima a pagar: " << endl;
			retornoCaja = C20.escogerCaja();
			if (retornoCaja == 1) {
				//CLiente en C20 paga
				C20.pagar();
				cout << "Cliente de la caja C20 ha pagado" << endl;
			}
			else {
				//CLiente en C25 paga
				C25.pagar();
				cout << "Cliente de la caja C25 ha pagado" << endl;
			}

			break;
		case 3:
			//Ingresar de manera intercalada
			do {
				//Extraer en C20 y verificar que C20 no est� vac�a antes de insertar (para no insertar espacios vac�os)
				retornoC20 = C20.pagar();
				if (retornoC20 != "") {
					//Insertar en D10
					D10.formar(retornoC20);
				}

				//Extraer en C25 y verificar que C25 no est� vac�a antes de insertar
				retornoC25 = C25.pagar();
				if(retornoC25 != ""){
					D10.formar(retornoC25);
				}				
			//Si una caja se vac�a, termina el intercalado
			} while (retornoC20 != "" || retornoC25 != "");

			//Ingresar elementos restantes de la cola sobrante
			do {
				//C20 est� vac�a, extraer de C25 e insertar a D10
				if (retornoC20 == "") {
					do {
						retornoC25 = C25.pagar();
						if (retornoC25 != "") {
							D10.formar(retornoC25);
						}
					} while (retornoC25 != "");
				}
				else { //C25 est� vac�a, extraer de C20 e insertar a D10
					do {
						retornoC20 = C20.pagar();
						if (retornoC20 != "") {
							D10.formar(retornoC20);
						}
					} while (retornoC20 != "");
				}
			} while (retornoC20 != "" && retornoC25 != "");
			break;

		case 4:
			cout << "\n--------- C20 ----------" << endl;
			//Mostrar caja C20
			C20.mostrar();
			cout << "\n--------- C25 ----------" << endl;
			//Mostrar caja C25
			C25.mostrar();
			cout << "\n--------- D10 ----------" << endl;
			//Mostrar caja C25
			D10.mostrar();
			break;

		case 0:
			cout << "�Hasta pronto! :)";
			break;
		default:
			break;
		}

	} while (opc != 0);
}