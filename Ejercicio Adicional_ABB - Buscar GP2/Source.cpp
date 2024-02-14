#include "Binario.h"

void main()
{
	setlocale(LC_ALL, "");

	Binario arbolBB;
	int opc, valor, aBuscar;
	Numero* nodoRaiz =NULL, *encontrado=NULL;

	do
	{
		cout << "\n1 Insertar   2 In-orden   3 Pre-orden"
			<< "   4 Pos-orden   5 Mostrar   6 Buscar   7 Salir: ";
		cin >> opc;

		if(opc < 7)
			nodoRaiz = arbolBB.ConsultarRaiz();

		switch (opc)
		{
		case 1:
			cout << "\tentero que insertarás: ";
			cin >> valor;
			arbolBB.CrearNodo(valor);
			arbolBB.Insertar(nodoRaiz);
			break;
		case 2:
			if (nodoRaiz == NULL)
				cout << "\tEl árbol está vacío" << endl;
			else
				arbolBB.Recorrer_INorden(nodoRaiz);
			break;
		case 3:
			if (nodoRaiz == NULL)
				cout << "\tEl árbol está vacío" << endl;
			else
				arbolBB.Recorrer_PREorden(nodoRaiz);
			break;
		case 4:
			if (nodoRaiz == NULL)
				cout << "\tEl árbol está vacío" << endl;
			else
				arbolBB.Recorrer_POSorden(nodoRaiz);
			break;
		case 5:
			if (nodoRaiz == NULL)
				cout << "\tEl árbol está vacío" << endl;
			else
				arbolBB.Mostrar(nodoRaiz, 0);
			break;
		case 6:
			if (nodoRaiz == NULL)
				cout << "\tÁrbol vacío" << endl;
			else
			{
				cout << "\tNúmero que buscas: ";
				cin >> aBuscar;
				encontrado = arbolBB.Buscar(nodoRaiz, aBuscar);
				if (encontrado != NULL)
				{
					cout << "\tRecorrido IN-orden:" << endl;
					arbolBB.Recorrer_INorden(encontrado);
				}
			}
			break;
		case 7:
			cout << "\n\n\t\t--- FINAL DE LA APLICACIÓN ---\n" << endl;
			break;
		default:
			cout << "\n\tERROR, opción inválida" << endl;
			break;
		}
	} while (opc != 7);
}