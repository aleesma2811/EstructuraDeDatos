#include "MatrizAdy.h"

int main() {
	setlocale(LC_ALL, "");

	int maxNodo, opc, codigo, peso, insertado;
	char letra, origen, destino;

	cout << "Cantidad m�xima de nodos: ";
	cin >> maxNodo;
	MatrizAdy grafo(maxNodo);

	do {
		cout << "============= MEN� PRINCIPAL ===============" << endl;
		cout << "1) Insertar nodo" << endl;
		cout << "2) Insertar arco" << endl;
		cout << "3) Mostrar" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Ingrese una letra: ";
			cin >> letra;
			codigo = grafo.insertarNodo(letra);
			if (codigo == 0) {
				cout << "\tNodo insertado" << endl;
			} if (codigo == -1) {
				cout << "\tArreglo lleno. NO se insert� el nodo" << endl;
			} if (codigo == -2) {
				cout << "El nodo ya existe. NO se insert� el nodo" << endl;
			}
			break;
		case 2:
			cout << "\nIngrese una letra de origen: ";
			cin >> origen;
			cout << "Ingrese una letra de destino: ";
			cin >> destino;
			cout << "Ingrese el peso del arco: ";
			cin >> peso;

			codigo = grafo.insertarArco(origen, destino, peso);

			if (codigo == 0) {
				cout << "\tSe insert� el arco" << endl;
			} 
			if (codigo == -1) {
				cout << "\tGrafo vac�o. NO se insert� el arco" << endl;
			}
			if (codigo == -2) {
				cout << "\tNo existe el nodo de origen o de destino. NO se insert� el arco. " << endl;
			}
			if (codigo == -3) {
				cout << "\tYa existe el arco. Se modific� el arco en las dos direcciones" << endl;
			}
			break;
		case 3:
			grafo.mostrar();
			break;
		case 0:
			cout << "�Hasta pronto! :)" << endl;
			break;
		default:
			break;
		}

	} while (opc != 0);

	return 0;
}