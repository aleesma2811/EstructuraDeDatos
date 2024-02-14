#pragma once
#include <iostream>
#include <string>

#define TAM 10

using namespace std;

typedef struct Pantalla {
  string modelo; // Una letra y dígitos
} Pantalla;

class Pila {

public:
  Pila();
  ~Pila();

  Pantalla Consultar();
  Pantalla Extraer(); // pop
  int Insertar(Pantalla);
  void Mostrar();

private:
  Pantalla pilaEnteros[TAM];

  int min, max, tope;

protected:
};
