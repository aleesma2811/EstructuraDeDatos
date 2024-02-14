#include "Arreglo.cpp"
#include <iostream>

int main() {
  Pila miPila;
  miPila.Mostrar();

  int opc, retornoI;
  Pantalla retornoP;

  do {
    cout << "\n1. Insertar 2. Extraeer 3. Consultar 4. Mostrar 5. Salir"
         << endl;
    cin >> opc;

    string modeloPantalla;
    switch (opc) {
    case 1:
      cout << "\nEscribe el modelo de pantalla a insertar (Secuencia de 1 "
              "letra seguida de digitos): \n";
      cin >> modeloPantalla;
      retornoI = miPila.Insertar({modeloPantalla});
      if (retornoI == -1) {
        cout << "\n\tPila llena. NO SE INSERTÓ" << endl;
      } else {
        cout << "\n\tOK. Se insertó correctamente" << endl;
      }
      break;
    case 2:
      retornoP = miPila.Extraer();
      if (retornoP.modelo == "-1") {
        cout << "\n\tPila vacía. NO SE EXTRAJO" << endl;
      } else {
        cout << "\n\tOK. Se extrajo el entero: " << retornoP.modelo << endl;
      }
      break;
    case 3:
      retornoP = miPila.Consultar();
      if (retornoP.modelo == "-1") {
        cout << "\n\tPila vacía. NO SE CONSULTÓ" << endl;
      } else {
        cout << "\n\tOK. Se consultó el entero: " << retornoP.modelo << endl;
      }
      break;
    case 4:
      miPila.Mostrar();
      break;
    case 5:
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 5);

  return 0;
}
