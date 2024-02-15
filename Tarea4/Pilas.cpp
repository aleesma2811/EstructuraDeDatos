#include "Pilas.h"

Pilas::Pilas()
{
	setlocale(LC_ALL, "");
	pilaEnteros = new int[MAX];
	min = 0;
	max = MAX - 1;
	tope = -1;

	for (int i = 0; i < MAX; i++) {
		pilaEnteros[i] = 0;
	}
}

Pilas::~Pilas()
{
}

void Pilas::mostrar()
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

int Pilas::insertarOriginal(int nuevo)
{
	//1) Revisar que haya espacio
	if (tope >= max) {
		//Pila llena
		return -1;
	}
	//2 Incrementar tope
	tope++;

	//3 Insertar nuevo valor
	pilaEnteros[tope] = nuevo;
	return 0;
}

int Pilas::extraerOriginal()
{
	int extraido;
	//1 Revisar que hayan elementos en la pila
	if (tope < min) {
		//Pila vacía
		return -1;
	}

	//2 Extraer elemento
	extraido = pilaEnteros[tope];
	pilaEnteros[tope] = 0;

	//3 Decrementar tope
	tope--;
	return extraido;
}



