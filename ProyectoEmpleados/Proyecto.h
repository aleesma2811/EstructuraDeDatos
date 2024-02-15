#pragma once
#include <iostream>

using namespace std;

struct Premiacion {
    string nombreEmpleado;
    string regalo;
    Premiacion* sig;
};

struct Regalo {
    string regalo;
    Regalo* anterior, * sig;
};

struct Empleado {
    string nombre;
    //bool participa; //Si participa o no 
    //string regalo;
    Empleado* sig;
};

class Proyecto {
public:
    Proyecto();
    ~Proyecto();

    void registrar(Empleado); // Cola para registrar empleados
    int almacenar(Regalo); // Pila para donar regalo
    Regalo sacarRegalo(); // Extraer pila de regalos de la bodega
    Empleado seleccionarEmpleado(); // Extraer cola de empleados participantes
    int premiar(string, string); // Premiar a los empleados (empleado, regalo)
    string buscar(string);
    void mostrarEmpleados(); 
    void mostrarRegalos(); // Pila para mostrar
    void mostrarPremiacion(); // Mostrar empleados con respectivos regalos
    int contarEmpleados(); // COntar empleados
    int contarRegalos();


private:
    Empleado* empleado, * principio, * final, * nodo;
    Regalo* nodoR, * tope;
    Premiacion* nodoP, * principioP, *finalP;
};