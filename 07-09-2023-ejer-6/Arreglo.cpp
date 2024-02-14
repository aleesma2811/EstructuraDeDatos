#include "Arreglo.h"
#include <cstdio>
#include <iostream>

Pila::~Pila() {}

Pila::Pila() {
  min = 0;
  max = TAM - 1;
  tope = -1;

  for (int i = 0; i <= max; i++) {
    pilaEnteros[i] = {""};
  }
}

Pantalla Pila::Consultar() {
  if (tope < min) {
    return {"-1"};
  }
  // mostrar el valor señalado por el tope
  return pilaEnteros[tope];
}

Pantalla Pila::Extraer() {

  // verificar que hayan valores en la pila
  if (tope < min) {
    return {"-1"}; // está vacía, no se extrae nada
  }
  // extraer valor en el tope
  Pantalla extraido = pilaEnteros[tope];
  pilaEnteros[tope] = {""};
  tope--; // decrementar el valor de tope
  return extraido;
}

int Pila::Insertar(Pantalla nuevaPantalla) {
  if (tope >= max) {
    return -1;
  }
  tope++;
  pilaEnteros[tope] = nuevaPantalla;
  return 0;
}

void Pila::Mostrar() {
  cout << "Pila: " << endl;

  for (int i = max; i >= 0; i--) {
    if (pilaEnteros[i].modelo.empty() == true) {
      cout << "\t\"\"";
    } else {
      cout << "\t" << pilaEnteros[i].modelo;
    }
    if (i == min) {
      cout << "\t<= Mínimo";
    }
    if (i == max) {
      cout << "\t<=Máximo";
    }
    if (i == tope) {
      cout << "\t<= Tope";
    }
    cout << endl;
  }
}
