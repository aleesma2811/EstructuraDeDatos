#include "ListaEnlazada.h"

void main()
{
	setlocale(LC_ALL, "");
	ListaEnlazada Palabras;
	int opc, retorno;
	string nvaPalabra, palabraAnterior, extraida, aExtraer;

	do
	{
		cout << "\n1 Insertar Inicio  2 Insertar Final"
			<< "  3 Insertar Intermedio" << endl
			<< "4 Extraer Inicio   5 Extraer Final" 
			<< "   6 Extraer Intermedio  7 Mostrar  8 Salir: ";
		cin >> opc;

		if (opc < 4)
		{
			cout << "\tPalabra que insertar�s: ";
			cin >> nvaPalabra;
		}
		switch (opc)
		{
		case 1:
			Palabras.InsertarInicio(nvaPalabra);
			cout << "\tOK. Se insert� al inicio" << endl;
			break;
		case 2:
			retorno = Palabras.InsertarFinal(nvaPalabra);
			if (retorno == -1)
				cout << "\tLista VAC�A. Se insert� al inicio" << endl;
			else
				cout << "\tOK. Se insert� correctamente al final" << endl;
			break;
		case 3:
			cout << "\tDesp�es de que palabra: ";
			cin >> palabraAnterior;
			retorno = Palabras.InsertarInter(nvaPalabra, palabraAnterior);
			if (retorno == -1)
				cout << "\tLista VAC�A, se insert� al inicio" << endl;
			else if (retorno == -2)
				cout << "\tNO se encontr� '" << palabraAnterior << "', se insert� al final" << endl;
			else
				cout << "\tOK. Se insert� correctamente, despu�s de '" << palabraAnterior << "'" << endl;
			break;
		case 4:
			extraida = Palabras.ExtraerInicio();
			if (extraida == "")
				cout << "\tLista VAC�A, NO se extrajo nada" << endl;
			else
				cout << "\tOK.Se extrajo '" << extraida
					<< "' del inicio" << endl;
			break;
		case 5:
			extraida = Palabras.ExtraerFinal();
			if (extraida == "")
				cout << "\tLista VAC�A, NO se extrajo nada" << endl;
			else
				cout << "\tOK. Se extrajo '" << extraida
					<< "' del final" << endl;
			break;
		case 6:
			cout << "\tPalabra que extraer�s: ";
			cin >> aExtraer;
			extraida = Palabras.ExtraerIntermedio(aExtraer);
			if (extraida == "")
				cout << "\tLista VAC�A, no se extrajo nada" << endl;
			else if (extraida == "NO")
				cout << "\tNO se encontr� '" << aExtraer << "' NO se extrajo" << endl;
			else
				cout << "\tOK. Se extrajo '" << extraida << "'" << endl;

			break;
		case 7:
			Palabras.Mostrar();
			break;
		case 8:
			cout << "\n\n\t\t\t--- FINAL DE LA APLICACI�N ---\n" << endl;
			break;
		default:
			cout << "\n\tERROR, opci�n inv�lida" << endl;
			break;
		}
	} while (opc != 8);
}