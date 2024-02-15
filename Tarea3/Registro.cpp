#include "Registro.h"

Registro::Registro() 
{
	setlocale(LC_ALL, "");
	cout << "Ingrese la cantidad de empleados de la fábrica: ";
	cin >> n;

	empleado = new Empleados[n];

}

Registro::~Registro()
{
	delete[]empleado;
}

void Registro::registrar()
{
	for (int i = 0; i < n; i++) {
		cout << "EMPLEADO " << i + 1 << endl;
		cout << "\tNombre: ";
		cin >> (empleado + i)->nombre;
		cout << "\tAños de antigüedad: ";
		cin >> (empleado + i)->aniosAnt;
		for (int j = 0; j < 3; j++) {
			cout << "\tPiezas fabricadas en el mes " << j + 1 << ": ";
			cin >> (empleado + i)->cantPiezas[j];
		}
	}
}

void Registro::ordenar()
{
	bool ordenado = false;
	Empleados aux; 
	do {
		for (int i = 0; i < n - 1; i++) {
			if ((empleado + i)->aniosAnt > (empleado + i + 1)->aniosAnt) {
				aux = *(empleado + i);
				*(empleado + i) = *(empleado + i + 1);
				*(empleado + i + 1) = aux;
			}
			else {
				ordenado = true;
			}
		}
	} while (!ordenado);
}

void Registro::mostrar()
{
	cout << "\nNOMBRE\tAÑOS ANT\tMES 1\tMES 2\tMES 3" << endl;
	for (int i = 0; i < n; i++) {
		cout << (empleado + i)->nombre
			<< "\t" << (empleado + i)->aniosAnt
			<< "\t" << (empleado + i)->cantPiezas[0]
			<< "\t" << (empleado + i)->cantPiezas[1]
			<< "\t" << (empleado + i)->cantPiezas[2] << endl;
	}
}
