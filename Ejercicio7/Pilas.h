#pragma once
#include <iostream>

using namespace std; 

struct Empleado {
	string nombre = "";
	int clave = 0;
	float sueldo = 0.0;
};

class Pilas
{
public:
	Pilas(int n);
	~Pilas();

	//Push
	int contratar(Empleado);
	//Pop
	int desocupar();
	void mostrar();

private:
	int n, min, max, tope;
	Empleado* empleados;
};

