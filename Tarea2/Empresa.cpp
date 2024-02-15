#include "Empresa.h"

Empresa::Empresa()
{
	ocupados = 6;
}

Empresa::~Empresa()
{
}

void Empresa::mostrarArreglo()
{
	cout << "\n========EMPLEADOS======= " << endl;
	for (int i = 0; i < ocupados; i++) {
		cout << "\t" << empleados[i].nombre
			<< "\t\t" << empleados[i].estatura
			<< "\t" << empleados[i].sueldoSemanal << endl;
	}
}


void Empresa::ordenar()
{
	Empleado temp;
	for (int i = 0; i < ocupados - 1; i++) {
		for (int j = 0; j < ocupados - i - 1; j++) {
			if (empleados[j].nombre > empleados[j + 1].nombre) {
				temp = empleados[j];
				empleados[j] = empleados[j + 1];
				empleados[j + 1] = temp;
			}
		}
	}
}

int Empresa::insertar(Empleado persona)
{
	int pos = ocupados;
	//Revisar que haya cupo disponible
	if (pos >= TAM) {
		return -1; //No hay cupo
	}

	//Localizar la posición
	for (int i = 0; i < ocupados; i++) {
		if (persona.nombre == empleados[i].nombre) {
			return -2; //Ya existe
		}
		if (persona.nombre < empleados[i].nombre) {
			pos = i;
			break;
		}
	}
	//Desplazar a la derecha
	for (int i = ocupados; i > pos; i--) {
		empleados[i] = empleados[i - 1];
	}

	//Insertar
	empleados[pos] = persona;
	ocupados++;
	return 0;
}

int Empresa::borrar(string nombre)
{
	//Inicializar
	int pos = -1;

	//Localizar posición
	for (int i = 0; i < ocupados; i++) {
		if (nombre == empleados[i].nombre) {
			//Lo encontró
			pos = i;
			break;
		}
	}
	//Si no existe, terminar
	if (pos == -1) {
		return -1;
	}
	//Desplazar desde la posición
	for (int i = pos; i < ocupados - 1; i++) {
		empleados[i] = empleados[i + 1];
		//Actualizar contador de ocupados
		ocupados--;
		return 0;
	}
}


