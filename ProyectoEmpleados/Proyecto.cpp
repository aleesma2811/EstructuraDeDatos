#include "Proyecto.h"

Proyecto::Proyecto()
{
	setlocale(LC_ALL, "");
}

Proyecto::~Proyecto()
{
}

// Registrar empleados
void Proyecto::registrar(Empleado registrado)
{
	nodo = new Empleado;

	nodo->nombre = registrado.nombre;

	nodo->sig = NULL;

	if (principio == NULL) {
		principio = nodo;
	}
	if (final != NULL) {
		final->sig = nodo;
	}
	final = nodo;
}

// Donar y almacenar regalos en la bodega (insertar pila)
int Proyecto::almacenar(Regalo regaloEmpleado)
{
	nodoR = new Regalo;
	nodoR->regalo = regaloEmpleado.regalo;
	nodoR->anterior = tope;
	tope = nodoR;
	return 0;
}

// Repartir regalos (extraer pila)
Regalo Proyecto::sacarRegalo()
{
	Regalo* extraido;
	Regalo regalo, vacio; // ?

	vacio.regalo = "";

	if (tope == NULL) {
		return vacio;
	}

	extraido = tope;
	tope = tope->anterior;
	regalo.regalo = extraido->regalo;

	delete extraido;

	return regalo; // Extraer último regalo almacenado
}

// Seleccionar participantes de la cola (extraer cola)
Empleado Proyecto::seleccionarEmpleado()
{
	Empleado empleado1, vacia; // Primer empleado de la cola
	vacia.nombre = "";

	if (principio == NULL) {
		return vacia;
	}

	nodo = principio;
	empleado1.nombre = nodo->nombre;
	principio = nodo->sig;

	if (principio == NULL) {
		final = NULL;
	}

	delete nodo;
	return empleado1; // Devuelve el primer empleado formado a recibir su regalo
}

// Repartir regalos (insertar lista)
int Proyecto::premiar(string empleado, string regalo)
{
	nodoP = new Premiacion;
	nodoP->nombreEmpleado = empleado;
	nodoP->regalo = regalo;
	nodoP->sig = nullptr;

	if (!principioP) {
		principioP = finalP = nodoP; 
	}
	else {
		finalP->sig = nodoP; 
		finalP = nodoP; 
	}

	return 0;
}

// Buscar empleado con regalo
string Proyecto::buscar(string nombre)
{
	if (principioP == NULL) {
		return "";
	}
	nodoP = principioP;

	while (nodoP != NULL) {
		if (nodoP->nombreEmpleado == nombre) {
			return nodoP->regalo;
		}
		nodoP = nodoP->sig;
	}
	return "Empleado no encontrado en la premiación";
}

// Mostrar cola de empleados registrados
void Proyecto::mostrarEmpleados()
{
	cout << "\n--------- Empleados ---------" << endl;

	if (principio == NULL) {
		cout << "\n\t...cola vacía..." << endl;
		return;
	}
	nodo = principio;
	do {
		cout << "\t" << nodo->nombre;
		if (nodo == principio) cout << "\t<- 1° Empleado en la cola";
		if (nodo == final) cout << "\t<- Último empleado en la cola";
		cout << endl;

		nodo = nodo->sig;

	} while (nodo != NULL);
}

// Mostrar pila de regalos donados
void Proyecto::mostrarRegalos()
{
	cout << "\n************* Bodega *************" << endl;
	if (tope == NULL) {
		cout << "... bodega vacía..." << endl;
		return;
	}
	nodoR = tope;

	while (nodoR != NULL) {
		cout << "\t" << nodoR->regalo;
		if (nodoR == tope) cout << "\t<- Último regalo en la bodega";
		cout << endl;
		nodoR = nodoR->anterior;
	}
	cout << endl;
}

// Mostrar lista de empleados y sus respectivos regalos
void Proyecto::mostrarPremiacion()
{
	/*
	if (!principio) {
		cout << "... lista vacía ..." << endl;
	}
	*/
	
	nodoP = principioP;

	cout << "\t" << "Empleado"
		<< "\t" << "Regalo" << endl;

	while (nodoP) {
		cout << "\t" << nodoP->nombreEmpleado
			<< "\t" << nodoP->regalo;
		if (nodoP == principioP) cout << "\t<- Principio";
		if (nodoP == finalP) cout << "\t<- Final";
		cout << endl;

		nodoP = nodoP->sig;
	}
}

// Contar número de empleados registrados
int Proyecto::contarEmpleados()
{
	int contador = 0;
	nodo = principio;

	while (nodo != NULL) {
		contador++;
		nodo = nodo->sig;
	}
	return contador; // Devuelve número de empleados
}

// Contar número de regalos donados
int Proyecto::contarRegalos()
{
	int contador = 0;
	nodoR = tope;

	while (nodoR != NULL) {
		contador++;
		nodoR = nodoR->anterior;
	}
	return contador; // Devuelve número de regalos
}
