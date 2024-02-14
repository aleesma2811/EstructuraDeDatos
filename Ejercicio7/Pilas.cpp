#include "Pilas.h"

Pilas::Pilas(int n)
{

	setlocale(LC_ALL, "");
	empleados = new Empleado[n];
	min = 0;
	max = n - 1;
	tope = -1;

	for (int i = 0; i < n; i++) {
		empleados[i].nombre = "-";
		empleados[i].clave = 0;
		empleados[i].sueldo = 0.0;
	}
}

Pilas::~Pilas()
{
}

int Pilas::contratar(Empleado nuevo)
{
	if (tope >= max) {
		//Pila llena
		return -1;
	}
	tope++;
	//Agregar empleado
	empleados[tope] = nuevo;
	return 0;
}

int Pilas::desocupar()
{
	Empleado extraido;
	if (tope < min) {
		//Pila vacia
		return -1;
	}
	//Seleccionar ultimo elemento
	extraido = empleados[tope];
	//"Vaciar" posición
	empleados[tope].nombre = "-";
	empleados[tope].clave = 0;
	empleados[tope].sueldo = 0.0;
	tope--;
	return 0;
}

void Pilas::mostrar()
{
	for (int i = max; i >= min; i--) {
		cout << "\t" << empleados[i].nombre
			<< "\t" << empleados[i].clave
			<< "\t" << empleados[i].sueldo;
		if (i == min) cout << "\t\t <-- Mínimo";
		if (i == max) cout << "\t\t <-- Máximo";
		if (i == tope) cout << "\t\t <-- Tope";
		cout << endl;
	}
}
