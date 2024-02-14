#include "Tienda.h"

Tienda::Tienda()
{
	//Constructor da valor a los objetos
	ocupados = 0;
}

Tienda::~Tienda()
{
}

void Tienda::mostrar()
{
	cout << "\nSUCURSALES: " << endl;
	for (int i = 0; i < ocupados; i++) {
		cout << "\t" << sucs[i].numSucursal
			<< "\t" << sucs[i].nombreGerente
			<< "\t" << sucs[i].ventas[0]
			<< "\t" << sucs[i].ventas[1] << endl;
	}
	cout << endl;
}

void Tienda::ordenar()
{
	bool ordenado = false; //false = desordenado   true = ordenado
	Sucursal aux;
	int itera = 0;
	while (!ordenado) {
		ordenado = true;
		for (int i = 0; i < ocupados - 1 - itera; i++) { //Se llega hasta el 5 para compararlo con el 6
			if (sucs[i].numSucursal > sucs[i + 1].numSucursal) {
				aux = sucs[i];
				sucs[i] = sucs[i + 1];
				sucs[i + 1] = aux;
				ordenado = false;
			}
		}
		itera++;
	}
}

bool Tienda::poblar()
{
	int numS;
	if (ocupados >= TAM) {
		//El arreglo está lleno, NO cabe 
		return false; 
	}
	do {
		cout << "Número de sucursal (999) para terminar: ";
		cin >> numS;
		if (numS != 999) {
			cin.ignore();
			sucs[ocupados].numSucursal = numS;
			cout << "Nombre del gerente: ";
			getline(cin,sucs[ocupados].nombreGerente); //Toma la "basura" de cin
			cout << "Ventas de este mes: ";
			cin >> sucs[ocupados].ventas[0];
			cout << "Ventas del mes anterior: ";
			cin >> sucs[ocupados].ventas[1];

			ocupados++;
		}
	} while (numS != 999 && ocupados < TAM);
	return true;
}
