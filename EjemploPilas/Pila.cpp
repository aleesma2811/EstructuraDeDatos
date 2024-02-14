#include "Pila.h"

Pila::Pila(int n)
{
	setlocale(LC_ALL, "");
	pilaEnteros = new int[n];
	min = 0;
	max = n - 1;
	tope = -1; //Si tope = 0, ya está en la cima

	for (int i = 0; i <= max; i++) {
		//Crear un array de 0's
		pilaEnteros[i] = 0;
	}
}

Pila::~Pila()
{
}

//POP
int Pila::extraer()
{
	//
	int extraido;

	//1) Verificar que haya elementos en la pila
	if (tope < min) {
		//La pila está vacía
		return -1;
	}

	//2) Extraer valor (tope)
	extraido = pilaEnteros[tope];
	pilaEnteros[tope] = 0;

	//3) Decrementar valor tope
	tope--;
	return extraido;
}

//PUSH
int Pila::insertar(int nuevo)
{
	//1) Verificar que haya espacio disponible
	if (tope >= max) {
		//La pila está llena
		return -1;
	}
	//2) Incrementar tope
	tope++;
	//3) Insertar nuevo valor
	pilaEnteros[tope] = nuevo;
	return 0;
}

//PEEK
int Pila::consultar()
{
	//1) Verificar si hay valores en la pila
	if (tope >= max) {
		//La pila está llena
		return -1;
	}

	//2) Mostrar el valor señalado por tope
	return pilaEnteros[tope];
}

void Pila::mostrar()
{
	cout << "ARREGLO " << endl;
	/**/
	for (int i = max; i >= min; i--) {
		cout << "\t" << *(pilaEnteros + i);
		if (i == min) cout << "\t<- Mínimo";
		if (i == max) cout << "\t<- Máximo";
		if (i == tope) cout << "\t<- Tope";
		cout << endl;
	}
}
