#include "Tienda.h"

Tienda::Tienda()
{
	ocupados = 0;
}

Tienda::~Tienda()
{
}

void Tienda::mostrar()
{
	cout << "\t" << sucs[ocupados].numSucursal
		<< "\t" << sucs[ocupados].nombreGerente
		<< "\t" << sucs[ocupados].ventas[0]
		<< "\t" << sucs[ocupados].ventas[1] << endl;
}

void Tienda::ordenar()
{
}

void Tienda::poblar()
{
	int nSucursal = 0;
	cout << "----------INGRESAR DATOS-----------" << endl;
	do {
		cout << "Número de sucursal (999 para terminar): ";
		cin >> nSucursal;
		if (nSucursal != 999) {
			sucs[ocupados].numSucursal = nSucursal;
			cout << "Nombre del gerente: ";
			cin >> sucs[ocupados].nombreGerente;
			cout << "Ventas de este mes: ";
			cin >> sucs[ocupados].ventas[0];
			cout << "Ventas del mes anterior: ";
			cin >> sucs[ocupados].ventas[1];

			ocupados++;
		}
	} while (nSucursal != 999);
}
