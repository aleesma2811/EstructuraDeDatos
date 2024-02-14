#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada()
{
	cabecera = final = nodo = NULL;
}

void ListaEnlazada::InsertarInicio(string nueva)
{
	/* Paso 1: Crear nodo nuevo */
	nodo = new Palabra;
	/* Paso 2: Llenar el campo de información */
	nodo->dato = nueva;
	/* Paso 3: Llenar el campo de enlace */
	nodo->sig = cabecera;
	/* Apuntar cabecera al nuevo nodo */
	cabecera = nodo;
	if (final == NULL)	// Solo en la primera inserción
		final = nodo;
}

int ListaEnlazada::InsertarInter(string nueva, string anterior)
{
	Palabra* nodoAnterior;
	bool encontrado = false;  // false=NO encontrado

	if (!cabecera)
	{
		InsertarInicio(nueva);
		return -1;		// Lista vacía. Se insertó al inicio
	}
	nodoAnterior = cabecera;
	
	while (nodoAnterior != final)
	{
		if (nodoAnterior->dato == anterior)
		{
			encontrado = true;	// Palabra encontrada
			nodo = new Palabra; /* Paso 2: Crear */
			nodo->dato = nueva; /* Paso 3: Información */
			nodo->sig = nodoAnterior->sig; /* Paso 4: Enlace */
			nodoAnterior->sig = nodo; /* Paso 5: Enlace de nodo anterior */
			if (nodoAnterior == final)
				final = nodo;	// Solo si anterior es el último nodo
			return 0;	// Se insertó correctamente
		}
		nodoAnterior = nodoAnterior->sig;
	}
	if (encontrado == false)
	{
		InsertarFinal(nueva);
		return -2;		// No se encontró nodo anterior. Se inserta al final
	}

	return 0;
}

int ListaEnlazada::InsertarFinal(string nueva)
{
	if (!cabecera)
	{
		InsertarInicio(nueva);
		return -1;	// Lista VACÍA. Se insertó al principio
	}
	/* Paso 1: Crear nuevo nodo */
	nodo = new Palabra;
	/* Paso 2: Llenar el campo de información */
	nodo->dato = nueva;
	/* paso 3: Apuntar a NULL el campo de enlace */
	nodo->sig = NULL;
	/* Paso 4: Apunta campo de enlace final a nuevo nodo */
	final->sig = nodo;
	final = nodo;
	return 0;	// Se insertó correctamente al final
}

string ListaEnlazada::ExtraerInicio()
{
	string extraida;

	if (cabecera == NULL)
		return "";		// La lista está vacía. No se extrae nada

	/* Paso 1: Localizar nodo señalado por cabecera */
	nodo = cabecera;
	/* paso 2: Tomar información del nodo a extraer */
	extraida = nodo->dato;
	/* paso 3: Apuntar cabecer al siguiente nodo */
	if (final == cabecera)
		final = NULL;
	cabecera = nodo->sig;
	/* Paso 4: Liberar nodo extraido */
	delete nodo;

	return extraida;
}

string ListaEnlazada::ExtraerFinal()
{
	string extraida;
	Palabra *nodoAnterior;
	if (cabecera == NULL)
		return "";	// Fila vacía. No se extrae nada
	if (cabecera == final)
	{
		extraida = ExtraerInicio();
		return extraida;	// Si es el único nodo en la lista ocupamos extraerInicio
	}
	/* Paso 1: Localizar el nodo final y su anterior */
	nodoAnterior = NULL;
	nodo = cabecera;
	while (nodo != final)
	{
		nodoAnterior = nodo;
		nodo = nodo->sig;
	}
	/* Paso 2: Tomar información del nodo a extraer */
	extraida = nodo->dato;
	/* Paso 3: Apuntar a NULL el enlace de nodo Anterior */
	nodoAnterior->sig = NULL;
	/* Paso 4: Apuntar la variable 'final' a nodoAnterior */
	final = nodoAnterior;
	/* Paso 5: Eliminar el nodo extraido */
	delete nodo;

	return extraida;
}

string ListaEnlazada::ExtraerIntermedio(string aExtraer)
{
	string extraida;
	Palabra* nodoAnterior;
	bool encontrada = false;	// false = NO encontrada

	if (cabecera == NULL)
		return "";		// Lista vacía. NO se extrae nada

	/* Paso 1: Localizar el nodo a extraer */
	nodoAnterior = NULL;
	nodo = cabecera;

	while (nodo != NULL)
	{
		if (nodo->dato == aExtraer)
		{
			encontrada = true;	// Se encontró la palabra
			break;
		}
		nodoAnterior = nodo;
		nodo = nodo->sig;
	}
	/* Paso 2: Tomar información del nodo a extraer */
	if (encontrada == false)
		return "NO";	// No se encontró la palabra. NO se extrae
	extraida = nodo->dato;
	/* Paso 3: Apuntar el enlace de nodoAnterior al siguiente del extraido */
	if (nodo == cabecera)	// En caso de extraer el nodo de la cabecera
		cabecera = nodo->sig;
	else
		nodoAnterior->sig = nodo->sig; // caso de nodo intermedio

	if (nodo == final)
		final = nodoAnterior;	// En caso de extraer el nodo del final
	/* Paso 4: Liberar el nodo extraido */
	delete nodo;

	return extraida;
}

void ListaEnlazada::Mostrar()
{
	cout << "\nLISTA DE PALABRAS:\n" << endl;
	if (!cabecera)
	{
		cout << "\n\tLista VACÍA" << endl;
		return;
	}
	nodo = cabecera;
	while (nodo)
	{
		cout << "\t" << nodo->dato;
		if (nodo == cabecera) cout << "\t<= Cabecera";
		if (nodo == final) cout << "\t<= Final";
		cout << endl;

		nodo = nodo->sig;
	}
}
