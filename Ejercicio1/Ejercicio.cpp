#include "Ejercicio.h"
#include <iostream>

using namespace std;

Ejercicio::Ejercicio()
{
    setlocale(LC_ALL, "");
}

Ejercicio::~Ejercicio()
{
}

void Ejercicio::contar1()
{
    cout << "----------Ejercicio 1---------" << endl;
    cout << "Contador de números ingresados" << endl;
    cout << "Ingrese los números deseados. Cuando termine, oprima 0." << endl;
    int n = 0;
    int cont = 0;
    do {
        cin >> n;
        if (n != 0) {
            cont += 1;
        }
    } while (n != 0);
    cout << "Cantidad de números ingresados: " << cont << endl;
}

void Ejercicio::contarParImpar()
{
    cout << "\n----------Ejercicio 2---------" << endl;
    cout << "Ingresar 9 números en total, para obtener la cantidad y suma de pares, y cantidad y suma de impares. " << endl;
    int n;
    int sumaPar = 0;
    int sumaImpar = 0;
    int contPar = 0;
    int contImpar = 0;
    for (int i = 0; i < 9; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> n;
        if (n % 2 == 0) {
            sumaPar += n;
            contPar += 1;
        }
        else {
            sumaImpar += n;
            contImpar += 1;
        }
    }
    cout << "\nSuma par: " << sumaPar << endl;
    cout << "Cantidad de números pares: " << contPar << endl;
    cout << "Suma impar: " << sumaImpar << endl;
    cout << "Cantidad de números impares: " << contImpar << endl;
}
