#pragma once
#include <iostream>
#define TAM 100

using namespace std;

struct Empleado {
	string nombre;
	float estatura;
	float sueldoSemanal;
};

class Empresa
{
public:
	Empresa();
	~Empresa();
	void mostrarArreglo();
	void ordenar();
	int insertar(Empleado x);
	int borrar(string nombre);

private:
	Empleado empleados[TAM]{
		{"Roberto", 1.76, 20000},
		{"Julia", 1.64, 23000},
		{"Alberto", 1.87, 30000},
		{"Carlos", 1.62, 21000},
		{"Bruno", 1.70, 25000},
		{"Alejandra", 1.82, 27000}
	};
	int ocupados;
};

