#pragma once
#include <iostream>

using namespace std;

struct Empleados {
	string nombre;
	int aniosAnt;
	int cantPiezas[3];
};

class Registro
{
public:
	Registro();
	~Registro();
	void registrar();
	void ordenar();
	void mostrar();

private:
	//Arreglo empleado
	Empleados* empleado;
	//Cantidad de empleados
	int n;
};

