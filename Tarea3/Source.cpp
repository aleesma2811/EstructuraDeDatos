#include "Registro.h"

int main() {
	Registro registro;
	int opc;
	int band = 0;
	do {
		cout << "\n===============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Registrar empleados" << endl;
		cout << "2) Ordenar registro" << endl;
		cout << "3) Mostrar registro" << endl;
		cout << "0) Salir" << endl << endl;

		cout << "Ingrese una opción: ";
		cin >> opc;

		if (opc == 0) {
			cout << "Hasta pronto :)" << endl;
		}

		switch (opc)
		{
		case 1:
			registro.registrar();
			band = 1;
			break;
		case 2:
			if (band == 1) {
				cout << "Ordenando arreglo..." << endl;
				registro.ordenar();
			}
			else {
				cout << "Antes de ordenar, debe de ingresar los datos " << endl;
			}
			
			break;
		case 3:
			if (band == 1) {
				registro.mostrar();
			}
			else {
				cout << "Debe de registrar los datos antes de mostrarlos..." << endl;
			}
			break;
		default:
			break;
		}
	} while (opc != 0);
	
	
	return 0;
}
