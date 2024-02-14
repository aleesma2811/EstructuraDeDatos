#include "CCircular.h"

int main() {
	int n;
	cout << "Ingrese el tama�o del arreglo: ";
	cin >> n;

	CCircular C(n);
	string palabra, consulta;
	int opc, retorno;

	do {
		cout << "\n=============MEN� PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "4) Consultar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			//Insertar nueva palabra
			cout << "Ingrese la palabra a insertar: ";
			cin >> palabra;
			retorno = C.insertar(palabra);

			//Pila llena, no se inserta elemento
			if (retorno == -1) {
				cout << "\tCola llena, NO se insert� la palabra" << endl;
			}
			//Palabra insertada
			else {
				cout << "\tPalabra insertada" << endl;
			}
			break;
		case 2:
			retorno = C.extraer();
			//Pila vac�a, no se inserta la palabra
			if (retorno == -1) {
				cout << "Pila vac�a" << endl;
			}
			break;
		case 3:
			C.mostrar();
			break;
		case 4:
			consulta = C.consultar();
			if (consulta == " ") {
				cout << "Pila vac�a" << endl;
			}
			else{
				cout << "Pr�ximo a extraer: " << consulta << endl;
			}
			break;
		case 0:

			break;
		default:
			break;
		}

	} while (opc != 0);
	

	return 0;
}


		/*
		
		*/