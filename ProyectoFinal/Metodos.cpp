// Metodos.cpp

#include "Header.h"

// LISTA
// ---------------------------------------------------------------------------

ListaLigada::ListaLigada() {
    cabecera = final = NULL;
    numElementosLista = 0;
}

ListaLigada::~ListaLigada() {}

void ListaLigada::InsertarInicio(InfoBoleto nuevoDato) {
    // crear nodo nuevo
    Nodo* nodoNuevo = new Nodo{ nuevoDato, cabecera };
    cabecera = nodoNuevo;
    if (final == NULL)
        final = nodoNuevo;
    numElementosLista++;
}

int ListaLigada::InsertarInter(string despuesDeNombreComprador,
    InfoBoleto nuevoDato) {
    if (cabecera == NULL) {
        InsertarInicio(nuevoDato);
        return -1; // lista vac�a, insertar inicio
    }
    Nodo* nodo = cabecera;
    do {
        if (nodo->dato.nombreComprador == despuesDeNombreComprador) {
            nodo->sig = new Nodo{ nuevoDato, nodo->sig };
            if (nodo == final)
                final = nodo->sig;
            return 0;
        }
        nodo = nodo->sig;
    } while (nodo != NULL);
    // no se encontr�, lo insertamos al final
    InsertarFinal(nuevoDato);
    numElementosLista++;
    return -2;
}

int ListaLigada::InsertarFinal(InfoBoleto nuevoDato) {
    if (!cabecera) {
        InsertarInicio(nuevoDato);
        return -1; // lista vac�a, se insert� al principio
    }
    Nodo* nodo = new Nodo{ nuevoDato, NULL };
    final->sig = nodo;
    final = nodo;
    numElementosLista++;
    return 0; // se insert� correctamente al final
}

InfoBoleto ListaLigada::ExtraerInicio() {
    if (cabecera == NULL)
        return { "" }; // lista vac�a, no se extrae nada
    Nodo* nodoABorrar = cabecera;
    InfoBoleto valorAExtraer = nodoABorrar->dato;
    cabecera = nodoABorrar->sig;
    if (final == cabecera)
        final = NULL;
    delete nodoABorrar;
    numElementosLista--;
    return valorAExtraer;
}

InfoBoleto
ListaLigada::ExtraerIntermedio(string nombreCompradorDeBoletoAExtraer) {
    if (cabecera == NULL)
        return { "" };

    Nodo* nodoAnterior = NULL;
    Nodo* nodo = cabecera;
    bool encontrada = false; // no encontrada

    while (nodo != NULL) {
        if (nodo->dato.nombreComprador == nombreCompradorDeBoletoAExtraer) {
            encontrada = true; // se encontr� la palabra
            break;
        }
        nodoAnterior = nodo;
        nodo = nodo->sig;
    }

    if (!encontrada)
        return { "" }; // no se encontr� la palabra, no se extrae
    InfoBoleto extraida = nodo->dato;

    if (nodo == cabecera) // en caso de extraer el nodo de la cabecera
        cabecera = nodo->sig;
    else
        nodoAnterior->sig = nodo->sig;

    if (nodo == final)
        final = nodoAnterior; // en caso de extraer el nodo final
    // liberar nodo extraido
    delete nodo;
    numElementosLista--;
    return extraida;
}

InfoBoleto ListaLigada::ExtraerFinal() {
    if (cabecera == NULL)
        return { "" }; // lista vac�a, no se extrae nada
    if (final == cabecera)
        return ExtraerInicio();

    Nodo* nodoAnterior = NULL;
    Nodo* nodo = final;
    while (nodo != final) {
        nodoAnterior = nodo;
        nodo = nodo->sig;
    }
    InfoBoleto valorAExtraer = nodo->dato;
    nodoAnterior->sig = NULL;
    final = nodoAnterior;
    cabecera = nodo->sig;
    delete nodo;
    numElementosLista--;
    return valorAExtraer;
}

ListaLigada ListaLigada::BuscarPorComprador(string nombre) {
    ListaLigada listaResultado;

    Nodo* actual = cabecera;
    while (actual != nullptr) {
        if (actual->dato.nombreComprador == nombre) {
            // Agregar el nodo actual a la lista de resultados
            listaResultado.InsertarInicio(actual->dato);
        }
        actual = actual->sig;
    }
    return listaResultado;
}

void ListaLigada::Mostrar(bool mostrarSeccion) {
    cout << "\tLista:" << endl;
    if (cabecera == NULL) {
        cout << "\t\t*LISTA VAC�A*" << endl;
        return;
    }
    Nodo* nodo = cabecera;
    do {
        cout << "\t";
        mostrarValor(nodo->dato, mostrarSeccion);
        nodo = nodo->sig;
    } while (nodo != NULL);
}

double ListaLigada::CalcularPromedioDeCosto() {
    Nodo* actual = cabecera;
    double promedio = 0;
    while (actual != nullptr) {
        // printf("iteracion: %f", actual->dato.totalCompra);
        promedio += actual->dato.totalCompra;
        actual = actual->sig;
    }
    if (numElementosLista > 0)
        return promedio / numElementosLista;
    else
        return 0;
}
double ListaLigada::CalcularPromedioDeBoletosComprados() {
    Nodo* actual = cabecera;
    double promedio = 0;
    while (actual != nullptr) {
        // printf("iteracion: %i", actual->dato.cantidadBoletos);
        promedio += actual->dato.cantidadBoletos;
        actual = actual->sig;
    }
    if (numElementosLista > 0)
        return promedio / numElementosLista;
    else
        return 0;
}
int ListaLigada::CalcularSumaCantidadDeBoletosComprados() {
    Nodo* actual = cabecera;
    int suma = 0;
    while (actual != nullptr) {
        // printf("iteracion: %i", actual->dato.cantidadBoletos);
        suma += actual->dato.cantidadBoletos;
        actual = actual->sig;
    }
    return suma;
}

double ListaLigada::CalcularSumaTotalDeGasto() {
    Nodo* actual = cabecera;
    int suma = 0;
    while (actual != nullptr) {
        // printf("iteracion: %f", actual->dato.totalCompra);
        suma += actual->dato.totalCompra;
        actual = actual->sig;
    }
    return suma;
}

void ListaLigada::CopiarDatosASegundaLista(ListaLigada& segundaLista) { // Copia para qu�
    Nodo* actual = this->cabecera;
    while (actual != nullptr) {
        segundaLista.InsertarInicio(actual->dato);
        actual = actual->sig;
    }
}

void mostrarValor(InfoBoleto valor, bool mostrarSeccion) {
    // Mostrar la lista de boletos vendidos en la secci�n especificada
    cout << "\tNo. de Tarjeta: " << valor.numTarjeta
        << "\tNombre: " << valor.nombreComprador
        << "\tCantidad de Boletos: " << valor.cantidadBoletos
        << "\tTotal de Compra: $" << valor.totalCompra;
    if (mostrarSeccion)
        cout << "\tSeccion: " << valor.seccion;
    cout << "\n";
}

// SECCION
// ---------------------------------------------------------------------------

Seccion::Seccion() {
    nombreSeccion = "";
    cantidadBoletosDisponibles = 0;
    precioBoleto = 0.0;
    listaBoletosVendidos = ListaLigada();
}

Seccion::~Seccion() {
    // Agregar l�gica de liberaci�n de memoria si es necesario
}

void Seccion::InicializarSeccion(string nombre, int cantidadBoletos,
    double precioBoleto) {
    nombreSeccion = nombre;
    cantidadBoletosDisponibles = cantidadBoletos;
    this->precioBoleto = precioBoleto;
}

void Seccion::ComprarBoletos(int cantidad, string nombreComprador,
    int numTarjeta) {
    if (cantidad > 0 && cantidad <= cantidadBoletosDisponibles) {
        InfoBoleto nuevoBoleto;
        nuevoBoleto.nombreComprador = nombreComprador;
        nuevoBoleto.numTarjeta = numTarjeta;
        nuevoBoleto.cantidadBoletos = cantidad;
        nuevoBoleto.totalCompra = cantidad * precioBoleto;

        // Agregar secci�n
        nuevoBoleto.seccion = nombreSeccion;
        cout << "seccion boleto comprado " << nuevoBoleto.seccion << endl;

        listaBoletosVendidos.InsertarInicio(nuevoBoleto);

        // Actualizar la cantidad de boletos de la seccion disponibles
        cantidadBoletosDisponibles -= cantidad;

        cout << "\n\tCompra realizada con �xito.\n";
        cout << "\tTotal a pagar: $" << nuevoBoleto.totalCompra << "\n";
    }
    else {
        cout << "\n\tNo hay suficientes boletos disponibles.\n";
    }
}

void Seccion::MostrarInformacionDeSeccion() {
    cout << "\t" << nombreSeccion << ":" << endl
        << "\t\tSe compraron en promedio: "
        << listaBoletosVendidos.CalcularPromedioDeBoletosComprados()
        << " boletos por compra" << endl
        << "\t\tPor compra se gast� en promedio: $"
        << listaBoletosVendidos.CalcularPromedioDeCosto() << endl
        << "\t\tSe vendieron: "
        << listaBoletosVendidos.CalcularSumaCantidadDeBoletosComprados()
        << " boletos" << endl;
}

void Seccion::ConsultarInfoBoletos(bool mostrarComoDisponible) {
    cout << "\n"
        << "\tSecci�n: " << nombreSeccion << "\n";
    if (mostrarComoDisponible) {
        cout << "\tBoletos disponibles: " << cantidadBoletosDisponibles << "\n"
            << "\tPrecio por boleto: $" << precioBoleto << "\n";
    }
    else {
        cout << "\tBoletos sobrantes: " << cantidadBoletosDisponibles << "\n";
    }
}

// EVENTO
// ---------------------------------------------------------------------------

Evento::Evento() {}

Evento::~Evento() {
    // Agregar l�gica de liberaci�n de memoria si es necesario
}

void Evento::MostrarVentaBoletos(bool mostrarComoDisponible) {
    seccionGA.ConsultarInfoBoletos(mostrarComoDisponible);
    seccionGB.ConsultarInfoBoletos(mostrarComoDisponible);
    seccionVIP.ConsultarInfoBoletos(mostrarComoDisponible);
}

void Evento::BuscarPorComprador(string nombre) {
    cout << "\nBuscando boletos comprados por: " << nombre << "\n";

    // Secci�n General A
    cout << "Boletos encontrados en General A\n";
    ListaLigada boletosEncontradosGA =
        seccionGA.listaBoletosVendidos.BuscarPorComprador(nombre);
    boletosEncontradosGA.Mostrar(false);
    cout << endl;

    // Secci�n General B
    cout << "Boletos encontrados en General B\n";
    ListaLigada boletosEncontradosGB =
        seccionGB.listaBoletosVendidos.BuscarPorComprador(nombre);
    boletosEncontradosGB.Mostrar(false);
    cout << endl;

    // Secci�n VIP
    cout << "Boletos encontrados en VIP\n";
    ListaLigada boletosEncontradosVIP =
        seccionVIP.listaBoletosVendidos.BuscarPorComprador(nombre);
    boletosEncontradosVIP.Mostrar(false);
}

void Evento::BuscarPorSeccion(string seccion) {
    cout << "\nBuscando boletos en la secci�n: " << seccion << "\n";

    // Determinar la secci�n y obtener la lista de boletos vendidos
    if (seccion == "General A") {
        seccionGA.listaBoletosVendidos.Mostrar(false);
    }
    else if (seccion == "General B") {
        seccionGB.listaBoletosVendidos.Mostrar(false);
    }
    else if (seccion == "VIP") {
        seccionVIP.listaBoletosVendidos.Mostrar(false);
    }
    else {
        cout << "\nSecci�n no v�lida.\n";
    }
}

void Evento::CopiarDatosSeccionesAListaCompleta() {
    /* Extraer compradores de la secci�n e insertarlos a la lista competa */
    seccionGA.listaBoletosVendidos.CopiarDatosASegundaLista(
        listaCompletaDeVentaBoletos);
    seccionGB.listaBoletosVendidos.CopiarDatosASegundaLista(
        listaCompletaDeVentaBoletos);
    seccionVIP.listaBoletosVendidos.CopiarDatosASegundaLista(
        listaCompletaDeVentaBoletos);
}

void Evento::MostrarCompradores() {
    /* Mostrar lista completa */
    cout << "\n-- Lista de compradores completa --\n";
    listaCompletaDeVentaBoletos.Mostrar(true);
}