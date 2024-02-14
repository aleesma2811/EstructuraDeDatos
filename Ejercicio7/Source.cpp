#include "Pilas.h"

int main()
{
	Pilas empleado(7);
	Empleado nuevoEmpleado;

	string nombre;
	int clave, retorno, opc;
	float sueldo;
	do {
		cout << "\n===============Menú principal=================" << endl;
		cout << "1) Contratar" << endl;
		cout << "2) Desocupar" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			
			cout << "\tIngrese el nombre del empleado: ";
			cin >> nombre;
			cout << "\tIngrese la clave del empleado: ";
			cin >> clave;
			cout << "\tIngrese el sueldo del empleado: ";
			cin >> sueldo;

			nuevoEmpleado.nombre = nombre;
			nuevoEmpleado.clave = clave;
			nuevoEmpleado.sueldo = sueldo;

			retorno = empleado.contratar(nuevoEmpleado);

			if (retorno == -1) {
				cout << "Pila llena" << endl;
			}
			else {
				cout << "Empleado agregado" << endl;
			}

			break;
		case 2:
			retorno = empleado.desocupar();
			if (retorno == -1) {
				cout << "Pila vacía" << endl;
			}
			else {
				cout << "Empleado desocupado" << endl;
			}

			break;
		case 3:
			cout << "\n-----------Empleados-----------" << endl;
			empleado.mostrar();
			break;
		case 0:
			cout << "Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}

	} while (opc != 0);
	return 0;
}