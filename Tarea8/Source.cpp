#include "Central.h"

int main() {
	int opc;
	string nuevaPlaca, nuevoProducto, trailerExtraido;
	Central trailer;
	do {
		cout << "\n=============MENÚ PRINCIPAL==============" << endl;
		cout << "1) Insertar" << endl;
		cout << "2) Extraer" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\n\tIngrese la placa del trailer: ";
			cin >> nuevaPlaca;
			cout << "\nIngrese el producto: ";
			cin >> nuevoProducto;

			trailer.llegada(nuevaPlaca, nuevoProducto);

			break;
		case 2:
			trailerExtraido = trailer.extraer();
			if (trailerExtraido == "") {
				cout << "\nCola vacía, NO se descargó ningún trailer" << endl;
			}
			else {
				cout << "\nTrailer " << trailerExtraido << " descargado " << endl;
			}

			break;
		case 3:
			trailer.mostrar();
			break;
		case 0:
			cout << "¡Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}
	} while (opc != 0);

	return 0;
}