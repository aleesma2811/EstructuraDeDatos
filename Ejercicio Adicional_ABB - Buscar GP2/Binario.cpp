#include "Binario.h"

Binario::Binario()
{
	raiz = nodo = NULL;
}

Numero* Binario::ConsultarRaiz()
{
	return raiz;
}

Numero* Binario::Buscar(Numero* inicio, int buscado)
{
	Numero* encontrado;

	if (buscado == inicio->num)	/* Igual. Se encontró en la raiz */
	{
		cout << "\tOK. Se encontró el " << buscado << endl;
		return inicio;
	}
	if (buscado < inicio->num)	/* Menor. Buscar en sub-arbol izquierdo */
	{
		if (inicio->Izq != NULL)
		{
			encontrado = Buscar(inicio->Izq, buscado);
			return encontrado;
		}
		else
		{
			cout << "\tNo existe " << buscado << endl;
			return NULL;
		}
	}
	if (buscado > inicio->num)	/* Mayor. Buscar en sub-arbol derecho */
	{
		if (inicio->Der != NULL)
		{
			encontrado = Buscar(inicio->Der, buscado);
			return encontrado;
		}
		else
		{
			cout << "\tNo existe " << buscado << endl;
			return NULL;
		}
	}
}

void Binario::CrearNodo(int valor)
{
	nodo = new Numero;
	nodo->num = valor;
	nodo->Izq = NULL;
	nodo->Der = NULL;
}

void Binario::Insertar(Numero* inicio)
{
	if (!raiz)	/* Arbol vacío. Se insertará en la raiz */
	{
		raiz = nodo;
		cout << "\tSe insertó en la raiz" << endl;
		return;
	}

	if (nodo->num < inicio->num)	/* Menor, se insertará a la izquierda */
	{
		if (inicio->Izq == NULL)
		{
			inicio->Izq = nodo;
			cout << "\tSe insertó a la izquierda de " << inicio->num << endl;
			return;
		}
		else
		{
			Insertar(inicio->Izq);
			return;
		}
	}

	if (nodo->num > inicio->num)	/* Mayor, se insertará a la derecha */
	{
		if (inicio->Der == NULL)
		{
			inicio->Der = nodo;
			cout << "\tSe insertó a la derecha de " << inicio->num << endl;
			return;
		}
		else
		{
			Insertar(inicio->Der);
			return;
		}
	}
	/* Si es igual, NO se insertará */
	cout << "\tYA existe " << nodo->num << " en el árbol. NO se insertará" << endl;
	delete nodo;
}

void Binario::Mostrar(Numero* inicio, int contador)
{
	if (inicio == NULL)
		return;
	Mostrar(inicio->Der, contador + 1);
	for (int i = 0; i < contador; i++)
		cout << "\t";
	cout << inicio->num << endl;
	Mostrar(inicio->Izq, contador + 1);
}

void Binario::Recorrer_INorden(Numero* inicio)
{
	if (inicio->Izq != NULL) Recorrer_INorden(inicio->Izq);
	cout << "\t" << inicio->num;
	if (inicio->Der != NULL) Recorrer_INorden(inicio->Der);
}

void Binario::Recorrer_PREorden(Numero* inicio)
{
	cout << "\t" << inicio->num;
	if (inicio->Izq != NULL) Recorrer_PREorden(inicio->Izq);
	if (inicio->Der != NULL) Recorrer_PREorden(inicio->Der);
}

void Binario::Recorrer_POSorden(Numero* inicio)
{
	if (inicio->Izq != NULL) Recorrer_POSorden(inicio->Izq);
	if (inicio->Der != NULL) Recorrer_POSorden(inicio->Der);
	cout << "\t" << inicio->num;
}