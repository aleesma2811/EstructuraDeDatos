#include "Ejemplo.h"

using namespace std;

void main() {
	Ejemplo objeto1;
	int a, b;

	cout << "Ingrese un entero: ";
	cin >> a;
	cout << "Ingrese otro entero: ";
	cin >> b;
	cout << "La suma es " << objeto1.sumar(a, b) << endl;

	objeto1.mostrar();
}