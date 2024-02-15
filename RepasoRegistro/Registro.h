#pragma once
#include <iostream>
#define TAM 100

using namespace std;

struct Empleado {
	string nombre;
	float estatura;
	float sueldo;
};

class Registro
{
public:
	Registro();
	~Registro();

	void llenarArreglo();
	void mostrarArreglo();
	void ordenar();
	void insertar();
	void borrar();

private:
	Empleado empleado[TAM];
};



