#include "Tienda.h"

int main() {
	Tienda laUnica;

	bool codigo;

	setlocale(LC_ALL, "");

	cout << "\nArreglo vacio: " << endl;
	laUnica.mostrar();
	cout << "\nArreglo poblado: " << endl;
	codigo = laUnica.poblar();
	if (!codigo) { //codigo --> código = true
		cout << "\nAguas, se llenó el arreglo" << endl;
	}
	else {
		cout << "\n\tOK. Se pobló el arreglo. " << endl;
	}
	cout << "\nArreglo con información: " << endl;
	laUnica.mostrar();

	cout << "\nArreglo ordenado: " << endl;
	laUnica.ordenar();
	laUnica.mostrar();
	return 0;
}