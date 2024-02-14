#include "Lista.h"

int main() {
	Lista palabras;
	string nuevaPalabra, palabraAnterior, extraida, aExtraer;
	int opc, retorno;

	do {
		cout << "\n==============MEN� PRINCIPAL===============" << endl;
		cout << "1) Insertar al incio " << endl;
		cout << "2) Insertar intermedio " << endl;
		cout << "3) Insertar al final " << endl;
		cout << "\n4) Extraer al incio " << endl;
		cout << "5) Extraer intermedio " << endl;
		cout << "6) Extraer al final " << endl;
		cout << "\n7) Mostrar " << endl;
		cout << "0) Salir" << endl;
		cout << "\nIngrese una opci�n: ";
		cin >> opc;

		if (opc >= 1 && opc <= 3) {
			cout << "Ingrese una palabra: ";
			cin >> nuevaPalabra;
		}

		switch (opc)
		{
		// Insertar al inicio
		case 1:
			palabras.insertarPrincipio(nuevaPalabra);
			cout << "Palabra insertada al inicio" << endl;
			break;

		// Insertar en medio
		case 2:			
			cout << "Despu�s de qu� palabra: ";
			cin >> palabraAnterior;

			retorno = palabras.insertarMedio(nuevaPalabra, palabraAnterior);

			if (retorno == -1) {
				cout << "Cola vac�a, se insert� al inicio del examen" << endl;
			}
			if (retorno == -2) {
				cout << "No se encontr� la palabra anterior. Se insert� al final" << endl;
			}
			else {
				cout << "Palabra ingresada despu�s de " << palabraAnterior << endl;
			}
			break;

		// Insertar al final
		case 3:
			retorno = palabras.insertarFinal(nuevaPalabra);
			if (retorno == -1) {
				cout << "Cola vac�a, se insert� al inicio del examen" << endl;
			}
			else {
				cout << "Palabra insertada al final " << endl;
			}
			break;

		// Extraer al principio
		case 4:
			extraida = palabras.extraerPrincipio();
			if (extraida == "") {
				cout << "Lista vac�a. NO se extrajo ning�n elemento" << endl;
			}
			else {
				cout << "Se extrajo '" << extraida << "' del inicio" << endl;
			}
			break;

		// Extraer intermedio
		case 5:
			cout << "Ingrese la palabra a extraer: ";
			cin >> aExtraer;
			extraida = palabras.extraerMedio(aExtraer);
			if (extraida == "") {
				cout << "Lista vac�a. NO se extrajo ning�n elemento" << endl;
			}
			else if (extraida == "NO") {
				cout << "NO se encontr� el elemento" << endl;
			}
			else {
				cout << "Extrayendo '" << extraida << "'" << endl;
			}
			break;

		// Extraer al final
		case 6:
			extraida = palabras.extraerFinal();
			if (extraida == "") {
				cout << "Lista vac�a. NO se extrajo ning�n elemento" << endl;
			}
			else {
				cout << "Se extrajo '" << extraida << "' del final" << endl;
			}
			break;
		case 7:
			cout << "\n-------------Lista----------------" << endl;
			palabras.mostrar();
			break;
		case 0:

			break;
		default:
			break;
		}

	} while (opc != 0);
	
	return 0;
}