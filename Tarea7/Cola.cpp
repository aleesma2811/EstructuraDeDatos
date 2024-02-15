#include "Cola.h"

Cola::Cola()
{
    setlocale(LC_ALL, "");
    min = 0;
    max = TAM - 1;
    principio = final = -1;

    for (int i = 0; i < TAM; i++) {
        boletos[i].posBoleto = i + 1;
        boletos[i].nombre = "-";
        boletos[i].nBoleto = 0;
    }
}

Cola::~Cola()
{
}

int Cola::registrar(Comprador nuevo)
{
    /*Pila llena*/
    if (principio == min && final == max) {
        return -1;
    }
    if ((final + 1) == principio) {
        return -1;
    }

    /*Incrementar final*/
    final++;

    /*Incrementar principio por primera vez*/
    if (principio == -1) {
        principio++;
    }

    boletos[final].nombre = nuevo.nombre;
    boletos[final].nBoleto = nuevo.nBoleto;

    //Si el boleto registrado es múltiplo de 5, comprador se gana un vale
    if (boletos[final].posBoleto % 5 == 0) {
        return 1; 
    }

    return 0;
}

int Cola::extraer()
{
    int extraido;

    /*Pila vacía*/
    if (principio < min && final < min) {
        return -1;
    }

    /*Extraer*/
    extraido = boletos[principio].nBoleto;
    boletos[principio].nombre = "-";
    boletos[principio].nBoleto = 0;

    /*Incrementar principio*/
    if (final == principio) {
        return extraido;
    }
    principio++;
    if (principio > max) {
        principio = min = -1; //Se extrajo el último elemento
    }
    return extraido;
}

void Cola::mostrar()
{
    cout << "\n-------------COLA DE BOLETOS--------------" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\t" << boletos[i].posBoleto
            << "\t" << boletos[i].nombre
            << "\t" << boletos[i].nBoleto;
        if (i == min) cout << "\t <- Mínimo";
        if (i == max) cout << "\t <- Máximo";
        if (i == principio) cout << "\t <- Principio";
        if (i == final) cout << "\t <- Final";
        cout << endl;
    }
}
