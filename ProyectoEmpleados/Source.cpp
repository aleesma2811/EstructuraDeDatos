#include "Proyecto.h"

int main() {
    // Cola de empleados - pila de regalos - lista de premiación
    Proyecto registro, bodegaRegalos, premiacion;

    string regaloObtenido;
    Empleado retornoE, empleado, seleccionado;
    Regalo regalo, retornoR;
    Premiacion nombre, regaloFinal;
    int opc, contRegalos, contEmpleados;

    do {
        cout << "\n================ MENÚ PRINCIPAL =======================" << endl;
        cout << "1 Registrar empleado" << endl;
        cout << "2 Donar regalo" << endl;
        cout << "3 Premiar" << endl;
        cout << "\n4 Mostrar empleados y bodega" << endl;
        cout << "5 Mostrar premiación " << endl;
        cout << "\n6 Supervisar " << endl;
        cout << "\n0 Salir" << endl;
        cout << "Ingrese una opción: ";
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
            // Contar número de empleados registrados y número de regalos en bodega
            contEmpleados = registro.contarEmpleados();
            contRegalos = bodegaRegalos.contarRegalos();
            
            // Si hay mas empleados que regalos
            if (contEmpleados > contRegalos) {
                // Se indica cuantos regalos faltan para sean el mismo número de empleados y regalos
                cout << "\tHacen falta " << contEmpleados - contRegalos << " regalos para que se lleve a cabo la premiación. " << endl;
            }

            // Si hay la misma cantidad de empleados y regalos o si hay más regalos que empleados
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
                cout << "\n~~~~~~~~~~~ PREMIACIÓN ~~~~~~~~~~~~~~" << endl;
                premiacion.mostrarPremiacion();
            }
            break;

        // Mostrar Empleados registrados y bodega
        case 4:

            registro.mostrarEmpleados();

            bodegaRegalos.mostrarRegalos();

            break;

        // Mostrar la premiación total
        case 5:
            cout << "\n~~~~~~~~~~~ PREMIACIÓN ~~~~~~~~~~~~~~" << endl;
            premiacion.mostrarPremiacion();
            break;

        // Supervisar un empleado en particular
        case 6:
            cout << "\nPara realizar la supervisión de la entrega de regalos, ingrese el nombre del empleado para verificar su regalo: ";
            cin >> empleado.nombre;

            // Buscar el empleado ingresado
            regaloObtenido = premiacion.buscar(empleado.nombre);

            // Si no se encontró el empleaod
            if (regaloObtenido == "") {
                cout << "No se encontró el empleado " << endl;
            }
            // Si se encuentra el empleado
            else {
                // Indicar regalo obtenido del empleado
                cout << "\tEl empleado '" << empleado.nombre << "' obtuvo un/una " << regaloObtenido << " de regalo " << endl;
            }
            
            break;

        case 0:
            cout << "\t¡Hasta pronto! :)" << endl;
            break;

        default:
            break;
        }

    } while (opc != 0);

    return 0;
}