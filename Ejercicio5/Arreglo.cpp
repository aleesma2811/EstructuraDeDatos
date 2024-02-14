#include "Arreglo.h"

Arreglo::Arreglo()
{
	setlocale(LC_ALL, "");
	cout << "Ingrese el número de renglones del arreglo: ";
	cin >> renglon;
	cout << "Ingrese el número de columnas del arreglo: ";
	cin >> columna;

	//Crear el arreglo bidimensional
	val = new int*[renglon];
	for (int i = 0; i < renglon; i++) { //Para cada renglón, estamos creando las columnas
		*(val + i) = new int[columna];
	}
}

Arreglo::~Arreglo()
{
}

void Arreglo::leerNombre()
{
	cout << "\nNombre: ";
	cin.ignore();
	getline(cin, nombre);
}

void Arreglo::mostrar()
{
	cout << "\n" << nombre << ", tu arreglo es: " << endl;
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			cout << "\t" << *(*(val + i) + j);
		}
		cout << endl;
	}

}

void Arreglo::ordenar()
{
	bool ordenado = false;
	int itera = 0;
	int aux;
	//Empezar método de la burbuja en el renglón
	for (int i = 0; i < renglon; i++) {
		while (!ordenado) {
			ordenado = true;
			//Llegar a la posición a través de columnas
			for (int j = 0; j < columna - 1; j++) {
				//Accedemos a los valores a través de la dirección de memoria
				if (*(*(val + i) + j) > *(*(val + i) + j + 1)) {
					aux = *(*(val + i) + j);
					*(*(val + i) + j) = *(*(val + i) + j + 1);
					*(*(val + i) + j + 1) = aux;
					ordenado = true;
				}
			}
		}
	}
}

void Arreglo::insertar()
{
	for (int i = 0; i < renglon; i++) {
		cout << "\nRenglón " << i << ": " << endl;
		for (int j = 0; j < columna; j++) {
			cout << "\nColumna " << j << ": " << endl;
			cin >> *(*(val + i) + j); //Guardar el dato en esa posición
		}
	}
}
