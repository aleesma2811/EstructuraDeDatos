#include "Proyecto.h"

int main() {
    // Cola de empleados - pila de regalos - lista de premiaci�n
    Proyecto registro, bodegaRegalos, premiacion;

    string regaloObtenido;
    Empleado retornoE, empleado, seleccionado;
    Regalo regalo, retornoR;
    Premiacion nombre, regaloFinal;
    int opc, contRegalos, contEmpleados;

    do {
        cout << "\n================ MEN� PRINCIPAL =======================" << endl;
        cout << "1 Registrar empleado" << endl;
        cout << "2 Donar regalo" << endl;
        cout << "3 Premiar" << endl;
        cout << "\n4 Mostrar empleados y bodega" << endl;
        cout << "5 Mostrar premiaci�n " << endl;
        cout << "\n6 Supervisar " << endl;
        cout << "\n0 Salir" << endl;
        cout << "Ingrese una opci�n: ";
        cin >> opc;

        switch (opc)
        {

        // Registrar empleados
        case 1:
            // Ingresar datos del empleado
            cout << "\nIngrese el nombre del empleado: ";
            cin >> empleado.nombre;

            // Insertar empleado a la cola
            registro.registrar(empleado);
            cout << "\tParticipante '" << empleado.nombre << "' registrado" << endl;

            break;

        // Proveedor dona regalo
        case 2:
            cout << "\nIngrese el regalo a donar por el proveedor: ";
            // Ingresar regalo
            cin >> regalo.regalo;

            // Insertar regalo en la bodega
            bodegaRegalos.almacenar(regalo);
            cout << "\tRegalo '" << regalo.regalo << "' almacenado " << endl;
            break;

        // Repartir regalos
        case 3:
            // Contar n�mero de empleados registrados y n�mero de regalos en bodega
            contEmpleados = registro.contarEmpleados();
            contRegalos = bodegaRegalos.contarRegalos();
            
            // Si hay mas empleados que regalos
            if (contEmpleados > contRegalos) {
                // Se indica cuantos regalos faltan para sean el mismo n�mero de empleados y regalos
                cout << "\tHacen falta " << contEmpleados - contRegalos << " regalos para que se lleve a cabo la premiaci�n. " << endl;
            }

            // Si hay la misma cantidad de empleados y regalos o si hay m�s regalos que empleados
            else { 
                while (contEmpleados > 0 && contRegalos > 0) {

                    // Seleccionar empleado
                    retornoE = registro.seleccionarEmpleado();

                    // Sacar Regalo del almacen
                    retornoR = bodegaRegalos.sacarRegalo();

                    // Dar regalo al empleado
                    premiacion.premiar(retornoE.nombre, retornoR.regalo);

                    contEmpleados--;
                    contRegalos--;
                }
                cout << "\n~~~~~~~~~~~ PREMIACI�N ~~~~~~~~~~~~~~" << endl;
                premiacion.mostrarPremiacion();
            }
            break;

        // Mostrar Empleados registrados y bodega
        case 4:

            registro.mostrarEmpleados();

            bodegaRegalos.mostrarRegalos();

            break;

        // Mostrar la premiaci�n total
        case 5:
            cout << "\n~~~~~~~~~~~ PREMIACI�N ~~~~~~~~~~~~~~" << endl;
            premiacion.mostrarPremiacion();
            break;

        // Supervisar un empleado en particular
        case 6:
            cout << "\nPara realizar la supervisi�n de la entrega de regalos, ingrese el nombre del empleado para verificar su regalo: ";
            cin >> empleado.nombre;

            // Buscar el empleado ingresado
            regaloObtenido = premiacion.buscar(empleado.nombre);

            // Si no se encontr� el empleaod
            if (regaloObtenido == "") {
                cout << "No se encontr� el empleado " << endl;
            }
            // Si se encuentra el empleado
            else {
                // Indicar regalo obtenido del empleado
                cout << "\tEl empleado '" << empleado.nombre << "' obtuvo un/una " << regaloObtenido << " de regalo " << endl;
            }
            
            break;

        case 0:
            cout << "\t�Hasta pronto! :)" << endl;
            break;

        default:
            break;
        }

    } while (opc != 0);

    return 0;
}