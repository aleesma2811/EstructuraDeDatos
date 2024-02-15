#include "Lista.h"

int main() {
	int opc, retorno;
	Lista lista;
	Nombre nombrecito;
	do {
		cout << "\n==============MENÚ PRINCIPAL===============" << endl;
		cout << "1) Insertar al incio " << endl;
		cout << "2) Insertar al final " << endl;
		cout << "3) Extraer impares " << endl;
		cout << "4) Obtener número de nodos " << endl;
		cout << "\n5) Mostrar " << endl;
		cout << "0) Salir" << endl;
		cout << "\nIngrese una opción: ";
		cin >> opc;

		if (opc == 1 || opc == 2) {
			cout << "Ingrese el nombre a insertar: ";
			cin >> nombrecito.nombre;
		}

		switch (opc)
		{
		case 1:
			lista.insertarInicio(nombrecito);
			cout << "Nombre insertado" << endl;
			break;
		case 2:
			retorno = lista.insertarFinal(nombrecito);
			if (retorno == -1) {
				cout << "Lista vacía. Se insertó al inicio " << endl;
			}
			else {
				cout << "Nombre insertado al final" << endl;
			}
			break;
		case 3:
			lista.extraerIntermedio();
			cout << "Se extrajo " << endl;
			break;
		case 4:
			retorno = lista.contarNodos();
			cout << "Actualmente hay " << retorno << " nodos en la lista" << endl;
			break;
		case 5:
			lista.mostrar();
			break;
		case 0:

			break;
		default:
			break;
		}

	} while (opc != 0);
	return 0;
}