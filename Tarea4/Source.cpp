#include "Pilas.h"

int main() {
	Pilas pilaOriginal, pilaDepurada;
	int opc, nuevo, retorno, menor, extraido;
	do {
		cout << "\n===============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Depurar" << endl;
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
			cout << "Ingrese el número a insertar: ";
			cin >> nuevo;
			retorno = pilaOriginal.insertarOriginal(nuevo);

			if (retorno == -1) {
				cout << "La pila está llena. NO se insertó el elemento" << endl;
			}
			else {
				cout << "Elemento ingresado " << endl;
			}
			break;
		case 2:
			retorno = pilaOriginal.extraerOriginal();
			if (retorno == -1) {
				cout << "Pila vacía. NO se extrajo ningún elemento" << endl;
			}
			else {
				cout << "Elemento extraido. " << endl;
			}
			break;
		case 3:
			cout << "Ingrese el elemento 'menor': ";
			cin >> menor;
			do {
				//Extraer todos los enteros de pilaOriginal hasta que quede vacía
				extraido = pilaOriginal.extraerOriginal();
				if (extraido >= menor) {
					pilaDepurada.insertarOriginal(extraido);
				}
			} while (extraido != -1);
			
		case 4:
			cout << "\n-------PILA ORIGINAL--------" << endl;
			pilaOriginal.mostrar();
			cout << "\n-------PILA DEPURADA--------" << endl;
			pilaDepurada.mostrar();
			break;
		default:
			break;
		}

	} while (opc != 0);
	return 0;
}