#include "Tienda.h"

int main() {
	Tienda laUnica;

	bool codigo;

	setlocale(LC_ALL, "");

	cout << "\nArreglo vacio: " << endl;
	laUnica.mostrar();
	cout << "\nArreglo poblado: " << endl;
	codigo = laUnica.poblar();
	if (!codigo) { //codigo --> c�digo = true
		cout << "\nAguas, se llen� el arreglo" << endl;
	}
	else {
		cout << "\n\tOK. Se pobl� el arreglo. " << endl;
	}
	cout << "\nArreglo con informaci�n: " << endl;
	laUnica.mostrar();

	cout << "\nArreglo ordenado: " << endl;
	laUnica.ordenar();
	laUnica.mostrar();
	return 0;
}