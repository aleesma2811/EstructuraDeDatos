#include "Pilas.h"

Pilas::Pilas()
{
	setlocale(LC_ALL, "");
	min = 0;
	max = TAM - 1;
	tope = -1;

	for (int i = 0; i < TAM; i++) {
		pantallas[i] = { "-" };
	}
}

Pilas::~Pilas()
{
}

int Pilas::extraer()
{
	Pantallas extraido;
	if (tope < min) {
		return -1;
	}
	extraido = pantallas[tope];
	pantallas[tope] = { "-" };

	tope--;
	
	return 0;
}

int Pilas::insertar(Pantallas nuevo)
{
	if (tope >= max) {
		return -1;
	}
	tope++;
	pantallas[tope] = nuevo;
	return 0;
}

void Pilas::mostrar()
{
	for (int i = max; i >= min; i--) {
		cout << "\t" << pantallas[i].modelo;
		if (i == min) cout << "\t <-- Mínimo";
		if (i == max) cout << "\t <-- Máximo";
		if (i == tope) cout << "\t <-- Tope";
		cout << endl;
	}
}
