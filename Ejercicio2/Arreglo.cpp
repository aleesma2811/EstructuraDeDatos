#include "Arreglo.h"

Arreglo::Arreglo()
{
}

Arreglo::~Arreglo()
{
}

int Arreglo::insertar(int aInsertar)
{
    int pos = ocupados;
    //1. Revisar que haya capacidad disponible
    if (ocupados >= TAM) {
        //Arreglo lleno, no se insertó
        return -2;
    }
    //2. Localizar la posición para insertar
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
    //4. Insertar el nuevo número en la posición localizada
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
