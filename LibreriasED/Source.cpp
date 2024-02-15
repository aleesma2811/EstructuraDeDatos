#include "metodos.cpp"

int main() {
	setlocale(LC_ALL, "");

	stack <int> pila; // Instancia de una pila de enteros

	int opc, num, extraido;

	do {
		cout << "\n==================================" << endl;
		cout << "1) Insertar " << endl; // Push
		cout << "2) Extraer " << endl; // Pop
		cout << "3) Tamaño " << endl;
		cout << "4) Consultar tope " << endl;
		cout << "5) Mostrar " << endl;
		cout << "0) Salir " << endl;
		cout << "Ingrese una opción: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\nIngrese el entero a insertar: ";
			cin >> num;
			pila.push(num); // Insertar entero a la cola
			cout << "\tEntero insertado" << endl;
			break;
		case 2:
			if (pila.empty()) {
				cout << "\tPila vacía, no se extrajo ningún elemento" << endl;
			}
			else {
				pila.pop();
				cout << "Se extrajo el elemento ";
			}
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			while (!pila.empty()) {
				cout << "\t" << pila.top() << endl;
				pila.pop(); // Eliminar para vaciar
			}
			break;
		default:
			break;
		}
	} while (opc != 0);
}