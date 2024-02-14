#include "Arreglo.h"

Arreglo::Arreglo()
{
}

Arreglo::~Arreglo()
{
}

int Arreglo::borrar(int aBorrar)
{
    int pos = -1;
    //1. Localizar posici�n
    for (int i = 0; i < ocupados; i++) {
        if (aBorrar == enteros[i]) {
            pos = i;
            break;
        }
    }
    //2. Si no existe terminar
    if (pos == -1) {
        //No existe
        return -1;
    }
    //3. Desplazar
    for (int i = pos; i < ocupados - 1; i++) {
        enteros[i] = enteros[i + 1];
    }
    //4. Colocar cero al �ltimo
    enteros[ocupados - 1] = 0;
    //5. Actualizar el n�mero de ocupados
    ocupados--;

    return 0;
}

int Arreglo::insertar(int aInsertar)
{
    int pos = ocupados;
    //1. Revisar que haya capacidad disponible
    if (ocupados >= TAM) {
        //Arreglo lleno, no se insert�
        return -2;
    }
    //2. Localizar la posici�n para insertar
    for (int j = 0; j < ocupados; j++) {
        if (aInsertar == enteros[j]) {
            //Ya existe, no se inserta
            return -1;
        }

        if (aInsertar < enteros[j]) {
            pos = j;
            break;
        }
    }
    //3. Desplazar a la derecha 
    for (int j = ocupados - 1; j >= pos; j--) {
        enteros[j + 1] = enteros[j];
    }
    //4. Insertar el nuevo n�mero en la posici�n localizada
    enteros[pos] = aInsertar;
    //5. Incrementar ocupados
    ocupados++;;
    return 0;
}

void Arreglo::mostrar()
{
    cout << "ARREGLO: ";
    for (int i = 0; i < TAM; i++) {
        cout << "\t" << enteros[i];
    }
    cout << endl;

}
