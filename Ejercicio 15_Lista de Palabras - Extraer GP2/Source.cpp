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
			cout << "\tPalabra que insertarás: ";
			cin >> nvaPalabra;
		}
		switch (opc)
		{
		case 1:
			Palabras.InsertarInicio(nvaPalabra);
			cout << "\tOK. Se insertó al inicio" << endl;
			break;
		case 2:
			retorno = Palabras.InsertarFinal(nvaPalabra);
			if (retorno == -1)
				cout << "\tLista VACÍA. Se insertó al inicio" << endl;
			else
				cout << "\tOK. Se insertó correctamente al final" << endl;
			break;
		case 3:
			cout << "\tDespúes de que palabra: ";
			cin >> palabraAnterior;
			retorno = Palabras.InsertarInter(nvaPalabra, palabraAnterior);
			if (retorno == -1)
				cout << "\tLista VACÍA, se insertó al inicio" << endl;
			else if (retorno == -2)
				cout << "\tNO se encontró '" << palabraAnterior << "', se insertó al final" << endl;
			else
				cout << "\tOK. Se insertó correctamente, después de '" << palabraAnterior << "'" << endl;
			break;
		case 4:
			extraida = Palabras.ExtraerInicio();
			if (extraida == "")
				cout << "\tLista VACÍA, NO se extrajo nada" << endl;
			else
				cout << "\tOK.Se extrajo '" << extraida
					<< "' del inicio" << endl;
			break;
		case 5:
			extraida = Palabras.ExtraerFinal();
			if (extraida == "")
				cout << "\tLista VACÍA, NO se extrajo nada" << endl;
			else
				cout << "\tOK. Se extrajo '" << extraida
					<< "' del final" << endl;
			break;
		case 6:
			cout << "\tPalabra que extraerás: ";
			cin >> aExtraer;
			extraida = Palabras.ExtraerIntermedio(aExtraer);
			if (extraida == "")
				cout << "\tLista VACÍA, no se extrajo nada" << endl;
			else if (extraida == "NO")
				cout << "\tNO se encontró '" << aExtraer << "' NO se extrajo" << endl;
			else
				cout << "\tOK. Se extrajo '" << extraida << "'" << endl;

			break;
		case 7:
			Palabras.Mostrar();
			break;
		case 8:
			cout << "\n\n\t\t\t--- FINAL DE LA APLICACIÓN ---\n" << endl;
			break;
		default:
			cout << "\n\tERROR, opción inválida" << endl;
			break;
		}
	} while (opc != 8);
}