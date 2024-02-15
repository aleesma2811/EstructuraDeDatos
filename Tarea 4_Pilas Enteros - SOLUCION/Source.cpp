#include "Pila.h"

void main()
{
	setlocale(LC_ALL, "");

	int cap, opc, nuevo, extraido, menor;

	cout << "\n Dí la capacidad de la Pila: ";
	cin >> cap;

	Pila original(cap);
	Pila depurada(cap);

	do
	{
		cout << "\n1 Insertar   2 Extraer   3 Mostrar   4 Depurar   5 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\nEntero que insertarás: ";
			cin >> nuevo;
			original.Insertar(nuevo);
			break;
		case 2:
			extraido = original.Extraer();
			if (extraido > -1)
				cout << "\tOK. Se extrajo " << extraido << endl;
			break;
		case 3:
			cout << "\nORIGINAL:" << endl;
			original.Mostrar();
			cout << "\nDEPURADA:" << endl;
			depurada.Mostrar();
			break;
		case 4:
			cout << "\nEntero menor para conservar: ";
			cin >> menor;
			cout << "\n\t ... depurando ..." << endl;
			do
			{
				extraido = original.Extraer();
				if (extraido >= menor)
					depurada.Insertar(extraido);
			} while (extraido != -1);
			cout << "\n\t OK. Terminó depuración" << endl << endl;
		case 5:
			break;
		default:
			cout << "\n\tERROR, opción inválida" << endl;
			break;
		}
	} while (opc != 5);
	cout << endl;
}