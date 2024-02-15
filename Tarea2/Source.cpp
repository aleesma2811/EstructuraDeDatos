#include "Empresa.h"

int main() {
	string nombre;
	Empleado persona;
	int codigo, respuesta;
	int opc;
	bool ordenado = false;
	Empresa prueba;

	prueba.mostrarArreglo();
	

	do {
		cout << "1. Ordenar" << endl;
		cout << "2. Insertar" << endl;
		cout << "3. Borrar" << endl;
		cout << "4. Mostrar" << endl;
		cout << "0. Salir" << endl;
		cout << "Escoge: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			prueba.ordenar();
			prueba.mostrarArreglo();
			ordenado = true;
			break;
		case 2:
			if (ordenado) {
				cout << "... ingresar ..." << endl;
				cout << "\tNombre: ";
				cin >> persona.nombre;
				cout << "\tEstatura: ";
				cin >> persona.estatura;
				cout << "\tSueldo: ";
				cin >> persona.sueldoSemanal;

				respuesta = prueba.insertar(persona);
			}
			else {
				cout << "Primero debe de ordenar el array" << endl;
			}
			break;
			
		case 3:
			cout << "\nIngrese el nombre a borrar: ";
			cin >> nombre;

			prueba.borrar(nombre);
			prueba.mostrarArreglo();
			break;

		case 4:
			prueba.mostrarArreglo();
			break;
		case 0:
			break;
		}
	} while (opc != 0);

	return 0;
}